/******************************************************************************
Link: STONES
Code: STONES
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-13-20.27.29
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

int n,a[2005],dp[2005][2005];
bool isprime(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0)return false;
    }
    return n>1;
}

void fillup(){
    int n=::n*2;
    for(int i=1;i<=n;++i){
        if(isprime(a[i]))dp[i][i]=1;
    }

    for(int len=2;len<=n;++len){
        for(int i=1;i<=n-len+1;++i){
            int j=i+len-1;
            dp[i][j]=max(dp[i][i]-dp[i+1][j],
                         dp[j][j]-dp[i][j-1]);
        }
    }
}

int solve(){
    fillup();
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(dp[i][i]>dp[i+1][i+n-1]){
            ++cnt;
        }
    }
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("STONES.INP","r",stdin);
    freopen("STONES.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
    }

    cout<<solve();
    return 0;
}

/******************************************************************************
Link: DIGITSUM
Code: DIGITSUM
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-09-18.46.55
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

int pow10(int m){
    int ans=1;
    while(m--)ans*=10;
    return ans;
}

void solve(){
    int n;cin>>n;
    int A[n];for(int&k:A)cin>>k;
    sort(A,A+n);
    int i=0,j=0;
    while(i<2){
        if(A[i]==0){
            j=i+1;
            while(A[j]==0&&j<n){
                ++j;
            }
            if(j<n)swap(A[i],A[j]);
//            cout<<i<<' '<<j<<'\n';
        }
        ++i;
    }

    int a=0,b=0;
    for(int i=0;i<n;i+=2){
        a=a*10+A[i];
    }
    for(int i=1;i<n;i+=2){
        b=b*10+A[i];
    }
    cout<<a+b<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DIGITSUM.INP","r",stdin);
    freopen("DIGITSUM.OUT","w",stdout);
    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

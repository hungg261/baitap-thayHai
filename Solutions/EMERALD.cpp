/******************************************************************************
Link: EMERALD
Code: EMERALD
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-11-19.14.37
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int n,a[505],sum=0,res[505],r=0;
bool dp[501][500001];

bool check(){
    if(sum%3!=0)return false;

    int target=sum/3;
    dp[1][0]=dp[1][a[1]]=true;
    for(int i=2;i<=n;++i){
        for(int j=0;j<=sum;++j){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i])dp[i][j]=dp[i][j]|dp[i-1][j-a[i]];
        }
        dp[i][a[i]]=true;
    }

    if(!dp[n][target])return false;

    int left=target;
    for(int i=n;i>=1;--i){
        if(dp[i-1][left])continue;
        if(left>=a[i]&&dp[i][left-a[i]]){
            left-=a[i];
            res[r++]=i;
        }
    }
    reverse(res,res+r);

//    for(int i=1;i<=n;++i){
//        for(int j=0;j<=50;++j)cout<<dp[i][j]<<' ';
//        cout<<'\n';
//    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("EMERALD.INP","r",stdin);
//    freopen("EMERALD.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    bool ans=check();
    if(ans){
        cout<<r<<'\n';
        for(int i=0;i<r;++i)cout<<res[i]<<' ';
    }
    else cout<<0;
    return 0;
}

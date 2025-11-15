/******************************************************************************
Link: GETPASS
Code: GETPASS
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-28-20.13.33
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

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("GETPASS.INP","r",stdin);
    freopen("GETPASS.OUT","w",stdout);
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size(),cnt1[200]={},cnt2[200]={};

    for(int i=1;i<n;++i){
        ++cnt1[s[i]];
    }
    for(int j=0;j<m-1;++j){
        ++cnt2[t[j]];
    }

    int ans=n*m;
    for(int i='a';i<='z';++i){
        ans-=cnt1[i]*cnt2[i];
    }
    cout<<ans;
    return 0;
}

/******************************************************************************
Link: CHECKPAL
Code: CHECKPAL
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-24-10.45.43
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

string s;
int n,A[256]={};

string solve(){
    for(int k:s)++A[k];

    int cnt=0;
    for(int i='a';i<='z';++i)
        cnt+=A[i]%2;
    return cnt<2?"YES":"NO";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CHECKPAL.INP","r",stdin);freopen("CHECKPAL.OUT","w",stdout);
    cin>>s;
    n=s.size();

    cout<<solve();
    return 0;
}

/******************************************************************************
Link: FRACTION
Code: FRACTION
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-14-00.39.42
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

struct fraction{
    int a,b;
};

fraction solve(int node){
    if(node==1)return {1,1};

    auto q=solve(node/2);
    if(node%2==0)return {q.a,q.b+q.a};
    else return {q.a+q.b,q.b};
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FRACTION.INP","r",stdin);
    freopen("FRACTION.OUT","w",stdout);
    int n;cin>>n;

    auto ans=solve(n+1);
    cout<<ans.a<<' '<<ans.b;
    return 0;
}

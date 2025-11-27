/******************************************************************************
Link: MINCOST
Code: MINCOST
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-19-20.42.35
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

const int MAX=1e6+1;
int A[MAX],n;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MINCOST.INP","r",stdin);
    freopen("MINCOST.OUT","w",stdout);
    cin>>n;
    inp(A,n);

    int ans=0;
    for(int i=1;i<n;++i)
        ans+=max(A[i-1],A[i]);

    cout<<ans;
    return 0;
}

/******************************************************************************
Link: BUILDING
Code: BUILDING
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-26-18.46.23
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int A[1001][1001],mark[1001][1001],n,m;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BUILDING.INP","r",stdin);
    freopen("BUILDING.OUT","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>A[i][j];

    int ans=0;
    for(int i=0;i<n;++i){
        int cur=0;
        for(int j=0;j<m;++j){
            if(A[i][j]>=cur)
                mark[i][j]=1,cur=A[i][j];
        }
        cur=0;
        for(int j=m-1;j>=0;--j){
            if(A[i][j]>=cur)
                mark[i][j]=1,cur=A[i][j];
        }
    }
    for(int i=0;i<m;++i){
        int cur=0;
        for(int j=0;j<n;++j){
            if(A[j][i]>=cur)
                mark[j][i]=1,cur=A[j][i];
        }
        cur=0;
        for(int j=n-1;j>=0;--j){
            if(A[j][i]>=cur)
                mark[j][i]=1,cur=A[j][i];
        }
    }

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(!mark[i][j]){
//                cout<<i<<' '<<j<<'\n';
                ++ans;
            }
    cout<<ans;
    return 0;
}

/******************************************************************************
Link: MINSWAP
Code: MINSWAP
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-21-20.27.11
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e5+1;
int A[MAX],mark[MAX],n;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MINSWAP.INP","r",stdin);
    freopen("MINSWAP.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i];
        mark[A[i]]=i;
    }

    int ans=0;
    for(int i=0;i<n;++i){
        if(A[i]!=i+1){
            swap(A[i],A[mark[i+1]]);
            swap(mark[A[i]],mark[A[mark[i+1]]]);
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}

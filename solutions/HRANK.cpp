/******************************************************************************
Link: HRANK
Code: HRANK
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-26-15.28.00
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1001;
int A[MAX],Q[MAX]={1},n,q;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("HRANK.INP","r",stdin);
    freopen("HRANK.OUT","w",stdout);
    cin>>n>>q;
    for(int i=1;i<n;++i){
        cin>>A[i];
        for(int j=0;j<i;++j)
            if(Q[j]>A[i])++Q[j];
        Q[i]=A[i]+1;
    }

    while(q--){
        int t;cin>>t;
        cout<<Q[t-1]<<'\n';
    }
    return 0;
}

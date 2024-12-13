/******************************************************************************
Link: FROGS
Code: FROGS
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-21-19.47.13
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e6+1;
int A[MAX],B[MAX],ans[MAX],S[MAX],k=0,n;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FROGS.INP","r",stdin);
    freopen("FROGS.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)ans[i]=-1;
    inp(A,n);inp(B,n);

    for(int i=n-1;i>=0;--i){
        while(k>0&&A[S[k-1]]<=A[i])--k;
        if(k>=B[i])ans[i]=A[S[k-B[i]]];

        S[k++]=i;
    }
    for(int i=0;i<n;++i)cout<<ans[i]<<' ';
    return 0;
}

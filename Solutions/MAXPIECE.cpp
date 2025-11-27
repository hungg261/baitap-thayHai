/******************************************************************************
Link: MAXPIECE
Code: MAXPIECE
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-28-18.50.31
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int n,m,k,X[100005],Y[100005],x=1,y=1;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MAXPIECE.INP","r",stdin);
    freopen("MAXPIECE.OUT","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=k;++i){
        int t;cin>>t;
        if(t==0){
            cin>>X[x++];
        }
        else cin>>Y[y++];
    }
    X[x++]=n;
    Y[y++]=m;

    sort(X+1,X+x+1);
    sort(Y+1,Y+y+1);
    int mx=-1,my=-1;
    for(int i=1;i<=x;++i){
        mx=max(mx,X[i]-X[i-1]);
    }
    for(int i=1;i<=y;++i){
        my=max(my,Y[i]-Y[i-1]);
    }

    cout<<min(mx,my);
    return 0;
}

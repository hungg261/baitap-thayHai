/******************************************************************************
Link: STAT
Code: STAT
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-30-20.25.19
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e5+5;
int A[MAX],B[MAX],Q[MAX],P[MAX],n;

void nen(int A[]){
    copy(A,A+n,B);
    sort(B,B+n);

    for(int i=0;i<n;++i){
        A[i]=lower_bound(B,B+n,A[i])-B+1;
        ++Q[A[i]];
    }
}

void compute(){
    P[0]=0;
    for(int i=1;i<MAX;++i){
        P[i]=P[i-1]+Q[i];
    }
}

void solve(){
    nen(A);
    compute();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("STAT.INP","r",stdin);
    freopen("STAT.OUT","w",stdout);
    cin>>n;
    inp(A,n);
    solve();

    for(int i=0;i<n;++i){
        cout<<P[A[i]-1]<<' '<<P[MAX-1]-P[A[i]]<<'\n';
    }
    return 0;
}

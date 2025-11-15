/******************************************************************************
Link: ANADEL
Code: ANADEL
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-25-11.24.01
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

string A,B;
int a,b,Q[256]={};
void solve(){
    for(int i=0;i<a;++i)
        ++Q[A[i]];

    int r=0;
    for(int i=0;i<b;++i){
        if(Q[B[i]]>0)++r;
        --Q[B[i]];
    }
    cout<<a+b-2*r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ANADEL.INP","r",stdin);freopen("ANADEL.OUT","w",stdout);
    cin>>A>>B;
    a=A.size(),b=B.size();

    solve();
    return 0;
}

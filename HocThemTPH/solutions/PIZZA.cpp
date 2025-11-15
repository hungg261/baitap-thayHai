/******************************************************************************
Link: PIZZA
Code: PIZZA
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-14-21.39.54
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define double long double
#define int long long
using namespace std;

const int MAX=1e5+1;
struct pizza{
    int cst,sz;
} A[MAX];

bool op(pizza&a,pizza&b){
    int ast=a.cst*b.sz*b.sz,bst=b.cst*a.sz*a.sz;
    if(ast==bst)return a.cst<b.cst;
    return ast<bst;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PIZZA.INP","r",stdin);freopen("PIZZA.OUT","w",stdout);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>A[i].sz>>A[i].cst;
    }
    sort(A,A+n,op);

    int r=0;
    for(int i=0;i<k;++i){
        r+=A[i].cst;
        //cout<<A[i].avg<<' '<<A[i].sz<<' '<<A[i].cst<<endl;
    }
    cout<<r;
    return 0;
}

/******************************************************************************
Link: MAXNUM
Code: MAXNUM
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-14-22.06.14
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

bool op(string&a,string&b){
    return a+b>b+a;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MAXNUM.INP","r",stdin);freopen("MAXNUM.OUT","w",stdout);
    int n;cin>>n;
    string A[n];inp(A,n);
    sort(A,A+n,op);

    for(string s:A)cout<<s;
    return 0;
}

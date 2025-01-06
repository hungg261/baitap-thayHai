/******************************************************************************
Link: FIB1
Code: FIB1
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-26-16.16.45
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int f[46]={1,1};
void compute(){
    for(int i=2;i<=45;++i)
        f[i]=f[i-1]+f[i-2];
}

char solve(int n,int k){
    if(n==0)return 'a';
    if(n==1)return 'b';

    if(k<=f[n-2])
        return solve(n-2,k);
    else return solve(n-1,k-f[n-2]);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FIB1.INP","r",stdin);freopen("FIB1.OUT","w",stdout);
    compute();
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}

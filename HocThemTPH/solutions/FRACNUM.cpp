/******************************************************************************
Link: FRACNUM
Code: FRACNUM
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-14-21.21.04
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

void solve(int n){
    int dcheo=ceil((sqrt(8*n+1)-1)/2.0);
    int tuso;
    if(dcheo%2==0){
        tuso=dcheo*(dcheo+1)/2-n+1;
    }
    else{
        tuso=n-dcheo*(dcheo-1)/2;
    }
    cout<<tuso<<'/'<<dcheo+1-tuso;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FRACNUM.INP","r",stdin);
    freopen("FRACNUM.OUT","w",stdout);
    int n;
    cin>>n;

    solve(n);
    return 0;
}

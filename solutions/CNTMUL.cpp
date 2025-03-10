/******************************************************************************
Link: CNTMUL
Code: CNTMUL
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-13-21.19.51
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
#define watch(x) cerr<<#x<<" = "<<(x)<<'\n';
using namespace std;

int L,H,a,b,lcm;

int solve(int n){
    return n/a+n/b-2*(n/lcm);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CNTMUL.INP","r",stdin);
    freopen("CNTMUL.OUT","w",stdout);
    cin>>L>>H>>a>>b;
    lcm=a/__gcd(a,b)*b;

    cout<<solve(H)-solve(L-1)<<'\n';
    return 0;
}

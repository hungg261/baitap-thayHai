#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(int N,int n){
    int c=0;
    while(N>n){
        N=(N+1)/2;
        c++;
    }
    return c;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FOLDING.INP","r",stdin);freopen("FOLDING.OUT","w",stdout);
    int a,b,w,h;cin>>a>>b>>w>>h;
    int W=max(a,b),H=min(a,b);
    if(max(w,h)>W||min(w,h)>H)cout<<-1;
    else cout<<min(solve(W,w)+solve(H,h),solve(W,h)+solve(H,w));
    return 0;
}

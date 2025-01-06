/******************************************************************************
Link: KDENSITY
Code: KDENSITY
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-16-21.24.56
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

int a,b,k;
int solve(){
    int cubea=ceil(cbrt(a)),cubeb=cbrt(b),
    sqrta=ceil(sqrt(a)-1),sqrtb=sqrt(b),
    cnt=0;

    for(int y=cubea;y<=cubeb;++y)
        cnt+=min(sqrtb,(int)sqrt(y*y*y+k))-max(sqrta,(int)sqrt(max(0LL,y*y*y-k-1)));
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("KDENSITY.INP","r",stdin);
    freopen("KDENSITY.OUT","w",stdout);
    cin>>a>>b>>k;

    cout<<solve();
    return 0;
}

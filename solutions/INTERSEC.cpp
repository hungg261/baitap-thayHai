/******************************************************************************
Link: INTERSEC
Code: INTERSEC
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-23-20.02.53
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define y1 yy1
#define int long long
using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4;
int giaonhau(int a,int b,int c,int d){
    int l1=min(a,b),h1=max(a,b),
        l2=min(c,d),h2=max(c,d);
    return max(0LL,min(h1,h2)-max(l1,l2));
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("INTERSEC.INP","r",stdin);
    freopen("INTERSEC.OUT","w",stdout);
    int t;cin>>t;
    while(t--){
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        cout<<giaonhau(x1,x2,x3,x4)*giaonhau(y1,y2,y3,y4)<<'\n';
    }

    return 0;
}

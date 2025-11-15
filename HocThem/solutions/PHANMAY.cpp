/******************************************************************************
Link: PHANMAY
Code: PHANMAY
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-14-21.51.09
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

const int MAX=2e5+1;
struct ev{
    int time,type;
} A[MAX];

bool op(ev&a,ev&b){
    if(a.time==b.time)return a.type>b.type;
    return a.time<b.time;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PHANMAY.INP","r",stdin);freopen("PHANMAY.OUT","w",stdout);
    int n;cin>>n;
    for(int i=0;i<2*n;++i){
        cin>>A[i].time;
        A[i].type=i%2;
    }
    sort(A,A+2*n,op);

    int r=0,cur=0;
    for(int i=0;i<2*n;++i){
        if(A[i].type)--cur;
        else r=max(r,++cur);
    }
    cout<<r;
    return 0;
}

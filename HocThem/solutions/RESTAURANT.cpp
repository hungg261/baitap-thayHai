/******************************************************************************
Link: RESTAURANT
Code: RESTAURANT
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-23-23.32.11
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=4e5+1;
int n;
struct ev{
    int time,type;
} A[MAX];

bool op(ev&a,ev&b){
    if(a.time==b.time)return a.type>b.type;
    return a.time<b.time;
}

void solve(){
    int cur=0,maxcur=0;
    for(int i=0;i<2*n;++i){
        if(A[i].type==1)--cur;
        else ++cur;
        maxcur=max(maxcur,cur);
    }
    cout<<maxcur;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("RESTAURANT.INP","r",stdin);freopen("RESTAURANT.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<2*n;++i){
        cin>>A[i].time;
        A[i].type=i%2;
    }
    sort(A,A+2*n,op);

    solve();
    return 0;
}

/******************************************************************************
Link: REWARD
Code: REWARD
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-24-10.54.47
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
int n;
struct job{
    int time,deadline;
} A[MAX];

bool op(job&a,job&b){
    return a.time<b.time;
//    if(a.deadline-a.time==b.deadline-b.time)return a.time<b.time;
//    return a.deadline-a.time<b.deadline-b.time;
}

void solve(){
//    for(int i=0;i<n;++i){
//        cout<<A[i].time<<' '<<A[i].deadline<<endl;
//    }
    int t=0,r=0;
    for(int i=0;i<n;++i){
        t+=A[i].time;
        r+=A[i].deadline-t;
    }
    cout<<r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("REWARD.INP","r",stdin);freopen("REWARD.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>A[i].time>>A[i].deadline;
    sort(A,A+n,op);

    solve();
    return 0;
}

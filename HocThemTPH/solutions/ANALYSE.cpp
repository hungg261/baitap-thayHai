/******************************************************************************
Link: ANALYSE
Code: ANALYSE
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-19-21.25.51
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n;
struct state{
    int self[51],len=0;
} base;

void solve(int idx,int sum,state cur){
    if(sum>n)return;
    if(sum==n){
        for(int i=0;i<cur.len;++i){
            cout<<cur.self[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=idx;i<=n;++i){
        cur.self[cur.len++]=i;
        solve(i,sum+i,cur);
        --cur.len;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ANALYSE.INP","r",stdin);
    freopen("ANALYSE.OUT","w",stdout);
    cin>>n;
    solve(1,0,base);

    return 0;
}

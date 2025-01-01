/******************************************************************************
Link: MONITOR
Code: MONITOR
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-21-21.59.17
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
void solve(){
    unordered_map<int,int>Q;
    int res=-1,id=-1;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        if(!Q.count(cur))Q[cur]=i;
        if(Q.count(cur)){
            if(i-Q[cur]+1>res){
                res=i-Q[cur]+1;
                id=cur;
            }
        }
    }
    cout<<id<<'\n'<<res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MONITOR.INP","r",stdin);
    freopen("MONITOR.OUT","w",stdout);
    cin>>n;

    solve();
    return 0;
}

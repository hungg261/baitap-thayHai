// BT_HungPhan_03102025
/******************************************************************************
Link: ROOMSALLOC
Code: ROOMSALLOC
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-28-18.19.33
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5;
int n,res[MAXN+5];
stack<int>available;
multiset<int>occupied;
struct event{
    int time;
    bool type;

    int idx;
} events[MAXN*2+5];

bool cmp(event&u,event&v){
    if(u.time==v.time){
        return u.type==false;
    }
    return u.time<v.time;
}

void solve(){
    int maxrooms=0;
    for(int i=1;i<=n*2;++i){
        if(events[i].type==false){
            int room=available.top();

            res[events[i].idx]=room;
            maxrooms=max(maxrooms,room);

            occupied.insert(room);

            available.pop();
        }
        else{
            occupied.erase(res[events[i].idx]);
            available.push(res[events[i].idx]);
        }
    }

    cout<<maxrooms<<'\n';
    for(int i=1;i<=n;++i){
        cout<<res[i]<<' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ROOMSALLOC.INP","r",stdin);
    freopen("ROOMSALLOC.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>events[i*2-1].time>>events[i*2].time;
        events[i*2-1].type=false;
        events[i*2].type=true;

        events[i*2-1].idx=events[i*2].idx=i;
        available.push(n-i+1);
    }

    sort(events+1,events+n*2+1,cmp);
    solve();
    return 0;
}

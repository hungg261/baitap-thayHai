// BT_HungPhan_03102025
/******************************************************************************
Link: CARDGAME
Code: CARDGAME
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-11-20.36.48
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
int n;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CARDGAME.INP","r",stdin);
    freopen("CARDGAME.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        pq.push({cur,0});
    }

    while(pq.size()>1){
        int a,b,c,d;
        tie(a,b)=pq.top(); pq.pop();
        tie(c,d)=pq.top(); pq.pop();

        pq.push({a+c,max(b+1,d+1)});
    }
    cout<<pq.top().second<<'\n';
    return 0;
}

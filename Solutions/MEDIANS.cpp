// BT_HungPhan_03102025
/******************************************************************************
Link: MEDIANS
Code: MEDIANS
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-19-20.58.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int n,a[MAXN+5];
pair<int,int>mark[MAXN+5];

void solve(){
    priority_queue<int,vector<int>,less<int>>pqmax;
    priority_queue<int,vector<int>,greater<int>>pqmin;

    for(int i=1;i<=n;++i){
        if(pqmax.empty() || a[i]<=pqmax.top()){
            pqmax.push(a[i]);
        }
        else{
            pqmin.push(a[i]);
        }

        if(pqmax.size()>pqmin.size()+1){
            pqmin.push(pqmax.top());
            pqmax.pop();
        }
        else if(pqmin.size()>pqmax.size()){
            pqmax.push(pqmin.top());
            pqmin.pop();
        }

        if(i%2==1){
            cout<<pqmax.top()<<'\n';
        }
        else{
            cout<<pqmax.top()<<' '<<pqmin.top()<<'\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MEDIANS.INP","r",stdin);
    freopen("MEDIANS.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}

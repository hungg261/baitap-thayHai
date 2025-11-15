/******************************************************************************
Link: CLOCKS
Code: CLOCKS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-20.00.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

string operations[9]={
    "ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"
};
bool mark[262145];

struct state{
    int self[9];
    int mov=0;
    string trace="";

    void operate(int op){
        for(char k:operations[op]){
            self[k-'A']=(self[k-'A']+1)%4;
        }
    }

    void re_operate(int op){
        for(char k:operations[op]){
            self[k-'A']=(self[k-'A']-1+4)%4;
        }
    }

    int getid(){
        int id=0;
        for(int i=0;i<9;++i){
            id=id*4+self[i];
        }
        return id;
    }

    bool check(){
        for(int i=0;i<9;++i){
            if(self[i]!=0)return false;
        }
        return true;
    }
} base;

void solve(){
    queue<state>que;
    que.push(base);

    while(!que.empty()){
        state cur=que.front();
        if(cur.check()){
            cout<<cur.mov<<'\n';
            for(int i=0;i<cur.mov;++i){
                cout<<cur.trace[i]<<'\n';
            }
            return;
        }
        que.pop();
        int id=cur.getid();
        if(mark[id])continue;
        mark[id]=true;

        for(int i=0;i<9;++i){
            cur.operate(i);
            cur.trace+=i+1+'0';
            ++cur.mov;

            que.push(cur);

            cur.re_operate(i);
            cur.trace.pop_back();
            --cur.mov;
        }
    }
    cout<<"NO SOLUTION\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CLOCKS.INP","r",stdin);
    freopen("CLOCKS.OUT","w",stdout);
    for(int i=0;i<9;++i)cin>>base.self[i];

    solve();
    return 0;
}

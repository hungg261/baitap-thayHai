/******************************************************************************
Link: LM
Code: LM
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-01-10.17.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int n;
string S;

bool mark[MAXN];
void bfs(){
    queue<pair<int,string>>que;
    for(char digit:S){
        que.push({(digit-'0')%n,string(1,digit)});
    }

    while(!que.empty()){
        int remain;
        string current;

        tie(remain,current)=que.front();
        que.pop();

        if(current=="0"||mark[remain])continue;
        mark[remain]=true;

        if(remain==0){
            cout<<current<<'\n';
            return;
        }

        for(char digit:S){
            que.push({(remain*10+digit-'0')%n,current+digit});
        }
    }
    cout<<"0\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LM.INP","r",stdin);
    freopen("LM.OUT","w",stdout);
    cin>>n>>S;

    bfs();
    return 0;
}

/******************************************************************************
Link: BIRD
Code: BIRD
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-02-19.33.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=1e5;
int m,n;
bool mark[15][MAX+5];
string a[10];

const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
vector<int>trace;
bool dfs(int x,int y){
    if(a[x][y]=='X'||mark[x][y])return false;
    if(y>=n-1)return true;

    mark[x][y]=true;

    if(dfs(max(0,x-1),y+1)){
        trace.push_back(y);
        return true;
    }
    if(dfs(min(m-1,x+1),y+1)){
        return true;
    }
    return false;
}

void output(){
    vector<pair<int,int>>res;

    int sz=trace.size();
    if(sz>0){
        reverse(begin(trace),end(trace));
        int press=trace[0],time=1;
        for(int i=1;i<sz;++i){
            if(trace[i-1]+1==trace[i]){
                ++time;
            }
            else{
                res.push_back({press,time});
                press=trace[i],time=1;
            }
        }
        res.push_back({press,time});
    }

    cout<<res.size()<<'\n';
    for(auto p:res){
        cout<<p.first<<' '<<p.second<<'\n';
    }
}

void solve(){
    dfs(m-1,0);
    output();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BIRD.INP","r",stdin);
    freopen("BIRD.OUT","w",stdout);
    cin>>n;
    m=10;
    for(int i=0;i<m;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}


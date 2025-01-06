/******************************************************************************
Link: LABYRINTH
Code: LABYRINTH
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-02-19.02.47
*******************************************************************************/
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
using namespace std;

const int MAX=1000;
int m,n;
bool mark[MAX][MAX];
string a[MAX];

const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
const char direction[4]={'N','E','S','W'};

string trace;
bool dfs(int x,int y){
    if(mark[x][y])return false;
    mark[x][y]=true;

    if(x==0||x==m-1||y==0||y==n-1)return true;

    for(int dir=0;dir<4;++dir){
        int nx=x+dx[dir],ny=y+dy[dir];
        if(nx>=0&&ny>=0&&nx<m&&ny<n&&a[nx][ny]=='.'&&!mark[nx][ny]){
            if(dfs(nx,ny)){
                trace+=direction[dir];
                return true;
            }
        }
    }
    return false;
}

void solve(){
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(a[i][j]=='*'){
                a[i][j]='.';
                dfs(i,j);

                goto done;
            }
        }
    }
    done:
    reverse(begin(trace),end(trace));
    cout<<trace<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LABYRINTH.INP","r",stdin);
    freopen("LABYRINTH.OUT","w",stdout);
    cin>>m>>n;
    for(int i=0;i<m;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}

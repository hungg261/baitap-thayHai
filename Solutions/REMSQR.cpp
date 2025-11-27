/******************************************************************************
Link: REMSQR
Code: REMSQR
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-03-11.34.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=100;
int m,n;
string a[MAX];
bool mark[MAX][MAX];

const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y){
    if(mark[x][y])return;
    mark[x][y]=true;

    for(int dir=0;dir<4;++dir){
        int nx=x+dx[dir],ny=y+dy[dir];
        if(nx>=0&&ny>=0&&nx<m&&ny<n&&a[nx][ny]=='#'&&!mark[nx][ny]){
            dfs(nx,ny);
        }
    }
}

void solve(){
    int cnt=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(a[i][j]=='#'&&!mark[i][j]){
                ++cnt;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("REMSQR.INP","r",stdin);
    freopen("REMSQR.OUT","w",stdout);
    cin>>m>>n;
    for(int i=0;i<m;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}

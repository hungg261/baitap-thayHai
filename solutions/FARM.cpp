/******************************************************************************
Link: FARM
Code: FARM
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-02-18.52.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=1000;
int m,n;
bool mark[MAX][MAX];
string a[MAX];

const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y,int&fox,int&chicken){
    if(mark[x][y])return;
    mark[x][y]=true;

    if(a[x][y]=='f')++fox;
    else if(a[x][y]=='c')++chicken;

    for(int dir=0;dir<4;++dir){
        int nx=x+dx[dir],ny=y+dy[dir];
        if(nx>=0&&ny>=0&&nx<m&&ny<n&&a[nx][ny]!='#'&&!mark[nx][ny]){
            dfs(nx,ny,fox,chicken);
        }
    }
}

void solve(){
    int total_fox=0,total_chicken=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(a[i][j]!='#'&&!mark[i][j]){
                int fcnt=0,ccnt=0;
                dfs(i,j,fcnt,ccnt);

                if(ccnt>fcnt){
                    total_chicken+=ccnt;
                }
                else total_fox+=fcnt;
            }
        }
    }
    cout<<total_fox<<' '<<total_chicken<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("FARM.INP","r",stdin);
    freopen("FARM.OUT","w",stdout);
    cin>>m>>n;
    for(int i=0;i<m;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}

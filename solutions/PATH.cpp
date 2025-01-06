/******************************************************************************
Link: PATH
Code: PATH
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-01-09.51.32
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
string a[51];
int mark[51][51];
bool roadmark[51][51];

bool bound(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}

const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void mark_dfs(int x,int y,int marker){
    if(mark[x][y]!=0)return;
    mark[x][y]=marker;

    for(int d=0;d<4;++d){
        int nx=x+dx[d],ny=y+dy[d];
        if(bound(nx,ny)&&mark[nx][ny]==0&&a[nx][ny]=='X'){
            mark_dfs(nx,ny,marker);
        }
    }
}

struct state{
    int x,y,move;
};

int bfs(int x,int y){
    queue<state>que;
    que.push({x,y,0});
    while(!que.empty()){
        state cur=que.front();
        que.pop();

        for(int d=0;d<4;++d){
            int nx=cur.x+dx[d],ny=cur.y+dy[d];
            if(bound(nx,ny)&&!roadmark[nx][ny]){
                if(mark[nx][ny]==2){
                    return cur.move;
                }
                else{
                    roadmark[nx][ny]=true;
                    que.push({nx,ny,cur.move+1});
                }
            }
        }
    }
    return -1;
}

void solve(){
    int temp=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mark[i][j]==0&&a[i][j]=='X'){
                mark_dfs(i,j,temp);
                ++temp;
            }
        }
    }

    int res=1e9;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mark[i][j]==1){
                memset(roadmark,0,sizeof(roadmark));
                int ans=bfs(i,j);

                res=min(res,ans);
            }
        }
    }
    cout<<res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PATH.INP","r",stdin);
    freopen("PATH.OUT","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}

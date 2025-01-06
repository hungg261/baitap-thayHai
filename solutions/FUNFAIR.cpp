/******************************************************************************
Link: FUNFAIR
Code: FUNFAIR
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-16-19.21.57
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=205,
dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int dp[MAX][MAX],A[MAX][MAX],n,m;
void compute(){
    for(int i=0;i<n;++i)dp[i][0]=A[i][0];
    for(int i=0;i<MAX;++i){
        for(int j=1;j<MAX;++j){
            dp[i][j]=1e9;
        }
    }
}

void printdp(){
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cout<<dp[i][j]<<"\t\n"[j==m-1];
    cout<<'\n';
}

void bfs(){
    queue<pair<int,int>>que;
    for(int i=0;i<n;++i)que.push({i,0});
    while(!que.empty()){
        auto pos=que.front();
        que.pop();

        for(int d=0;d<4;++d){
            int nx=pos.first+dy[d],ny=pos.second+dx[d];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&dp[nx][ny]>dp[pos.first][pos.second]+A[nx][ny]){
                dp[nx][ny]=dp[pos.first][pos.second]+A[nx][ny];
                que.push({nx,ny});
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FUNFAIR.INP","r",stdin);
    freopen("FUNFAIR.OUT","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>A[i][j];
        }
    }
    compute();

    bfs();

    int ans=dp[0][m-1];
    for(int i=1;i<n;++i)
        ans=min(ans,dp[i][m-1]);

//    printdp();
    cout<<ans;
    return 0;
}

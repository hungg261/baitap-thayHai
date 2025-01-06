/******************************************************************************
Link: TREASURE
Code: TREASURE
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-03-00.42.15
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1000;
int n,k,a[MAX+1][MAX+1],store[1000001],len=0;
bool mark[MAX+1][MAX+1];

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y,int&sum){
    if(mark[x][y])return;
    mark[x][y]=true;

    sum+=a[x][y];

    for(int dir=0;dir<4;++dir){
        int nx=x+dx[dir],ny=y+dy[dir];
        if(nx>=0&&ny>=0&&nx<MAX&&ny<MAX&&a[nx][ny]>0&&!mark[nx][ny]){
            dfs(nx,ny,sum);
        }
    }
}

void solve(){
    for(int i=0;i<MAX;++i){
        for(int j=0;j<MAX;++j){
            if(a[i][j]>0&&!mark[i][j]){
                int sum=0;
                dfs(i,j,sum);

                store[len++]=sum;
            }
        }
    }

    sort(store,store+len,greater<int>());
    cout<<accumulate(store,store+k,0LL)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TREASURE.INP","r",stdin);
    freopen("TREASURE.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        int x,y,p;
        cin>>x>>y>>p;

        a[x-1][y-1]=p;
    }

    solve();
    return 0;
}

/******************************************************************************
Link: MIRROR
Code: MIRROR
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-02-18.48.19
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
#define cerr if(false)cerr
using namespace std;

const int MAX=33;
// mark[x][y]: dem xem o (x,y) giao voi bao nhieu cai guong
int n,mark[MAX+2][MAX+2];
// a[][]: luu trang thai
// visited[][]: danh dau
bool a[MAX+2][MAX+2],visited[MAX+2][MAX+2];

const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y){
    if(visited[x][y])return;
    visited[x][y]=true;

    for(int dir=0;dir<4;++dir){
        int nx=x+dx[dir],ny=y+dy[dir];
        // neu o (nx,ny) hop le va la buc tuong thi o do se phai lap them mot cai guong
        // nghia la o chung canh voi o (nx,ny) la o (x,y) se cong them 1 cai guong nua (++mark[x][y])
        if(nx>=0&&ny>=0&&nx<=n+1&&ny<=n+1&&a[nx][ny]){
            ++mark[x][y];
        }

        // dfs den o trong tiep theo
        if(nx>=1&&ny>=1&&nx<=n&&ny<=n&&!a[nx][ny]&&!visited[nx][ny]){
            dfs(nx,ny);
        }
    }
}

void solve(){
    cerr<<'\n';

    // goi dfs(1,1) vi du khach di tu o (1,1) vao
    dfs(1,1);
    dfs(n,n);
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cerr<<mark[i][j]<<' ';

            // cong cac buc tuong giao voi o (i,j)
            ans+=mark[i][j];
        }
        cerr<<'\n';
    }
    // lay ans*9 vi kich thuoc cua moi o la 3x3
    cout<<ans*9<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MIRROR.INP","r",stdin);
    freopen("MIRROR.OUT","w",stdout);
    cin>>n;
    // dau tien, gan tat ca cac o la buc tuong
    memset(a,1,sizeof(a));

    // input
    for(int i=1;i<=n;++i){
        string line;
        cin>>line;
        for(int j=1;j<=n;++j){
            // a[i][j] = 1 (neu la buc tuong) else 0
            a[i][j]=line[j-1]=='#';
        }
    }
    // cac o o goc ko the la buc tuong
    a[0][0]=a[n+1][n+1]=a[0][1]=a[1][0]=a[n+1][n]=a[n][n+1]=false;

    // debug
    for(int i=0;i<=n+1;++i){
        for(int j=0;j<=n+1;++j){
            cerr<<a[i][j]<<' ';
        }
        cerr<<'\n';
    }

    solve();
    return 0;
}

/******************************************************************************
Link: WINS
Code: WINS
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-09-20.35.33
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1005;
struct rect{
    int x1,y1,x2,y2;
} A[MAX];
int n,q;
bool mark[MAX];

// ktra xem (x,y) co thuoc hinh chu nhat a hay ko
bool check(rect a,int x,int y){
    return a.x1<=x&&x<=a.x2&&a.y1<=y&&y<=a.y2;
}

void solve(int u){
    mark[u]=true;
    ++q;

    for(int i=u+1;i<=n;++i){
        if(!mark[i]&&check(A[i],A[u].x2,A[u].y1)){
            solve(i);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("WINS.INP","r",stdin);
    freopen("WINS.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        A[i]={a,b,c,d};
    }

    solve(1);
    cout<<q<<'\n';
    for(int i=n;i>=1;--i)if(mark[i])cout<<i<<' ';
    return 0;
}


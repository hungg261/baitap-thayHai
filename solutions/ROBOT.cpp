/******************************************************************************
Link: ROBOT
Code: ROBOT
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-24-11.04.44
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

//const int dx={0,1,0,-1},dy={1,0,-1,0};
int n;
int dirfind(int x,int y){
    if(x==0&&y==1)return 0;
    if(x==1&&y==0)return 1;
    if(x==0&&y==-1)return 2;
    if(x==-1&&y==0)return 3;
    return -1;
}

void solve(){
    int px,py,pidx=0,c=0;cin>>px>>py;
    for(int i=1;i<n;++i){
        int x,y;cin>>x>>y;
        int dir=dirfind(x-px,y-py);
        if(i>1&&(dir-pidx+4)%4==1)++c;
        pidx=dir;
        px=x,py=y;
    }
    cout<<c;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ROBOT.INP","r",stdin);freopen("ROBOT.OUT","w",stdout);
    cin>>n;
    solve();

    return 0;
}

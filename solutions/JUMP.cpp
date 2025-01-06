/******************************************************************************
Link: JUMP
Code: JUMP
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-02-23.55.35
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

int n;
int convert(int x,int y){
    int dcheo=x+y-1;

    if(dcheo<=n){
        if(dcheo%2==0)return dcheo*(dcheo+1)/2-y+1;
        else return dcheo*(dcheo+1)/2-x+1;
    }

    dcheo=2*n-dcheo;
    if(dcheo%2==0)return n*n-dcheo*(dcheo-1)/2-(n-x+1)+1;
    else return n*n-dcheo*(dcheo-1)/2-(n-y+1)+1;
}

const int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int dir(char direction){
    if(direction=='U')return 0;
    if(direction=='R')return 1;
    if(direction=='D')return 2;
    return 3;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("JUMP.INP","r",stdin);
    freopen("JUMP.OUT","w",stdout);
    string m="useless",direction;
    cin>>n>>m>>direction;

    int x=1,y=1,ans=1;
    for(char k:direction){
        int direct=dir(k);
        ans+=convert(x+=dy[direct],y+=dx[direct]);
    }
    cout<<ans;
//    for(int i=1;i<=n;++i){
//        for(int j=1;j<=n;++j){
//            cout<<convert(i,j)<<' ';
//        }
//        cout<<'\n';
//    }

    return 0;
}

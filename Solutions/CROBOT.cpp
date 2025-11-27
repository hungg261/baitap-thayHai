#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
using namespace std;

const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int turn(char d){
    if(d=='G')return 0;
    if(d=='R')return 1;
    if(d=='B')return 2;
    if(d=='L')return 3;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CROBOT.INP","r",stdin);freopen("CROBOT.OUT","w",stdout);
    int x=0,y=0,dir=0;
    string n="useless",s;cin>>n>>s;
    for(char d:s){
        dir=(dir+turn(d))%4;
        x+=dx[dir];y+=dy[dir];
        //cout<<dir<<' '<<x<<' '<<y<<endl;
    }
    cout<<x<<' '<<y;
    return 0;
}

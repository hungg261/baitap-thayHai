/******************************************************************************
Link: FITZOOM
Code: FITZOOM
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-07-18.21.40
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

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FITZOOM.INP","r",stdin);
    freopen("FITZOOM.OUT","w",stdout);
    int w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;

    double tile_w=(double)w2/w1,tile_h=(double)h2/h1, tile=min(tile_w,tile_h);
    int new_w=round(w1*tile),new_h=round(h1*tile);
//    int new_w=w1*tile,new_h=h1*tile;

//    cout<<w1*tile<<' '<<h1*tile<<'\n';
    if(new_w==0)new_w=1;
    if(new_h==0)new_h=1;
    cout<<new_w<<' '<<new_h<<'\n';
    return 0;
}

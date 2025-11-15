/******************************************************************************
Link: SURFACE
Code: SURFACE
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-22-11.26.13
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int arr[1005][1005];
void solve(int w,int h){
    int face1=0,face2=0,face3=0;
    for(int i=1;i<=h+1;++i){
        for(int j=1;j<=w+1;++j){
            face1+=abs(arr[i][j]-arr[i][j-1]);
            face2+=abs(arr[i][j]-arr[i-1][j]);
            face3+=arr[i][j]!=0;
        }
    }
    face3*=2;
    int ans=face1+face2+face3;

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("SURFACE.INP","r",stdin);
    freopen("SURFACE.OUT","w",stdout);
    int w,h;
    cin>>h>>w;
    for(int i=1;i<=h;++i){
        for(int j=1;j<=w;++j){
            cin>>arr[i][j];
        }
    }

    solve(w,h);
    return 0;
}

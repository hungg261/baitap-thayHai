/******************************************************************************
Link: WALKING
Code: WALKING
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-08-20.11.39
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
#define watch(x) cerr<<#x<<" = "<<(x)<<'\n';
using namespace std;

int n,m,x,y,ans;
int dir[4];

void xuli(int idx){
    int ans=0;
    int len;
    int cur=dir[idx];
    if(idx<=1){
        len=2*cur+1;
    }
    else{
        len=2*cur+2;
    }

    ans+=len*(len+1);
    if(idx%2==0)ans-=len;

    cout<<ans<<'\n';
}

void solve(){
    y=m-y+1;

    dir[0]=n-x;
    dir[1]=m-y;
    dir[2]=x-1;
    dir[3]=y-1;

    int target=min_element(dir,dir+4)-dir;
    xuli(target);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("WALKING.INP","r",stdin);
    freopen("WALKING.OUT","w",stdout);
    cin>>n>>m>>x>>y;

    solve();
    return 0;
}

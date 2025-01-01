/******************************************************************************
Link: NUMSPIRAL
Code: NUMSPIRAL
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-12.27.19
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(int x,int y){
    int layer=max(x,y);

    int res=0;
    if(x<y){
        if(layer%2==0){
            res=(layer-1)*(layer-1)+1+(x-1);
        }
        else{
            res=layer*layer-(x-1);
        }
    }
    else{
        if(layer%2==1){
            res=(layer-1)*(layer-1)+1+(y-1);
        }
        else{
            res=layer*layer-(y-1);
        }
    }
    return res;
}

void input(){
    int x,y;
    cin>>x>>y;

    cout<<solve(x,y)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("NUMSPIRAL.INP","r",stdin);
    freopen("NUMSPIRAL.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        input();
    }
    return 0;
}

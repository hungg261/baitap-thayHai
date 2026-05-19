// BT_HungPhan_03102025
/******************************************************************************
Link: TQUEEN
Code: TQUEEN
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-28-20.11.44
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;

int occupied(int x,int y){
    int W=(x-1),
        N=(y-1),
        E=(n-x),
        S=(m-y),
        NW=min(x-1,y-1),
        NE=min(y-1,n-x),
        SE=min(n-x,m-y),
        SW=min(m-y,x-1);

    return N+S+E+W+NW+NE+SW+SE;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TQUEEN.INP","r",stdin);
    freopen("TQUEEN.OUT","w",stdout);
    cin>>n>>m;

    int best_x= n%2==0 ? n/2 : (n+1)/2,
        best_y= m%2==0 ? m/2 : (m+1)/2;

    cout<<occupied(best_x,best_y)<<'\n';
    return 0;
}

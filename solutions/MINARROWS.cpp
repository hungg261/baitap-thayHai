/******************************************************************************
Link: MINARROWS
Code: MINARROWS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-24-17.38.44
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXH=1e6,MAXN=1e6;
int mark[MAXH+2],n;
void solve(){
    int res=0;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        if(mark[cur+1]>0){
            --mark[cur+1];
        }
        else{
            ++res;
        }
        ++mark[cur];
    }

    cout<<res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MINARROWS.INP","r",stdin);
    freopen("MINARROWS.OUT","w",stdout);
    cin>>n;
    solve();

    return 0;
}

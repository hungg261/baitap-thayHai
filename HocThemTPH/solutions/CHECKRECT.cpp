/******************************************************************************
Link: CHECKRECT
Code: CHECKRECT
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-13-20.32.54
*******************************************************************************/
#include<bits/stdc++.h>
#define st first
#define nd second
#define int long long
using namespace std;

pair<int,int>a[4];
int pow2(int x){
    return x*x;
}

void solve(){
    vector<int>base={0,1,2,3};
    do{
        if(a[base[0]].st==a[base[1]].st&&a[base[1]].nd==a[base[2]].nd&&a[base[2]].st==a[base[3]].st&&a[base[3]].nd==a[base[0]].nd){
            cout<<pow2(a[base[0]].st-a[base[1]].st)+pow2(a[base[0]].nd-a[base[1]].nd)<<'\n';
            return;
        }
    } while(next_permutation(begin(base),end(base)));

    cout<<"-1\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CHECKRECT.INP","r",stdin);
    freopen("CHECKRECT.OUT","w",stdout);
    for(int i=0;i<4;++i)cin>>a[i].st>>a[i].nd;

    solve();
    return 0;
}

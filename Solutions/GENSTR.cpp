/******************************************************************************
Link: GENSTR
Code: GENSTR
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-09-19.20.47
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

unordered_set<string>mark;
string store[40321];
int len=0;
string s;

void solve(){
    sort(begin(s),end(s));
    do{
        if(!mark.count(s))store[len++]=s;
        mark.insert(s);
    } while(next_permutation(begin(s),end(s)));

    cout<<len<<'\n';
    for(int i=0;i<len;++i){
        cout<<store[i]<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GENSTR.INP","r",stdin);
    freopen("GENSTR.OUT","w",stdout);
    cin>>s;

    solve();
    return 0;
}

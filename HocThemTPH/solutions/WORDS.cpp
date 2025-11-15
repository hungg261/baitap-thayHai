/******************************************************************************
Link: WORDS
Code: WORDS
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-08-21.09.09
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("WORDS.INP","r",stdin);
    freopen("WORDS.OUT","w",stdout);
    string s;
    int words=0,maxlen=0;
    while(cin>>s){
        ++words;
        maxlen=max(maxlen,(int)s.size());
    }

    cout<<words<<' '<<maxlen<<'\n';
    return 0;
}

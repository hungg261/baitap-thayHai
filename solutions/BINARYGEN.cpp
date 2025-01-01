/******************************************************************************
Link: BINARYGEN
Code: BINARYGEN
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-22.01.12
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s;

void solve(int idx){
    if(idx<0){
        cout<<"-1\n";
        return;
    }

    if(s[idx]=='0'){
        s[idx]='1';
        cout<<s<<'\n';
    }
    else{
        s[idx]='0';
        solve(idx-1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BINARYGEN.INP","r",stdin);
    freopen("BINARYGEN.OUT","w",stdout);
    cin>>n>>s;

    solve(n-1);
    return 0;
}

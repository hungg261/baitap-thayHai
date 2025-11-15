/******************************************************************************
Link: MOLECULAR
Code: MOLECULAR
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-13-19.35.39
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int get_weight(char name){
    if(name=='H')return 1;
    if(name=='O')return 16;
    if(name=='N')return 14;
    if(name=='C')return 12;
    return 0;
}

bool isNum(char k){
    return '0'<=k&&k<='9';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MOLECULAR.INP","r",stdin);
    freopen("MOLECULAR.OUT","w",stdout);
    string s;
    cin>>s;
    int n=s.size();

    s+='#';
    int ans=0;
    for(int i=0;i<n;++i){
        if(!isNum(s[i])){
            int cnt=1;
            if(isNum(s[i+1])){
                cnt=s[i+1]-'0';
            }

            ans+=get_weight(s[i])*cnt;
        }
    }
    cout<<ans<<'\n';

    return 0;
}

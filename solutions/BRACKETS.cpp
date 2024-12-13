/******************************************************************************
Link: BRACKETS
Code: BRACKETS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-10-20.41.48
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

string s;
int n;

bool check(int idx,int len){
    stack<char>sta;
    for(int i=idx;i<=idx+len-1;++i){
        if(s[i]==')'){
            if(sta.empty())return false;
            if(sta.top()!='(')return false;
            sta.pop();
        }
        else if(s[i]==']'){
            if(sta.empty())return false;
            if(sta.top()!='[')return false;
            sta.pop();
        }
        else if(s[i]=='}'){
            if(sta.empty())return false;
            if(sta.top()!='{')return false;
            sta.pop();
        }
        else{
            sta.push(s[i]);
        }
    }
    return sta.size()==0;
}

bool solve(){
    if(n==0)return true;

    for(int i=0;i<n;++i){
        if(check(i,n))return true;
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BRACKETS.INP","r",stdin);
    freopen("BRACKETS.OUT","w",stdout);
    cin>>s;
    n=s.size();
    s+=s;

    cout<<(solve()?"Yes\n":"No\n");
    return 0;
}

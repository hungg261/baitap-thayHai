/******************************************************************************
Link: JNUM
Code: JNUM
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-01-09.43.15
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    cout<<"0 ";
    queue<int>que;
    for(int i=1;i<=9;++i)que.push(i);

    while(!que.empty()){
        int cur=que.front();
        que.pop();
        if(cur>n)break;
        cout<<cur<<' ';

        int last_digit=cur%10;
        if(last_digit>0)que.push(cur*10+last_digit-1);
        if(last_digit<9)que.push(cur*10+last_digit+1);
    }
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("JNUM.INP","r",stdin);
    freopen("JNUM.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}

/******************************************************************************
Link: SEQ
Code: SEQ
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-18-20.20.39
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=10000;
int period[MAX+1],len=1,actual,n;
bool mark[MAX+1];

void compute(){
    for(;;){
        period[len]=(period[len-1]*period[len-1])%MAX;

        if(mark[period[len]]){
            actual=find(period,period+len,period[len])-period+1;
            return;
        }
        mark[period[len]]=true;
        ++len;
    }
}

void solve(){
    compute();

    if(n<actual){
        cout<<period[n-1]<<'\n';
    }
    else cout<<period[actual+(n-actual)%(len-actual+1)-1]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
     freopen("SEQ.INP","r",stdin);
     freopen("SEQ.OUT","w",stdout);
    cin>>period[0]>>n;
    mark[period[0]]=true;

    solve();
    return 0;
}

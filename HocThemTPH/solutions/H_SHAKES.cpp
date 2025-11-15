/******************************************************************************
Link: H_SHAKES
Code: H_SHAKES
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-04-09.05.28
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

string s;
void solve(){
    int n=s.size();

    int time=0,total=0,demR=0;
    for(int i=0;i<n;++i){
        if(s[i]=='L'){
            total+=demR;
            if(demR>0)time=max(time+1,demR);
        }
        else ++demR;
    }
    cout<<time<<' '<<total;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   freopen("H_SHAKES.INP","r",stdin);
   freopen("H_SHAKES.OUT","w",stdout);
    cin>>s;

    solve();
    return 0;
}

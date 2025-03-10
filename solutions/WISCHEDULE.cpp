/******************************************************************************
Link: WISCHEDULE
Code: WISCHEDULE
Time (YYYY-MM-DD-hh.mm.ss): 2025-02-05-20.38.00
*******************************************************************************/
#include<bits/stdc++.h>
#define left sussy
using namespace std;

const int MAXN=30000;
int n,left[MAXN+1];
struct event{
    int a,b,c;
} Q[MAXN+1];

bool op(event&u,event&v){
    if(u.b==v.b)return u.a<v.a;
    return u.b<v.b;
}

int dp[MAXN+1];
void solve(){
    dp[0]=0;
    for(int i=1;i<=n;++i){
        int l=1,h=i-1,lowpos=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(Q[mid].b<=Q[i].a){
                lowpos=mid;
                l=mid+1;
            }
            else h=mid-1;
        }

        dp[i]=max(dp[i],left[lowpos]+Q[i].c);
        left[i]=max(left[i-1],dp[i]);
    }

    cout<<*max_element(dp,dp+n+1)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("WISCHEDULE.INP","r",stdin);
    freopen("WISCHEDULE.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>Q[i].a>>Q[i].b>>Q[i].c;
    }
    sort(Q+1,Q+n+1,op);

    solve();
    return 0;
}

/******************************************************************************
Link: FRIDLIST
Code: FRIDLIST
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-06-19.20.56
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int n,m,store[10000],sto=0;
struct user{
    bool fridlist[51]={},waitlist[51]={};
} Q[51];
bool isfull[51]={};

bool checkfull(bool q[]){
    for(int i=1;i<=n;++i){
        if(!q[i])return false;
    }
    return true;
}

void solve(){
    int cnt=0;
    for(int u=1;u<=n;++u){
//        cout<<u<<": \n";
        if(!isfull[u])for(int i=1;i<=n;++i){
            if(u!=i&&Q[u].fridlist[i]){
//                cout<<"\t"<<i<<": \n";
                for(int j=1;j<=n;++j){
                    if(i!=j&&u!=j&&!Q[u].fridlist[j]&&Q[i].fridlist[j]&&!Q[u].waitlist[j]){
//                        cout<<"\t\t"<<j<<' ';
                        ++cnt;
                        Q[u].waitlist[j]=true;
                        Q[j].waitlist[u]=true;
                    }
                }
//                cout<<'\n';
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(Q[i].waitlist[j])Q[i].fridlist[j]=Q[j].fridlist[i]=true;
        }
        if(checkfull(Q[i].fridlist))isfull[i]=true;
        memset(Q[i].waitlist,0,sizeof(Q[i].waitlist));
    }
    store[sto++]=cnt;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FRIDLIST.INP","r",stdin);
    freopen("FRIDLIST.OUT","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)Q[i].fridlist[i]=true;
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        Q[u].fridlist[v]=true;
        Q[v].fridlist[u]=true;
    }

    while(!checkfull(isfull)){
        solve();
    }
    cout<<sto<<'\n';
    for(int i=0;i<sto;++i)cout<<store[i]<<'\n';
    return 0;
}

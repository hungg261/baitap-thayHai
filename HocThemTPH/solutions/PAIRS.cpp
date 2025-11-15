/******************************************************************************
Link: PAIRS
Code: PAIRS
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-09-19.53.28
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

const int MAX=1e6+5;
bool Q[MAX];
int P[78499],p=0,n,k;

void sieve(int n){
    for(int i=2;i*i<=n;++i){
        if(!Q[i]){
            for(int j=i*i;j<=n;j+=i)Q[j]=true;
        }
    }
    for(int i=2;i<=n;++i)if(!Q[i])P[p++]=i;
}

void solve(){
    for(int a=1;a<=n/2;++a){
        int j=lower_bound(P,P+p,2*a)-P,cnt=p-j;
        if(cnt>=k){
            cout<<a<<' '<<P[j+k-1]-a;
            return;
        }
        k-=cnt;

    }
    cout<<-1<<' '<<-1;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PAIRS.INP","r",stdin);
    freopen("PAIRS.OUT","w",stdout);
    cin>>n>>k;
    sieve(n);

    solve();
    return 0;
}

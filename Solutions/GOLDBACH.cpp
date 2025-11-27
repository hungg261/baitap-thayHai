/******************************************************************************
Link: GOLDBACH
Code: GOLDBACH
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-18-21.03.57
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

const int MAX=1000010;
int A[MAX],n,Prime[MAX],p=0;
bool Q[MAX];

void sieve(){
    for(int i=2;i*i<MAX;++i){
        if(!Q[i])for(int j=i*i;j<MAX;j+=i){
            Q[j]=true;
        }
    }
    for(int i=2;i<MAX;++i){
        if(!Q[i])Prime[p++]=i;
    }
}

int solve(){
    int ans=1;
    for(int i=1;i<p;++i){
        int pos=upper_bound(Prime,Prime+p,2*n-Prime[i])-Prime-i;
        if(pos<0)break;
        ans+=pos;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("GOLDBACH.INP","r",stdin);
    freopen("GOLDBACH.OUT","w",stdout);
    sieve();
    while(cin>>n){
//        if(n==-1)break;
        cout<<solve()<<'\n';
    }

    return 0;
}

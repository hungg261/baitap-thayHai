#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

unordered_map<int,int>A;
const int MAX=1e6+5;
int n,k,Q[MAX];

void sieve(){
    for(int i=2;i*i<MAX;++i)
        if(Q[i]==0)for(int j=i*i;j<MAX;j+=i)
            Q[j]=i;
}

void pfactor(int n,unordered_map<int,int>&N){
    while(n>1){
        int p=Q[n];
        if(p==0)p=n;
        while(n%p==0)n/=p,++N[p];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DISTINCT.INP","r",stdin);
    freopen("DISTINCT.OUT","w",stdout);
    cin>>n>>k;
    sieve();
    for(int i=0,q;i<n;++i){
        cin>>q;
        pfactor(q,A);
        if(A.size()==k)cout<<i+1<<' ';
        A.clear();
    }

    return 0;
}

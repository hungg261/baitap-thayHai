#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

unordered_map<int,int>A,B;
const int MAX=1e6+5,MOD=1e9+7;
int n,m,Q[MAX];

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

int power(int a,int b){
    int ans=1;
    while(b>0){
        if(b%2==1)ans=(ans%MOD*a%MOD)%MOD;
        a=(a%MOD*a%MOD)%MOD;
        b/=2;
    }
    return ans%MOD;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("GCDLCM.INP","r",stdin);
//    freopen("GCDLCM.OUT","w",stdout);
    cin>>n>>m;
    sieve();
    for(int i=0,q;i<n;++i){
        cin>>q;
        pfactor(q,A);
    }
    for(int i=0,q;i<m;++i){
        cin>>q;
        pfactor(q,B);
    }

    int gcd=1,lcm=1;
    for(auto p:A){
        if(B.count(p.st))gcd=(gcd%MOD*power(p.st,min(p.nd,B[p.st]))%MOD)%MOD;
        lcm=(lcm%MOD*power(p.st,max(p.nd,B[p.st]))%MOD)%MOD;
    }
    for(auto p:B){
        if(!A.count(p.st))lcm=(lcm%MOD*power(p.st,p.nd)%MOD)%MOD;
    }
    cout<<gcd<<'\n'<<lcm;
    return 0;
}

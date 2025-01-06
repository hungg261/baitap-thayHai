/******************************************************************************
Link: FRACTION
Code: FRACTION
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-04-19.53.57
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

const int MAX=1000005;
int Q[MAX];
unordered_map<int,int>A,B;
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

string getans(){
    for(auto p:B){
        if(p.nd>0&&p.st!=2&&p.st!=5)return "repeating\n";
    }
    return "finite\n";
}

void toi_gian(){
    for(auto p:A)
        if(B.count(p.st))B[p.st]-=min(p.nd,B[p.st]);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FRACTION.INP","r",stdin);
    freopen("FRACTION.OUT","w",stdout);
    sieve();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0,q;i<n;++i){
            cin>>q;
            pfactor(q,A);
        }
        for(int i=0,q;i<n;++i){
            cin>>q;
            pfactor(q,B);
        }
        toi_gian();
        cout<<getans();

        A.clear();
        B.clear();
    }

    return 0;
}

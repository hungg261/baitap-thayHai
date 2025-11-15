#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

int cntdigit(int n){
    return (int)log10(n)+1;
}

int build(int n,int d){
    int q=cntdigit(n),r=(d%q==0&&d/q==2?n:n/10);
    while(n>0){
        r=r*10+n%10;
        n/=10;
    }
    return r;
}

int solve(int n){
    int lt10=1,cdigit=1,fcnt=0,cost;
    while(n>(cost=9*lt10)){
        n-=cost;
        if(++cdigit%2){
            fcnt+=cost;
            if(cdigit>1)lt10*=10;
        }
    }
    return build(fcnt+n,cdigit);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PALINDROME.INP","r",stdin);freopen("PALINDROME.OUT","w",stdout);
    int n;cin>>n;
    cout<<solve(n);

    return 0;
}

#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define int long long
using namespace std;

int solve(int n){
    int cnt=0,a=1,b,c;;
    while(a<=n){
        b=a;
        while(b<=n){
            c=b;
            while(c<=n){
                cnt++;
                c*=5;
            }
            b*=3;
        }
        a*=2;
    }
    return cnt;
}

bool pfactor(int n){
    while(n%2==0)n/=2;
    while(n%3==0)n/=3;
    while(n%5==0)n/=5;
    return n<=1;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("HAMMING.INP","r",stdin);freopen("HAMMING.OUT","w",stdout);
    int t,n;cin>>t;
    while(t--&&cin>>n){
        if(pfactor(n))cout<<solve(n)<<endl;
        else cout<<"Not in sequence\n";
    }
    return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a,int b){
    while(b){
        int r=b;
        b=a%b;
        a=r;
    }
    return a;
}

int gcds(int A[],int n){
    int r=A[0];
    for(int i=1;i<n;i++){
        r=gcd(r,A[i]);
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("NUMQUIZ.INP","r",stdin);freopen("NUMQUIZ.OUT","w",stdout);
    int n;cin>>n;
    int A[n];for(int i=0;i<n;i++)cin>>A[i];
    cout<<gcds(A,n)*n;
    return 0;
}
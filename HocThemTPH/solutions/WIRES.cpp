#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define int long long
using namespace std;

int solve(int mid,int A[],int n){
    int r=0;
    for(int i=0;i<n;i++){
        r+=A[i]/mid;
    }
    return r;
}

int tknp(int A[],int n,int x,int k){
    int l=1,h=x,r=0,s;
    while(l<=h){
        int mid=(l+h)/2;
        s=solve(mid,A,n);
        //cout<<mid<<' '<<solve(mid,A,n)<<endl;
        if(s>=k){
            r=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("WIRES.INP","r",stdin);freopen("WIRES.OUT","w",stdout);
    int n,k;
    while(cin>>n>>k){
        int m=0;
        int A[n];
        for(int&t:A){
            cin>>t;
            m=max(m,t);
        }
        //cout<<endl<<m<<endl;
        cout<<tknp(A,n,m,k)<<endl;
    }
    return 0;
}

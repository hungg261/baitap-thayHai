#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int unsigned long long
using namespace std;

const int MAX=2e5+1;
int n,k,A[MAX];

bool solve(int mid){
    int r=0;
    for(int i=0;i<n;i++){
        r+=mid/A[i];
    }
    return r>=k;
}

int tknp(){
    int l=1,h=4e18,r=1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(solve(mid))
            r=mid,h=mid-1;
        else l=mid+1;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MACHINES.INP","r",stdin);freopen("MACHINES.OUT","w",stdout);
    cin>>n>>k;
    inp(A,n);

    cout<<tknp();
    return 0;
}

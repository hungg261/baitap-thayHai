#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CONTAINER.INP","r",stdin);freopen("CONTAINER.OUT","w",stdout);
    int n;cin>>n;
    int A[n];inp(A,n);

    int i1=0,i2=n-1,cur,maxcur=0;
    while(i1<i2){
        cur=(i2-i1)*min(A[i1],A[i2]);
        maxcur=max(maxcur,cur);

        if(A[i1]<A[i2])++i1;
        else --i2;
    }
    cout<<maxcur;

    return 0;
}

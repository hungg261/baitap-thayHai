#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CLIS.INP","r",stdin);freopen("CLIS.OUT","w",stdout);
    int n;cin>>n;
    int A[2*n];
    for(int i=0;i<n;i++){
        cin>>A[i];
        A[i+n]=A[i];
    }

    int r=0,s=0,r1=0;
    for(int i=0;i<n;i++){
        int j=i;
        while(j<2*n-1&&A[j]<=A[j+1]){
            r++;
            j++;
        }

        if(r==n){
            r1=1,s=n-2;
            break;
        }
        if(r>s)r1=i,s=r,i+=r;
        r=0;
    }
    cout<<r1%n+1<<' '<<(r1+s)%n+1;
    return 0;
}

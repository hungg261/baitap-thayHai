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
    freopen("BIRTHCAKES.INP","r",stdin);freopen("BIRTHCAKES.OUT","w",stdout);
    int n;cin>>n;
    int A[n];inp(A);sort(A,A+n,greater<int>());

    int i1=(n+1)/2,i2=0,c=0;
    while(i1<n&&i2<n){
        if(A[i1]*2<=A[i2]){
            i2++;
            c++;
        }
        i1++;
    }
    cout<<n-c;
    return 0;
}

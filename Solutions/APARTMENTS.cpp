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
    freopen("APARTMENTS.INP","r",stdin);freopen("APARTMENTS.OUT","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    int A[n],B[m];inp(A);inp(B);
    sort(A,A+n);sort(B,B+m);

    int i1=0,i2=0,c=0;
    while(i1<n&&i2<m){
        //cout<<abs(A[i1]-B[i2])<<' '<<k<<endl;
        if(abs(A[i1]-B[i2])<=k){
            c++;
            i1++;
            i2++;
        }
        else if(A[i1]>B[i2]){
            i2++;
        }
        else i1++;
    }
    cout<<c;
    return 0;
}

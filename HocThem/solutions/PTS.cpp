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
    freopen("PTS.INP","r",stdin);freopen("PTS.OUT","w",stdout);
    int n,m;cin>>n>>m;
    int A[n],B[m];inp(A);inp(B);
    sort(A,A+n);sort(B,B+m);

    int i1=0,i2=0,c=0;
    while(i1<n&&i2<m){
        if(A[i1]<B[i2]){
            i1++;
            c+=m-i2;
        }
        else i2++;
    }
    cout<<c;
    return 0;
}

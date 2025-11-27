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
    freopen("PALINSEQ.INP","r",stdin);freopen("PALINSEQ.OUT","w",stdout);
    int n;cin>>n;
    int A[n];inp(A,n);

    int i1=0,i2=n-1,r1=A[i1],r2=A[i2],c=0;
    while(i1<i2){
        if(r1<r2){
            ++i1;
            r1+=A[i1];
            ++c;
        }
        else if(r1>r2){
            --i2;
            r2+=A[i2];
            ++c;
        }
        else{
            ++i1,--i2;
            r1=A[i1],r2=A[i2];
        }
        //cout<<i1<<' '<<i2<<' '<<r1<<' '<<r2<<endl;
    }
    cout<<c;

    return 0;
}

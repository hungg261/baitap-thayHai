#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

const int MAX=2e5+1;
int n,k,A[MAX],ans=INT_MAX,idx=0;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SUMSEQ.INP","r",stdin);freopen("SUMSEQ.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>A[i];
        A[i+n]=A[i];
    }
//    cout<<endl;
//    for(int i=0;i<2*n;++i)cout<<A[i]<<' ';cout<<endl;
    int i1=0,i2=0,s=0,r1=0,ans=1e15;
    while(i1<=i2&&i2<2*n){
        if(s>=k){
            if(s==k){
                ans=min(ans,i2-i1);
                r1=i1%n+1;
            }
            s-=A[i1];
            ++i1;
        }
        else{
            s+=A[i2];
            ++i2;
        }
        //cout<<s<<' '<<k<<' '<<i1<<' '<<i2<<endl;
    }
    if(ans==1e15)cout<<0;
    else cout<<r1<<' '<<ans;
    return 0;
}

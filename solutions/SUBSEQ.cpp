#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

const int MAX=1e6+1;
int n,k,A[MAX],P[MAX];

int solve(){
    int B[n];
    B[0]=A[0];
    int maxx=A[0];
    for(int i=1;i<n;++i){
        maxx=max(A[i],maxx+A[i]);
        B[i]=maxx;
    }
//	for(int i=0;i<n;++i)cout<<B[i]<<' ';cout<<endl;
	//for(int i=0;i<=n;++i)cout<<P[i]<<endl;cout<<endl;

    int cur,maxcur=P[k];
    for(int i=k;i<n;++i){
        cur=P[i+1]-P[i-k+1];
        //cout<<cur<<' '<<maxcur<<' '<<B[i-k]<<endl;
        maxcur=max({maxcur,cur,cur+B[i-k]});
    }
    return maxcur;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SUBSEQ.INP","r",stdin);freopen("SUBSEQ.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>A[i];
        P[i+1]=P[i]+A[i];
    }
    cout<<solve();
    return 0;
}

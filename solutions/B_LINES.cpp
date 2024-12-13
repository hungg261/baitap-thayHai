#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define pii pair<int,int>
#define int long long
using namespace std;

bool op(pii&a,pii&b){
    return a.nd>b.nd;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("B_LINES.INP","r",stdin);freopen("B_LINES.OUT","w",stdout);
    int m,n,k,r=0;cin>>m>>n>>k;
    unordered_map<int,int>A;
    vector<pii>R;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int p;cin>>p;
            A[p]++;
        }
    }
    for(pii k:A)R.pb(k);sort(it(R),op);
    for(int i=0;i<k;i++)r+=R[i].nd;
    cout<<r;
    return 0;
}

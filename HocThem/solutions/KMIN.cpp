#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
using namespace std;

const int MAX=1e7+1;
bool A[MAX]={};
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("KMIN.INP","r",stdin);freopen("KMIN.OUT","w",stdout);
    int n,r=1;cin>>n;

    while(n--){
        int k;cin>>k;
        if(k<MAX)A[k]=1;
        while(A[r])r++;
    }
    cout<<r;

    return 0;
}

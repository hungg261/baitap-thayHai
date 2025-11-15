#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("OLYMP.INP","r",stdin);freopen("OLYMP.OUT","w",stdout);
    int n,c,k,i=0;cin>>n>>c>>k;
    int A[n];
    for(int&q:A){
        int a,b;cin>>a>>b;
        if(a>=k)q=0;
        else{
            if(b)q=(k-a-1)/b+1;
            else q=INT_MAX;
        }
    }
    sort(A,A+n);
    while(i<n){
        c-=A[i];
        //cout<<i<<' '<<c<<' '<<A[i]<<endl;
        if(c<0)break;
        i++;
    }
    cout<<i;

    return 0;
}

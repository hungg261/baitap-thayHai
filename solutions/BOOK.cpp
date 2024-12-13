#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BOOK.INP","r",stdin);freopen("BOOK.OUT","w",stdout);
    int n,s=0;cin>>n;
    int A[n];for(int&k:A){cin>>k;s+=k;};
    sort(A,A+n);
    for(int i=n%3;i<n;i+=3){
        s-=A[i];
    }
    cout<<s;
    return 0;
}

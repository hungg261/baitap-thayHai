#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BONUS.INP","r",stdin);freopen("BONUS.OUT","w",stdout);
    int n,s=0,r=INT_MAX;cin>>n;
    unordered_map<int,int>A;
    for(int i=0;i<n;i++){
        int k;cin>>k;s+=k;
        A[k]+=k;
    }
    for(auto p:A){
        r=min(r,p.nd);
        if(r==1)break;
    }
    cout<<s-r;
    return 0;
}

#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

void solve(int a,int&a1,int&a2){
    if(a<a2)a2=a;
    else if(a>a1)a1=a;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MAHDIST.INP","r",stdin);freopen("MAHDIST.OUT","w",stdout);
    int n,s1,s2,d1,d2;cin>>n;
    int a,b;cin>>a>>b;
    s1=s2=a+b;d1=d2=a-b;
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        int s=x+y,d=x-y;
        solve(s,s1,s2);solve(d,d1,d2);
    }
    cout<<max(s1-s2,d1-d2);
    return 0;
}

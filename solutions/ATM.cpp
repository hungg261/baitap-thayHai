#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(int a,int b,int c,int n){
    if(n%5)return 0;
    int count=0;
    for(int z=0;z<=min(c,n/20);z++){
        for(int y=0;y<=min(b,(n-20*z)/10);y++){
            // 5x+10y+20z=n -> x=(n-10y-20z)/5
            // cout<<x<<' '<<y<<' '<<z<<' '<<(5*x+10*y+20*z==n)<<endl;
            int x=(n-10*y-20*z)/5;
            if(x>=0&&x<=a)count++;
        }
    }
    return count;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ATM.INP","r",stdin);freopen("ATM.OUT","w",stdout);
    int a,b,c,n;cin>>a>>b>>c>>n;
    cout<<solve(a,b,c,n);
    return 0;
}
/******************************************************************************
Link: GCD
Code: GCD
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-20-19.56.49
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=5e5+5,K=19;
int a[MAX],n,table[K][MAX],k;
void compute(){
    for(int i=1;i<=n;++i){
        table[0][i]=a[i];
    }
    for(int i=1;i<=K;++i){
        for(int j=1;j+(1LL<<i)-1<=n;++j){
            table[i][j]=__gcd(table[i-1][j],table[i-1][j+(1LL<<(i-1))]);
        }
    }
}

int gcd(int l,int h){
    int ans=a[l];
    for(int i=K;i>=0;--i){
        if((1LL<<i)<=(h-l+1)){
            ans=__gcd(ans,table[i][l]);
            l+=(1LL<<i);
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("GCD.INP","r",stdin);
    freopen("GCD.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    compute();

    int ans=0;
    for(int i=k;i<=n;++i){
        ans=max(ans,gcd(i-k+1,i));
    }
    cout<<ans;
    return 0;
}

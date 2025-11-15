/******************************************************************************
Link: CDSUBSEG
Code: CDSUBSEG
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-13-18.22.55
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6+5,K=21;
int a[MAX],n,table[K][MAX];
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

int solve(){
    int maxlen=0,l=1,h=1,curgcd=a[1];
    for(;h<=n;++h){
        curgcd=__gcd(curgcd,a[h]);
        while(l<=h&&curgcd==1){
            ++l;
            curgcd=gcd(l,h);
        }
        if(curgcd!=1)maxlen=max(maxlen,h-l+1);
    }
    return maxlen;
}

void query(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]=abs(a[i]);
    }
    compute();

    cout<<solve()<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CDSUBSEG.INP","r",stdin);
    freopen("CDSUBSEG.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        query();
    }
    return 0;
}

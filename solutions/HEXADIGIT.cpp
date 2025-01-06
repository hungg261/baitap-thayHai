/******************************************************************************
Link: HEXADIGIT
Code: HEXADIGIT
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-14-23.30.47
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

int cnt[12]={0};
void compute(){
    for(int i=1;i<=11;++i){
        cnt[i]=15*(1LL<<(4*(i-1)));
    }
}

string to_str(int n){
    string ans="";
    while(n>0){
        int digit=n%16;
        if(digit>9){
            ans+=digit-10+'A';
        }
        else ans+=digit+'0';
        n/=16;
    }
    reverse(begin(ans),end(ans));
    return ans;
}

void solve(){
    int k;cin>>k;

    int chuso=1,boqua=0;
    while(k>chuso*cnt[chuso]){
        k-=chuso*cnt[chuso];
        boqua+=cnt[chuso];
        ++chuso;
    }

    boqua+=(k-1)/chuso+1;
    cout<<to_str(boqua)[(k-1)%chuso]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("HEXADIGIT.INP","r",stdin);
    freopen("HEXADIGIT.OUT","w",stdout);
    compute();

    solve();
    return 0;
}

/******************************************************************************
Link: RELATIVES
Code: RELATIVES
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-25-19.31.26
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

int bitmask[1025],n;
int convert(int n){
    if(n==0)return 1;
    int mask=0;
    while(n>0){
        mask|=(1<<(n%10));
        n/=10;
    }
    return mask;
}

void solve(){
    int ans=0;
    for(int i=0;i<=1023;++i){
        for(int j=i;j<=1023;++j){
            if((i&j)){
                if(i==j){
                    ans+=bitmask[i]*(bitmask[i]-1)/2;
                }
                else ans+=bitmask[i]*bitmask[j];
            }
        }
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("RELATIVES.INP","r",stdin);
    freopen("RELATIVES.OUT","w",stdout);
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        ++bitmask[convert(t)];
    }

    solve();
    return 0;
}

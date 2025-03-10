/******************************************************************************
Link: ENCRYPTION
Code: ENCRYPTION
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-21-20.09.10
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int cnt[19]={0,9,90,900,9000,90000,900000,9000000,90000000LL,900000000LL,9000000000LL,90000000000LL,900000000000LL,9000000000000LL,90000000000000LL,900000000000000LL,9000000000000000LL,90000000000000000LL,900000000000000000LL};
int solve(int k){
    int chuso=1,boqua=0;
    while(k>chuso*cnt[chuso]){
        k-=chuso*cnt[chuso];
        boqua+=cnt[chuso];
        ++chuso;
    }

    boqua+=(k-1)/chuso+1;
    return boqua;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ENCRYPTION.INP","r",stdin);
    freopen("ENCRYPTION.OUT","w",stdout);
    int L,R;
    cin>>L>>R;

    int low=solve(L);
    if(low==solve(L-1))++low;

    int high=solve(R);
    if(high==solve(R+1))--high;

    cout<<max(0LL,high-low+1)<<'\n';
    return 0;
}

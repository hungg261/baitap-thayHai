/******************************************************************************
Link: NUMBERS
Code: NUMBERS
Time (YYYY-MM-DD-hh.mm.ss): 2025-02-12-20.00.25
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXVAL=1e7,MAXDIGIT=1000;
int cnt[MAXDIGIT],sum[MAXDIGIT];

int sum_digit(int n){
    int res=0;
    while(n>0){
        res+=n%10;
        n/=10;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("NUMBERS.INP","r",stdin);
    freopen("NUMBERS.OUT","w",stdout);

//    auto start=chrono::high_resolution_clock::now();
    int n;
    cin>>n;

    int ans=1e18;
    for(int i=1;i<=1000000;++i){
        int dsum=sum_digit(i);

        ++cnt[dsum];
        sum[dsum]+=i;

        if(cnt[dsum]==n){
            ans=min(ans,sum[dsum]);
        }

//        auto stop=chrono::high_resolution_clock::now();
//        if(chrono::duration_cast<chrono::milliseconds>(stop-start).count()>=900){
//            break;
//        }
    }
    cout<<ans<<'\n';
    return 0;
}

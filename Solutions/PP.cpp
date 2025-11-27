/******************************************************************************
Link: PP
Code: PP
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-06-19.10.41
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e6;
int divsum[MAX+5];

void sanguoc(int high){
    for(int i=1;i<=high;++i){
        for(int j=i*2;j<=high;j+=i){
            divsum[j]+=i;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PP.INP","r",stdin);
    freopen("PP.OUT","w",stdout);
    int a,b;
    cin>>a>>b;

    sanguoc(b);
    int ans=0;
    for(int i=a;i<=b;++i){
        if(divsum[i]>i)++ans;
    }

    cout<<ans<<'\n';
    return 0;
}

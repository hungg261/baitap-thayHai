// BT_HungPhan_03102025
/******************************************************************************
Link: READING
Code: READING
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-12-18.51.32
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("READING.INP","r",stdin);
    freopen("READING.OUT","w",stdout);
    int n;
    cin>>n;

    int sum=0;
    int maxval=-1e9;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;

        sum+=cur;
        maxval=max(maxval,cur);
    }

    cout<<max(sum,2*maxval)<<'\n';
    return 0;
}

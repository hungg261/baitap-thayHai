// BT_HungPhan_03102025
/******************************************************************************
Link: PARTITION
Code: PARTITION
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-09-23.51.57
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PARTITION.INP","r",stdin);
    freopen("PARTITION.OUT","w",stdout);
    int L,n;
    cin>>L>>n;

    int total=0;
    priority_queue<int,vector<int>,greater<int>>que;
    for(int i=1;i<=n;++i){
        int cur;
        cin>>cur;
        que.push(cur);

        total+=cur;
    }

    if(total<L){
        que.push(L-total);
    }

    int ans=0;
    while(que.size()>1){
        int sum=que.top();
        que.pop();
        sum+=que.top();
        que.pop();

        ans+=sum;
        que.push(sum);
    }

    cout<<ans<<'\n';
    return 0;
}

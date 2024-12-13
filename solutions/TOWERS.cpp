/******************************************************************************
Link: TOWERS
Code: TOWERS
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-02-18.24.34
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int A[200005];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TOWERS.INP","r",stdin);
    freopen("TOWERS.OUT","w",stdout);
    int n;cin>>n;
    inp(A,n);
    vector<int>Q={A[0]};

    for(int i=1;i<n;++i){
        if(A[i]>=Q.back())Q.push_back(A[i]);
        else Q[lower_bound(it(Q),A[i])-begin(Q)]=A[i];
    }

    cout<<Q.size();
    return 0;
}

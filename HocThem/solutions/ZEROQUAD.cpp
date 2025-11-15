/******************************************************************************
Link: ZEROQUAD
Code: ZEROQUAD
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-02-19.25.48
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=2005;
int A[MAX],Q[5000000],n,OFF=2000001;

int solve(){
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            ++Q[-A[i]-A[j]+OFF];
        }
    }

    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j)--Q[-A[i]-A[j]+OFF];
        for(int j=0;j<i;++j)ans+=Q[A[i]+A[j]+OFF];
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ZEROQUAD.INP","r",stdin);
    freopen("ZEROQUAD.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i];
    }

    cout<<solve();
    return 0;
}

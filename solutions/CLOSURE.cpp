/******************************************************************************
Link: CLOSURE
Code: CLOSURE
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-26-16.21.34
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e5+69;
int freq[MAX],n;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CLOSURE.INP","r",stdin);
    freopen("CLOSURE.OUT","w",stdout);
    cin>>n;

    int ans=0;
    for(int i=1,q;i<=n;++i){
        cin>>q;
        if(freq[q]>0)ans=max(ans,i-freq[q]+1);
        else freq[q]=i;
    }
    cout<<ans;
    return 0;
}

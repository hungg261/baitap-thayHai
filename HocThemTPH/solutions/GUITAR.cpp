/******************************************************************************
Link: GUITAR
Code: GUITAR
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-19-20.29.16
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int n,p;
unordered_map<int,stack<int>>A;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("GUITAR.INP","r",stdin);
    freopen("GUITAR.OUT","w",stdout);
    cin>>n>>p;
    int ans=0;
    while(n--){
        int s,f;cin>>s>>f;
        while(!A[s].empty()&&A[s].top()>f){
            ++ans;
            A[s].pop();
        }
        if(A[s].empty()||A[s].top()<f){
            A[s].push(f);
            ++ans;
        }
    }

    cout<<ans;
    return 0;
}

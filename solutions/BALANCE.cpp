/******************************************************************************
Link: BALANCE
Code: BALANCE
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-30-19.43.36
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int n,x,A[100005],P[100005],x_idx=-1;

void xuli(int idx,unordered_map<int,int>&A,unordered_map<int,int>&B,int&cnt){
    if(idx>=x_idx&&B.count(P[idx]))
        cnt+=B[P[idx]];
    if(idx<x_idx)++A[P[idx]];
}

int solve(){
    unordered_map<int,int>chan,le;
    chan[0]=le[0]=1;
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(i%2==0) xuli(i,le,chan,cnt);
        else xuli(i,chan,le,cnt);
    }
    return cnt;

//    for(int i=1;i<=n;++i){
//        if(i%2==0){
//            if(le.count(P[i])){
//                cnt+=le[P[i]];
//            }
//            ++chan[P[i]];
//        }
//        else{
//            if(chan.count(P[i])){
//                cnt+=chan[P[i]];
//            }
//            ++le[P[i]];
//        }
//    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BALANCE.INP","r",stdin);
    freopen("BALANCE.OUT","w",stdout);
    cin>>n>>x;
    for(int i=0;i<n;++i){
        int q;cin>>q;
        if(q>x)A[i]=1;
        else if(q<x)A[i]=-1;
        else A[i]=0,x_idx=i+1;

        P[i+1]=P[i]+A[i];
    }

    cout<<solve();
    return 0;
}

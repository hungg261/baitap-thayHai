/******************************************************************************
Link: MARIO
Code: MARIO
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-07-18.56.11
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

//////////////////////
#define int unsigned long long
//////////////////////

int n,A[1000005],high=0;
bool check(int mid){
    for(int i=0;i<n;++i){
        if(2*mid<A[i])return false;
        mid=2*mid-A[i];
    }
    return true;
}

int solve_cach1(){
    int l=1,h=high,k=0;
    while(l<=h){
        int mid=l+(h-l)/2;
        // cout<<l<<' '<<h<<' '<<mid<<' '<<check(mid)<<'\n';
        if(check(mid))
            k=mid,
            h=mid-1;
        else l=mid+1;
    }
    return k;
}

long long solve_cach2(){
    long long m=0;
    for(long long i=n-1;i>=0;--i){
        m=ceil((m+A[i])/2.0);
    }
    return m;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     freopen("MARIO.INP","r",stdin);
     freopen("MARIO.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i];
        high=max(high,A[i]);
    }

    cout<<solve_cach2();
    return 0;
}

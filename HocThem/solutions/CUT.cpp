/******************************************************************************
Link: CUT
Code: CUT
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-23-20.40.23
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

int m,n,k;
int solve(int mid){
    int mid1=min(m-1,mid),mid2=min(n-1,k-mid1);
//    cout<<mid1<<' '<<mid2<<'\n';
    return (mid1+1)*(mid2+1);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CUT.INP","r",stdin);
    freopen("CUT.OUT","w",stdout);
    cin>>m>>n>>k;
    if(m>n)swap(m,n);

    if(m+n-2<=k)cout<<m*n;
    else{
        int mid1=k/2,mid2=k-mid1;
        cout<<max(solve(mid1),solve(mid2));
    }
    return 0;
}

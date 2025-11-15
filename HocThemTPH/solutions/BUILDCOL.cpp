/******************************************************************************
Link: BUILDCOL
Code: BUILDCOL
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-26-15.44.55
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

const int MAX=1e5+1;
int A[MAX],B[MAX],E[MAX],n,m,up=0;

bool check(int mid){
    B[0]=max(A[0],mid);
    for(int i=1;i<n;++i){
        B[i]=max({B[i-1],A[i],mid});
    }
    E[n-1]=max(A[n-1],mid);
    for(int i=n-2;i>=0;--i){
        E[i]=max({E[i+1],A[i],mid});
    }

//    for(int i=0;i<n;++i)cout<<B[i]<<' ';cout<<'\n';
//    for(int i=0;i<n;++i)cout<<E[i]<<' ';cout<<'\n';

    int sum=0;
    for(int i=0;i<n;++i){
        sum+=max(0LL,min(B[i],E[i])-max(mid,A[i]));
    }
    return sum>=m;
}

int tknp(){
    int l=1,h=up,k=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
//        cout<<l<<' '<<h<<' '<<k<<' '<<mid<<'\n';
        if(check(mid))k=mid,l=mid+1;
        else h=mid-1;
    }
    return k;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BUILDCOL.INP","r",stdin);
    freopen("BUILDCOL.OUT","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>A[i];
        up=max(up,A[i]);
    }
    cout<<tknp();
    return 0;
}

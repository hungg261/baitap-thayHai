/******************************************************************************
Link: SAW
Code: SAW
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-14-20.40.40
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
int A[MAX],P[MAX],n,k,sum=0;

bool check(int mid,int q){
    int l=0,h=n-1,k=-1;
    while(l<=h){
        int m=(l+h)/2;
        if(A[m]>=mid)k=m,l=m+1;
        else h=m-1;
    }
    ++k;

    return P[k]-k*mid>=q;
}

int tknp(int q){
    int l=0,h=sum,k=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid,q))k=mid,l=mid+1;
        else h=mid-1;
    }
    return k;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SAW.INP","r",stdin);
    freopen("SAW.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>A[i];
        sum+=A[i];
    }
    sort(A,A+n,greater<int>());
    for(int i=0;i<n;++i)P[i+1]=P[i]+A[i];

    while(k--){
        int q;cin>>q;
        cout<<tknp(q)<<' ';
    }
    return 0;
}

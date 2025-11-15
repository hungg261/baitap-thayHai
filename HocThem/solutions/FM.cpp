/******************************************************************************
Link: FM
Code: FM
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-02-18.43.17
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

const int MAX=1e6+1;
int A[MAX],n,k;

int tknp(int pos,int value){
    int l=pos,h=n-1,r=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(value+A[mid]<=k)r=mid,l=mid+1;
        else h=mid-1;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FM.INP","r",stdin);
    freopen("FM.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>A[i];
    sort(A,A+n);

    int ans=0;
    for(int i=0;i<n;++i){
        int pos=tknp(i+1,A[i]);
        if(pos>=0)ans+=pos-i;
    }
    cout<<ans;
    return 0;
}

/******************************************************************************
Link: POWER
Code: POWER
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-24-19.07.30
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int unsigned long long
using namespace std;

int n,k=0;
struct answers{
    int a,b;
} A[10000];

int power(int a,int b){
    int r=1;
    while(b>0){
        if(b%2==1)r*=a;
        a*=a;
        b/=2;
    }
    return r;
}

int solve(int b){
    int l=1,h=ceil(pow(n,1.0/b));
    while(l<=h){
        int mid=(l+h)/2,val=power(mid,b);
        if(val==n)return mid;
        else if(val>n)h=mid-1;
        else l=mid+1;
    }
    return -1;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("POWER.INP","r",stdin);freopen("POWER.OUT","w",stdout);
    cin>>n;
    for(int i=2;i<=60;++i){
        int ans=solve(i);
        if(ans!=-1)A[k].a=ans,A[k++].b=i;
    }

    cout<<k<<'\n';
    for(int i=0;i<k;++i)cout<<A[i].a<<' '<<A[i].b<<'\n';
    return 0;
}

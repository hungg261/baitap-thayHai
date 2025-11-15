/******************************************************************************
Link: NUMORDER
Code: NUMORDER
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-16-18.51.54
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

int n,m,k;
int tknp(int n,int m,int x){
    int cnt=0;
    for(int i=1;i<=n;++i){
        int l=1,h=m;
        while(l<=h){
            int mid=(l+h)/2;
            if(i*i+mid*mid>x)h=mid-1;
            else l=mid+1;
        }
        cnt+=h;
    }
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("NUMORDER.INP","r",stdin);
    freopen("NUMORDER.OUT","w",stdout);
    cin>>n>>m>>k;

    if(n>m)swap(n,m);
    int l=2,h=n*n+m*m,q=h;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(tknp(n,m,mid)>=k){
            q=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    cout<<q;
    return 0;
}

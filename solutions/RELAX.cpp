/******************************************************************************
Link: RELAX
Code: RELAX
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-20-19.43.00
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int a[100005],n,P[100005];
int Try(int l,int h,int turn){
    if(l==h)return turn;
    for(int i=l;i<=h;++i){
        int left=P[i]-P[l-1],right=P[h]-P[i];
        if(left==right){
            return max(Try(l,i,turn+1),Try(i+1,h,turn+1));
        }
    }
    return turn;
}

int solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        P[i]=P[i-1]+a[i];
    }

    if(P[n]%2==0)return Try(1,n,0);
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("RELAX.INP","r",stdin);
    freopen("RELAX.OUT","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }
    return 0;
}

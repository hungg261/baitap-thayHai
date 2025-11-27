/******************************************************************************
Link: KTHSUM
Code: KTHSUM
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-29-19.01.18
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
int A[MAX],n,k;

int solve(int x){
    int cnt=0,j=n-1;
    for(int i=0;i<n&&i<j;++i){
        while(i<j&&A[i]+A[j]>x)
            --j;
        cnt+=j-i;
    }
    return cnt;
}

int tknp(){
    int l=A[0]+A[1],h=A[n-2]+A[n-1],r=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(solve(mid)>=k)
            r=mid,h=mid-1;
        else l=mid+1;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("KTHSUM.INP","r",stdin);freopen("KTHSUM.OUT","w",stdout);
    cin>>n>>k;
    inp(A,n);

    sort(A,A+n);
    cout<<tknp();
    return 0;
}

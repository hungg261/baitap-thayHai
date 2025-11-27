/******************************************************************************
Link: PIGRACE
Code: PIGRACE
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-26-15.52.08
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
int A[MAX],B[MAX],n;
unordered_map<int,int>Q;

int tknp_l(int target){
    int l=0,h=n-1,k=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(B[mid]<target)
            k=mid,l=mid+1;
        else h=mid-1;
    }
    return k+1;
}

void solve(){
    int a=0,b=0;
    for(int i=0;i<n;++i){
        int w=tknp_l(A[i]),d=Q[A[i]],l=n-w-d;
        a+=3*w,a+=d;
        b+=3*l,b+=d;
    }
    cout<<a<<' '<<b;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PIGRACE.INP","r",stdin);freopen("PIGRACE.OUT","w",stdout);
    cin>>n;
    inp(A,n);
    for(int i=0;i<n;++i){
        cin>>B[i];
        ++Q[B[i]];
    }

    sort(A,A+n);sort(B,B+n);
    solve();
    return 0;
}

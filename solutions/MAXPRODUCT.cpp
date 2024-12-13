/******************************************************************************
Link: MAXPRODUCT
Code: MAXPRODUCT
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-23-23.58.39
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

const int MAX=2e5+1;
int n,k;
struct ele{
    int idx,val;
} A[MAX];

bool op(ele&a,ele&b){
    return a.val<b.val;
}

void solve(){
    int i1=0,i2=n-1,r=INT_MIN,r1=0,r2=0;
    while(i1<i2){
        if(A[i1].val>k/A[i2].val){
            --i2;
        }
        else{
            if(A[i1].val*A[i2].val>r){
                r=A[i1].val*A[i2].val;
                r1=A[i1].idx,r2=A[i2].idx;
            }
            ++i1;
        }
        if(r==k)break;
    }
    if(r!=INT_MIN)cout<<r<<'\n'<<r1+1<<' '<<r2+1;
    else cout<<0;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MAXPRODUCT.INP","r",stdin);freopen("MAXPRODUCT.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>A[i].val;
        A[i].idx=i;
    }
    sort(A,A+n,op);

    solve();
    return 0;
}

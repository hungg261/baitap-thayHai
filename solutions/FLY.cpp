/******************************************************************************
Link: FLY
Code: FLY
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-29-18.32.56
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
int n,suma=0;
struct fly{
    int h,a;
} A[MAX];

void solve(){
    int cur=0,mid=(suma+1)/2,h;
    for(int i=0;i<n;++i){
        cur+=A[i].a;
        if(cur>=mid){
            h=A[i].h;
            break;
        }
    }

    int ans=0;
    for(int i=0;i<n;++i){
        ans+=A[i].a*abs(A[i].h-h);
    }
    cout<<h<<' '<<ans;
}

bool op(fly&a,fly&b){
    return a.h<b.h;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FLY.INP","r",stdin);freopen("FLY.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)cin>>A[i].h;
    for(int i=0;i<n;++i){
        cin>>A[i].a;
        suma+=A[i].a;
    }

    sort(A,A+n,op);
    solve();
    return 0;
}

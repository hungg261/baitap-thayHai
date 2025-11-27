/******************************************************************************
Link: CODERS
Code: CODERS
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-06-14.51.07
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

const int MAX=1e5+5;
int A[MAX],L[MAX],n,q,qr=1,l=0;
pair<int,int>Q[MAX];

int i=0,j=1;
void compute(){
    while(i<n&&j<n){
        Q[qr++]={A[i],A[j]};
//        cout<<A[i]<<' '<<A[j]<<'\n';
        L[l++]=min(A[i],A[j]);
        if(A[i]<A[j]){
            if(i<j)i=j,++j;
            else ++i;
        }
        else{
            if(j<i)j=i,++i;
            else ++j;
        }
    }
//    for(int i=0;i<l;++i)cout<<L[i]<<' ';cout<<'\n';
//    cout<<l<<' '<<qr<<'\n';
}

void solve(int k){
    if(k<qr){
        cout<<Q[k].st<<' '<<Q[k].nd<<'\n';
    }
    else{
        cout<<A[i]<<' '<<L[(k-1)%l]<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CODERS.INP","r",stdin);
    freopen("CODERS.OUT","w",stdout);
    cin>>n;
    inp(A,n);
    compute();

    cin>>q;
    while(q--){
        int k;cin>>k;
        solve(k);
    }

    return 0;
}

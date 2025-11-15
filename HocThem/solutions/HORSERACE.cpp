/******************************************************************************
Link: HORSERACE
Code: HORSERACE
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-06-16.01.42
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e5+5;
struct ele{
    int val,pos;
} A[MAX],B[MAX],C[MAX];
int n,c=0;

bool op(ele&a,ele&b){
    return a.val<b.val;
}

void solve(){
    int j=0;
    for(int i=0;i<n;++i){
        for(;j<n&&A[i].val>B[j].val;++j){
            C[c++]=B[j];
        }
        if(c>0){
            cout<<A[i].pos<<' '<<C[c-1].pos<<'\n';
            A[i].val=-1;
            --c;
        }
    }
    for(;j<n;++j)C[c++]=B[j];

    for(int i=0;i<n;++i){
        if(A[i].val!=-1){
            cout<<A[i].pos<<' '<<C[c-1].pos<<'\n';
            --c;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("HORSERACE.INP","r",stdin);
    freopen("HORSERACE.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i].val;
        A[i].pos=i+1;
    }
    for(int i=0;i<n;++i){
        cin>>B[i].val;
        B[i].pos=i+1;
    }
    sort(A,A+n,op);sort(B,B+n,op);

    solve();
    return 0;
}

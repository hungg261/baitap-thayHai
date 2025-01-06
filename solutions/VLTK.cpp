#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define psum(A,n,Pa) for(int i=0;i<n;i++)Pa[i+1]=Pa[i]+A[i].val
#define int long long
using namespace std;

const int MAX=50001;
int Pa[MAX]={},Pb[MAX]={};
struct elm{
    int val,idx;
} A[MAX],B[MAX];

bool op(elm&a,elm&b){
    return a.val>b.val;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("VLTK.INP","r",stdin);freopen("VLTK.OUT","w",stdout);
    int b,k,n,m;cin>>b>>k>>n>>m;
    for(int i=0;i<n;i++){
        elm x;x.idx=i+1;
        cin>>x.val;
        A[i]=x;
    }
    for(int i=0;i<m;i++){
        elm x;x.idx=i+1;
        cin>>x.val;
        B[i]=x;
    }
    sort(it(A),op);sort(it(B),op);
    psum(A,n,Pa);psum(B,m,Pb);

    int rx=0,ry=0;

    int r=0;
    for(int x=0;x<=min(n,k);x++){
        int y=min(k-x,m);
        int p=(b+Pa[x])*(100+Pb[y]);
        if(p>=r){
            rx=x;ry=y;
            r=p;
            //cout<<endl<<i<<' '<<l<<endl;
            //for(int k:R.st)cout<<k<<' ';cout<<endl;
            //for(int k:R.nd)cout<<k<<' ';cout<<endl<<endl;
        }
    }


    //cout<<endl;

    cout<<rx<<' '<<ry<<endl;
    for(int q=0;q<rx;q++)cout<<A[q].idx<<' ';cout<<endl;
    for(int q=0;q<ry;q++)cout<<B[q].idx<<' ';

    //for(int k:A)cout<<k<<' ';cout<<endl;
    //for(int k:B)cout<<k<<' ';cout<<endl;

    //for(int k:Pa)cout<<k<<' ';cout<<endl;
    //for(int k:Pb)cout<<k<<' ';cout<<endl;

    return 0;
}

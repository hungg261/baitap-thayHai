/******************************************************************************
Link: ASUMMIN
Code: ASUMMIN
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-28-19.32.33
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e5+1;
int n,m,A[MAX];
struct ele{
    int idx,val;
} B[MAX];

bool op(ele&a,ele&b){
    return a.val<b.val;
}

int tknp_up(int x){
    int l=0,h=m-1,k=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(B[mid].val>=x)k=mid,h=mid-1;
        else l=mid+1;
    }
    return k;
}

int tknp_low(int x){
    int l=0,h=m-1,k=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(B[mid].val<=x)k=mid,l=mid+1;
        else h=mid-1;
    }
    return k;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ASUMMIN.INP","r",stdin);
    freopen("ASUMMIN.OUT","w",stdout);
    cin>>n>>m;
    inp(A,n);
    for(int i=0;i<m;++i){
        cin>>B[i].val;
        B[i].idx=i;
    }
    sort(B,B+m,op);

    int r1=0,r2=0,s=1e14;
    for(int i=0;i<n;++i){
        int pos,value,pos_up=tknp_up(-A[i]),pos_low=tknp_low(-A[i]),val_up=abs(A[i]+B[pos_up].val),val_low=abs(A[i]+B[pos_low].val);
        if(val_up<val_low)pos=pos_up,value=val_up;
        else pos=pos_low,value=val_low;

        if(value<s)
            r1=i,r2=B[pos].idx,s=value;
        if(s==0)break;
    }
    cout<<r1+1<<' '<<r2+1;


    return 0;
}


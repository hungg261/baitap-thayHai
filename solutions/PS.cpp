/******************************************************************************
Link: PS
Code: PS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-20-00.01.53
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e5;
int a[MAX+1],n,Posmin[MAX+1];
struct prefix{
    int pos=0,value=0;
} P[MAX+1];

bool op(prefix&a,prefix&b){
    if(a.value==b.value){
        return a.pos<b.pos;
    }
    return a.value<b.value;
}

int tknp_low(int idx,int target){
    int l=0,h=idx,res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(P[mid].value<target){
            l=mid+1;
            res=mid;
        }
        else h=mid-1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PS.INP","r",stdin);
    freopen("PS.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        P[i].value=P[i-1].value+a[i];
        P[i].pos=i;
    }

//    for(int i=1;i<=n;++i){
//        cerr<<P[i].value<<' ';
//    }cerr<<"\n\n";

    sort(P,P+n+1,op);

    Posmin[0]=P[0].pos;
    int l=0,r=0;
    for(int i=1;i<=n;++i){
        Posmin[i]=min(Posmin[i-1],P[i].pos);
        int idx=tknp_low(i,P[i].value);
//        cerr<<l<<' '<<r<<' '<<idx<<' '<<Posmin[i]<<' '<<P[i].pos<<' '<<P[i].value<<'\n';
        if(idx==-1)continue;

        if(r-l<P[i].pos-Posmin[idx]){
            l=Posmin[idx],r=P[i].pos;
        }

    }
//    cerr<<'\n';
    cout<<l+1<<' '<<r<<'\n';

    return 0;
}

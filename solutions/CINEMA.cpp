/******************************************************************************
Link: CINEMA
Code: CINEMA
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-12-20.08.49
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
int n,A[MAX],B[MAX],C[MAX],sum=0;
struct pfilm{
    int val,pos;
} Pb[MAX],Pc[MAX];

bool op(pfilm&a,pfilm&b){
    if(a.val==b.val)return a.pos<b.pos;
    return a.val>b.val;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CINEMA.INP","r",stdin);
    freopen("CINEMA.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i]>>B[i]>>C[i];
        sum+=A[i];
    }

    for(int i=0;i<n;++i){
        Pb[i].val=B[i]-A[i];
        Pb[i].pos=i;

        Pc[i].val=C[i]-A[i];
        Pc[i].pos=i;
    }
    sort(Pb,Pb+n,op);
    sort(Pc,Pc+n,op);

    auto curb=Pb[0],curc=Pc[0];
    int cbpos=0,ccpos=0;
    if(curb.pos==Pc[0].pos)curb.val+=Pc[1].val,cbpos=Pc[1].pos;
    else curb.val+=Pc[0].val,cbpos=Pc[0].pos;

    if(curc.pos==Pb[0].pos)curc.val+=Pb[1].val,ccpos=Pb[1].pos;
    else curc.val+=Pb[0].val,ccpos=Pb[0].pos;

//    cout<<curb.pos<<' '<<cbpos<<' '<<curc.pos<<' '<<ccpos<<'\n';
    cout<<max(sum+curb.val,sum+curc.val)<<'\n';
    if(curb.val==curc.val){
        if(curb.pos<ccpos)cout<<curb.pos+1<<' '<<cbpos+1;
        else cout<<ccpos+1<<' '<<curc.pos+1;
    }
    else if(curb.val>curc.val)cout<<curb.pos+1<<' '<<cbpos+1;
    else cout<<ccpos+1<<' '<<curc.pos+1;
    return 0;
}

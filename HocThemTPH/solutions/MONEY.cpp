/******************************************************************************
Link: MONEY
Code: MONEY
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-07-19.38.09
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

struct money{
    int g,s,k;

    void tru(const money&sub){
        g-=sub.g;
        s-=sub.s;
        k-=sub.k;
    }
} total;

int to_knat(int g,int s,int k){
    return g*493+s*29+k;
}

void convert(money total){
    if(total.k<0){
        total.s-=(-total.k-1)/29+1;
        total.k=29+total.k%29;
    }
    if(total.s<0){
        total.g-=(-total.s-1)/17+1;
        total.s=17+total.s%17;
    }

    if(total.g<0)cout<<-1;
    else cout<<total.g<<' '<<total.s<<' '<<total.k;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MONEY.INP","r",stdin);
    freopen("MONEY.OUT","w",stdout);
    cin>>total.g>>total.s>>total.k;
    int t;cin>>t;

    while(t--){
        int p,q,r;
        cin>>p>>q>>r;

        total.tru({p,q,r});
    }

    convert(total);
//    cout<<total.g<<' '<<total.s<<' '<<total.k;
    return 0;
}

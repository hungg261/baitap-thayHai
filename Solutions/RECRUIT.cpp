/******************************************************************************
Link: RECRUIT
Code: RECRUIT
Time (YYYY-MM-DD-hh.mm.ss): 2025-02-10-23.29.26
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;
//
//int ans=1e9,total=0;
//int n,a[10005],c[10005];
//void Try(int idx,int bought,int cost){
//    if(a[idx]==0)return;
//    cout<<idx<<' '<<bought<<' '<<cost<<'\n';
//    if(bought==total){
//        ans=min(ans,cost);
//        return;
//    }
//
//    for(int i=1;i<=n;++i){
//        if(bought>a[i]){
//            int temp=a[i];
//            a[i]=0;
//            Try(i,bought+temp,cost);
//            a[i]=temp;
//        }
//        else{
//            for(int j=1;j<=a[i];++j){
//                a[i]-=j;
//                Try(i,bought+j,cost+c[i]*j);
//                a[i]+=j;
//            }
//        }
//    }
//}

const int MAXN=1000;
int n,prefix=0;
struct city{
    int a,c;
} intel[MAXN+5];

bool op(city&u,city&v){
    if(u.a==v.a)return u.c<v.c;
    return u.a<v.a;
}

void solve(){
    int ans=0,
        bought=0;
    for(int i=n;i>=1;--i){
        prefix-=intel[i].a;
        if(prefix+bought<=intel[i].a){
            ans+=intel[i].c*((intel[i].a-prefix-bought)/2+1);
            bought+=(intel[i].a-prefix-bought)/2+1;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("RECRUIT.INP","r",stdin);
    freopen("RECRUIT.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>intel[i].a>>intel[i].c;
        prefix+=intel[i].a;
    }
    sort(intel+1,intel+n+1,op);

    solve();
    return 0;
}

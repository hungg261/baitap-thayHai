/******************************************************************************
Link: FILMS
Code: FILMS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-21-21.34.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=2e5;
struct film{
    int start,stop;
} a[MAX+1];
int n;

bool op(film&a,film&b){
    return a.stop<b.stop;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("FILMS.INP","r",stdin);
    freopen("FILMS.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].start>>a[i].stop;
    }

    sort(a,a+n,op);
    int prv=-1,
        ans=0;
    for(int i=0;i<n;++i){
        if(a[i].start>=prv){
            ++ans;
            prv=a[i].stop;
        }
    }
    cout<<ans<<'\n';
    return 0;
}

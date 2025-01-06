/******************************************************************************
Link: ELECTRICITY
Code: ELECTRICITY
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-18.53.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n,k,len=0;
struct interval{
    int start,stop;

    void output(){
        cout<<"["<<start<<", "<<stop<<"]"<<'\n';
    }
} val[100005];

bool op(interval&a,interval&b){
    if(a.start==b.start)return a.stop<b.stop;
    return a.start<b.start;
}

void solve(){
    int ans=0,
        covered=0,
        idx=0;
    while(covered<n){
        int farthest=covered;
        bool found=false;
        while(idx<len&&val[idx].start<=covered){
            farthest=max(farthest,val[idx].stop);
            ++idx;
            found=true;
        }
        if(!found){
            cout<<"-1\n";
            return;
        }
        covered=farthest+1;
        ++ans;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ELECTRICITY.INP","r",stdin);
    freopen("ELECTRICITY.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        bool state;
        cin>>state;

        if(state)val[len++]={i-k+1,i+k-1};
    }
    sort(val,val+len,op);

    solve();
    return 0;
}

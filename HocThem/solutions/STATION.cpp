/******************************************************************************
Link: STATION
Code: STATION
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-15.27.12
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n,m,R;
struct interval{
    int start,stop,pos;

    void output(){
        cout<<"["<<start<<", "<<stop<<"]"<<'\n';
    }
} x[1000005];
int res[1000005],len=0;

bool op(interval&a,interval&b){
    if(a.start==b.start)return a.stop<b.stop;
    return a.start<b.start;
}

void solve(){
    int covered=0,
        idx=0;
    while(covered<n){
        int farthest=covered;
        int maxpos=-1;
        while(idx<m&&x[idx].start<=covered){
            if(x[idx].stop>farthest){
                maxpos=idx;
                farthest=max(farthest,x[idx].stop);
            }
            ++idx;
        }

        if(farthest==covered){
            cout<<"0\n";
            return;
        }
        covered=farthest+1;
        res[len++]=maxpos;
    }
    cout<<len<<'\n';
    for(int i=0;i<len;++i){
        cout<<x[res[i]].pos<<' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("STATION.INP","r",stdin);
    freopen("STATION.OUT","w",stdout);
    cin>>n>>m>>R;
    for(int i=0;i<m;++i){
        int point;
        cin>>point;

        x[i]={point-R,point+R,i+1};
    }
    sort(x,x+m,op);

    solve();
    return 0;
}

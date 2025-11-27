/******************************************************************************
Link: COVER
Code: COVER
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-03-18.52.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int n,a,b,len=0;

struct interval{
    int l,r;
    int origin;
} intervals[MAXN+1];

bool cmp(interval&u,interval&v){
    return u.l<v.l;
}

void solve(){
    sort(intervals,intervals+len,cmp);
    vector<int>store;

//    cerr<<'\n';
//    for(int i=0;i<len;++i){
//        cerr<<intervals[i].l<<' '<<intervals[i].r<<'\n';
//    }cerr<<'\n';

    b-=a;
    b*=2;

    int idx=0;
    int covered=-1;
    while(covered<b){
        int farthest=covered;
        int chosen=-1;
        while(idx<len&&intervals[idx].l-1<=covered){
            if(intervals[idx].r>farthest){
                farthest=intervals[idx].r;
                chosen=idx;
            }
            ++idx;
        }

        if(chosen==-1){
            cout<<"-1\n";
            return;
        }

        covered=farthest;
        store.push_back(intervals[chosen].origin);
    }

    cout<<store.size()<<'\n';
    for(int ele:store){
        cout<<ele<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("COVER.INP","r",stdin);
    freopen("COVER.OUT","w",stdout);
    cin>>n>>a>>b;
    for(int i=1;i<=n;++i){
        cin>>intervals[len].l>>intervals[len].r;
        if(intervals[len].r<a)continue;

        intervals[len].l-=a;
        intervals[len].r-=a;

        intervals[len].l*=2;
        intervals[len].r*=2;

        intervals[len].origin=i;

        ++len;
    }

    solve();
    return 0;
}

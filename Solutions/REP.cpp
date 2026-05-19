// BT_HungPhan_09262024
/******************************************************************************
Link: REP
Code: REP
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-05-19.57.10
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAXN=1e5;
int n;
struct interval{
    int L,R;
} intervals[MAXN+1];

bool cmp(interval&u,interval&v){
    return u.R<v.R;
}

void solve(){
    sort(intervals+1,intervals+n+1,cmp);

    int last[3]={(int)-2e6,(int)-2e6,(int)-2e6};
    vector<int>chosen;
    for(int i=1;i<=n;++i){
        int L=intervals[i].L,
            R=intervals[i].R;

        bool in1,in2;
        in1= L<=last[1]&&last[1]<=R;
        in2= L<=last[2]&&last[2]<=R;

        int need=2-(in1+in2);
        if(need==0){
            continue;
        }

        int high=R;
        vector<int>candidates;
        while(need>0&&L<=high){
            if(high!=last[1]&&high!=last[2]){
                candidates.push_back(high);
                --need;
            }
            --high;
        }

        for(int point:candidates){
            chosen.push_back(point);
            last[0]=point;
            sort(last,last+3);
        }
    }

    sort(begin(chosen),end(chosen));
    chosen.resize(unique(begin(chosen),end(chosen))-begin(chosen));

    cout<<(int)chosen.size()<<'\n';
    for(int point:chosen){
        cout<<point<<' ';
    }
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("REP.INP","r",stdin);
    freopen("REP.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>intervals[i].L>>intervals[i].R;
    }

    solve();
    return 0;
}

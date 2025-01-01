/******************************************************************************
Link: OVERLAP
Code: OVERLAP
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-14.11.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct point{
    int a,b,idx;
} value[1005];

struct res{
    int maxres=0,maxpos=0;
} ans;
int n;

namespace custom{
    struct stack{
        int self[1005],len=0;

        bool empty(){
            return len==0;
        }

        void push(int x){
            self[len++]=x;
        }

        void pop(){
            --len;
        }

        void copy_to(custom::stack&target){
            for(int i=0;i<len;++i){
                target.self[i]=self[i];
            }
            target.len=len;
        }

        void output(){
            for(int i=0;i<len;++i){
                cout<<self[i]<<'\n';
            }
        }
    };
}

bool op(point&a,point&b){
    return a.b<b.b;
}

unordered_map<int,pair<int,custom::stack>>dp;
void solve(){
    for(int i=0;i<n;++i){
        int newlen=dp[value[i].a].first+1,
            oldlen=dp[value[i].b].first;

        if(newlen>oldlen){
            dp[value[i].b].first=newlen;
            dp[value[i].a].second.copy_to(dp[value[i].b].second);
            dp[value[i].b].second.push(value[i].idx);

            if(newlen>ans.maxres){
                ans.maxres=newlen;
                ans.maxpos=value[i].b;
            }
        }
        else{
            if(oldlen>ans.maxres){
                ans.maxres=oldlen;
                ans.maxpos=value[i].a;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("OVERLAP.INP","r",stdin);
    freopen("OVERLAP.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>value[i].a>>value[i].b;
        value[i].idx=i+1;
    }
    sort(value,value+n,op);
//    for(int i=0;i<n;++i){
//        cerr<<value[i].a<<' '<<value[i].b<<' '<<value[i].idx<<'\n';
//    }

    solve();
//    cerr<<dp[5].first<<'\n';
//    dp[5].second.output();
//
//    cerr<<ans.maxpos<<' '<<ans.maxres<<'\n';

    int k=dp[ans.maxpos].first;
    cout<<k<<'\n';
    dp[ans.maxpos].second.output();
    return 0;
}

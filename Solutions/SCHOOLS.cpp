// BT_HungPhan_03102025
/******************************************************************************
Link: SCHOOLS
Code: SCHOOLS
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-20-19.27.15
*******************************************************************************/
#include<bits/stdc++.h>
#define left aaasfasofiajsfo
#define right oaisjfoaiss
#define int long long
using namespace std;

const int MAXN=3e5;
int n,m,s;
pair<int,int>a[MAXN+5];

bool cmp(pair<int,int>&u,pair<int,int>&v){
    return u.second-u.first<v.second-v.first;
}

int left[MAXN+5],right[MAXN+5];
priority_queue<int,vector<int>,greater<int>>pq;
void solve(){
    int sum=0;
    for(int i=1;i<=n;++i){
        if(i<=m){
            pq.push(a[i].first);
            sum+=a[i].first;

            if(i==m)left[i]=sum;
        }
        else{
            if(a[i].first>pq.top()){
                sum-=pq.top();
                pq.pop();

                pq.push(a[i].first);
                sum+=a[i].first;
            }

            while(pq.size()>m){
                left[i]-=pq.top();
                pq.pop();
            }
            left[i]=sum;
        }
    }

    sum=0;
    while(!pq.empty())pq.pop();
    for(int i=n;i>=1;--i){
        if(n-i+1<=s){
            pq.push(a[i].second);
            sum+=a[i].second;

            if(n-i+1==s)right[i]=sum;
        }
        else{
            if(a[i].second>pq.top()){
                sum-=pq.top();
                pq.pop();

                pq.push(a[i].second);
                sum+=a[i].second;
            }

            while(pq.size()>s){
                right[i]-=pq.top();
                pq.pop();
            }
            right[i]=sum;
        }
    }

    int ans=0;
    for(int i=0;i<=n;++i){
//        cerr<<left[i]<<' '<<right[i]<<'\n';
        ans=max(ans,left[i]+right[i+1]);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("SCHOOLS.INP","r",stdin);
    freopen("SCHOOLS.OUT","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
    }

    sort(a+1,a+n+1,cmp);
//    cerr<<'\n';for(int i=1;i<=n;++i)cerr<<a[i].first<<' '<<a[i].second<<'\n';cerr<<'\n';

    solve();
    return 0;
}

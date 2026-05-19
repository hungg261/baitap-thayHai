// BT_HungPhan_03102025
/******************************************************************************
Link: GENEMAP
Code: GENEMAP
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-09-21.09.36
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5,MOD=1e9+7;
int n,k;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GENEMAP.INP","r",stdin);
    freopen("GENEMAP.OUT","w",stdout);
    cin>>n>>k;
    string cur;

    int ans=0;
    hash<string>hasher;
    unordered_map<int,pair<unordered_map<int,int>,int>>umap;
    for(int i=1;i<=n;++i){
        cin>>cur;
        int sz=cur.size();
        if(sz<k){
            continue;
        }
        string pre_suf=cur.substr(0,k)+cur.substr(sz-k);
        string checker=cur.size()==k?to_string(i):cur.substr(k,1)+cur.substr(sz-k-1,1);

        int hash_presuf=hasher(pre_suf),
            hash_checker=hasher(checker);

        ans+=umap[hash_presuf].second-umap[hash_presuf].first[hash_checker];
        ++umap[hash_presuf].first[hash_checker];
        ++umap[hash_presuf].second;
    }

    cout<<ans%MOD<<'\n';
    return 0;
}

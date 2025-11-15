/******************************************************************************
Link: LYRICS
Code: LYRICS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-19-20.12.28
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
string store[1001];
int getlast(string&a,string&b){
    int i=a.size()-1,j=b.size()-1,
        ans=0;
    while(i>=0&&j>=0&&a[i]==b[j]){
        ++ans;
        --i,--j;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LYRICS.INP","r",stdin);
    freopen("LYRICS.OUT","w",stdout);
    cin>>n>>m;
    cin.ignore();
    int ans=1e9;
    for(int i=0;i<n;++i){
        getline(cin,store[i]);
    }

    for(int i=m;i<n;++i){
        ans=min(ans,getlast(store[i],store[i-m]));
    }
    cout<<(ans==1e9?0:ans)<<'\n';
    return 0;
}

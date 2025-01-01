#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SUM.INP","r",stdin);freopen("SUM.OUT","w",stdout);
    vector<pair<int,int>>R;
    int n;cin>>n;n*=2;
    for(int i=sqrt(n);i>0;i--){
        if(n%i==0&&(n/i+i)%2)R.push_back({(n/i+1-i)/2,(n/i+i-1)/2});
    }
    cout<<R.size()<<endl;
    for(auto p:R)cout<<p.first<<' '<<p.second<<endl;
    return 0;
}

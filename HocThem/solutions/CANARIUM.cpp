#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CANARIUM.INP","r",stdin);freopen("CANARIUM.OUT","w",stdout);
    int n;
    while(cin>>n){
        // cout<<endl;
        pair<int,int>R={-1,-1};
        for(int x=(sqrt(4*n-1)+1)/2;x>1;x--){
                double y=(2*n+x-1)/(2*x-1.0);
                // cout<<x<<' '<<y<<endl;
                if(y==(int)y){
                    R.first=x-1;
                    R.second=(int)y-1;
                    break;
                }
            }
            cout<<R.first<<' '<<R.second<<endl;
        }
    return 0;
}

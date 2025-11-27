/******************************************************************************
Link: SUMS
Code: SUMS
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-13-20.57.33
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
void solve(){
    for(int i=1;i<=sqrt(2*n);++i){
        if((2*n)%i==0){
            int a=2*n/i,b=i;
            if((a+b-1)%2==0){
                int x=(a-b+1)/2,y=(a+b-1)/2;
                if(x!=y){
                    cout<<n<<" = ";
                    for(int j=x;j<=y;++j){
                        cout<<j;
                        if(j!=y)cout<<" + ";
                    }
                    cout<<'\n';
                    return;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("SUMS.INP","r",stdin);
    freopen("SUMS.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        cin>>n;
        solve();
    }
    return 0;
}

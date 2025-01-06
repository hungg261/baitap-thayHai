/******************************************************************************
Link: LUCKY
Code: LUCKY
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-03-18.11.47
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

int n;
string solve(){
    int sum=0,cur=2,digit=1;
    while(sum+cur<n){
        sum+=cur;
        cur*=2;

        ++digit;
    }

    int target=n-sum-1;
    string ans;
    for(int i=0;i<digit;++i){
        ans+=(target&(1<<i) ?'7':'4');
    }
    reverse(begin(ans),end(ans));
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("LUCKY.INP","r",stdin);
    freopen("LUCKY.OUT","w",stdout);
    cin>>n;

    cout<<solve();
    return 0;
}

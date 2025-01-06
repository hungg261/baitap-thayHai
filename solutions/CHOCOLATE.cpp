/******************************************************************************
Link: CHOCOLATE
Code: CHOCOLATE
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-02-20.07.57
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

int pos[105],k=0;
int n,ans=0;
string s;
int solve(){
    for(int i=0;i<n;++i){
        if(s[i]=='X')pos[k++]=i;
    }
    if(k==0)return 0;

    int ans=1;
    for(int i=1;i<k;++i){
        ans*=pos[i]-pos[i-1];
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CHOCOLATE.INP","r",stdin);
    freopen("CHOCOLATE.OUT","w",stdout);
    cin>>s;
    n=s.size();

    cout<<solve();
    return 0;
}

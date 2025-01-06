/******************************************************************************
Link: STRINGS
Code: STRINGS
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-30-20.45.35
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

string a,b,xoay[101];
int xb=0;
void solve(){
    int n=a.size(),m=b.size();
    for(int l=0;l<m;++l){
        for(int h=l;h<l+m;++h){
            xoay[xb]+=b[h%m];
        }
        ++xb;
    }

    int cnt=0;
    for(int i=0;i+m-1<n;++i){
        for(int j=0;j<xb;++j){
            if(a.substr(i,m)==xoay[j]){
                ++cnt;
                break;
            }
        }
    }
//    for(int i=0;i<xb;++i)cout<<xoay[i]<<'\n';

    cout<<cnt;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("STRINGS.INP","r",stdin);
    freopen("STRINGS.OUT","w",stdout);
    cin>>a>>b;
    solve();

    return 0;
}

/******************************************************************************
Link: REPSTR
Code: REPSTR
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-21-20.51.51
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

int n,q;
string s;
pair<int,int> cnt(){
    int div=0,mod=0;
    for(int i=0;i<q;++i){
        if(s[i]=='a'){
            if(i<n%q)++mod;
            ++div;
        }
    }
    return {div,mod};
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("REPSTR.INP","r",stdin);freopen("REPSTR.OUT","w",stdout);
    cin>>s>>n;
    q=s.size();

    auto p=cnt();
    cout<<n/q*p.st+p.nd;
    return 0;
}

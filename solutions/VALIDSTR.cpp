/******************************************************************************
Link: VALIDSTR
Code: VALIDSTR
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-12-19.28.10
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int A[256],n;
unordered_map<int,int>Q;
string s;

string solve(){
    for(int k:s)++A[k];

    int cnt=0;
    for(int i='a';i<='z';++i)
        if(A[i]!=0)++Q[A[i]];

    if(Q.size()>2)return "NO";
    if(Q.size()<=1)return "YES";

    auto iter=begin(Q);
    int v1=iter->st,c1=iter->nd;
    ++iter;
    int v2=iter->st,c2=iter->nd;

    if(c1==1&&(v1==1||v1-1==v2)||c2==1&&(v2==1||v2-1==v1))return "YES";
    return "NO";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("VALIDSTR.INP","r",stdin);
    freopen("VALIDSTR.OUT","w",stdout);
    cin>>s;
    n=s.size();

    cout<<solve();
    return 0;
}

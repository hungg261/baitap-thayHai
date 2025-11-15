/******************************************************************************
Link: ANAGRAM
Code: ANAGRAM
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-25-09.24.13
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int n;
string s;

int scount(){
    int A[123]={},B[123]={};
    for(int i=0;i<n/2;++i){
        ++A[s[i]];
    }
    for(int i=n/2;i<n;++i){
        ++B[s[i]];
    }

    int r1=0,r2=0;
    for(int i=n/2;i<n;++i){
        if(A[s[i]]<=0)++r1;
        --A[s[i]];
    }
    for(int i=0;i<n/2;++i){
        if(B[s[i]]<=0)++r2;
        --B[s[i]];
    }
    return min(r1,r2);
}

int solve(){
    if(n%2==1)return -1;
    return scount();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ANAGRAM.INP","r",stdin);freopen("ANAGRAM.OUT","w",stdout);
    int t;cin>>t;
    while(t--){
        cin>>s;
        n=s.size();
        cout<<solve()<<endl;
    }

    return 0;
}

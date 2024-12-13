#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
using namespace std;

int solve(unordered_map<char,int>&A,unordered_map<char,int>&B){
    int r=0;
    for(auto k:A){
        r+=min(k.nd,B[k.st]);
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("AD.INP","r",stdin);freopen("AD.OUT","w",stdout);
    unordered_map<char,int>A,B;
    int sa=0,sb=0;
    char q;
    while(cin.get(q)&&q!='\n'){
        A[q]++;
        sa++;
    }
    while(cin.get(q)&&q!='\n'){
        B[q]++;
        sb++;
    }
    cout<<sa+sb-2*solve(A,B)<<endl;

    return 0;
}

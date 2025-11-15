/******************************************************************************
Link: NEXTCODE
Code: NEXTCODE
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-23-20.30.17
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int n,mark[26];
string L,S;
bool op(char&a,char&b){
    return mark[a-'A']<mark[b-'A'];
}

string solve(){
    n=L.size();
    memset(mark,0,sizeof(mark));
    for(int i=0;i<n;++i){
        mark[L[i]-'A']=i;
    }
    next_permutation(begin(S),end(S),op);

    return (S!=L?S:"-1");

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("NEXTCODE.INP","r",stdin);
    freopen("NEXTCODE.OUT","w",stdout);
    while(cin>>L>>S)
        cout<<solve()<<'\n';

    return 0;
}

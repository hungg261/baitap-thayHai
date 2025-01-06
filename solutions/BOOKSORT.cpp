/******************************************************************************
Link: BOOKSORT
Code: BOOKSORT
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-02-19.50.55
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int A[300005];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BOOKSORT.INP","r",stdin);
    freopen("BOOKSORT.OUT","w",stdout);
    int n,cnt=0,cur;cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i];
    }

    cur=n;
    for(int i=n-1;i>=0;--i){
        if(A[i]!=cur)++cnt;
        else --cur;
    }
    cout<<cnt;
    return 0;
}

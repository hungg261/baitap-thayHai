/******************************************************************************
Link: TELEFON
Code: TELEFON
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-19-15.49.50
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=3e5+1;
int n,d,c=0,A[MAX];

void solve(){
    int i1=0,i2=0;
    while(i2<n){
        if(i2-i1>=d&&!A[i2]){
            i1=i2;
            ++c;
        }
        if(A[i2])i1=i2;
        ++i2;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TELEFON.INP","r",stdin);freopen("TELEFON.OUT","w",stdout);
    cin>>n>>d;inp(A,n);

    solve();
    cout<<c;
    return 0;
}

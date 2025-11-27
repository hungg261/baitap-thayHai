/******************************************************************************
Link: GIFTS
Code: GIFTS
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-14-15.07.03
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

const int MAX=5001;
int A[MAX];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("GIFTS.INP","r",stdin);freopen("GIFTS.OUT","w",stdout);
    int k,n=-1,r=0;
    while(cin>>A[++n]);

    sort(A,A+n);
    for(int i=1;i<n-1;++i){
        int i1=0,i2=n-1;
        while(i1<i&&i2>i){
            int q=A[i1]+A[i2];
            if(q>2*A[i]){
                --i2;
            }
            else if(q<2*A[i]) ++i1;
            else{
                ++r;
                break;
            }
        }
    }
    cout<<r;
    return 0;
}

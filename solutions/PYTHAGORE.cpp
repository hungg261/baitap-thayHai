/******************************************************************************
Link: PYTHAGORE
Code: PYTHAGORE
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-23-23.50.15
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=5000;
unordered_map<int,int>A;

void compute(){
    for(int i=1;i<MAX/3;++i){
        for(int j=i+1;j<MAX-i;++j){
            double sq=sqrt(i*i+j*j);
            if(sq==(int)sq)++A[i+j+(int)sq];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PYTHAGORE.INP","r",stdin);freopen("PYTHAGORE.OUT","w",stdout);
    compute();
    int t;cin>>t;

    while(t--){
        int n;cin>>n;
        cout<<A[n]<<endl;
    }
    return 0;
}

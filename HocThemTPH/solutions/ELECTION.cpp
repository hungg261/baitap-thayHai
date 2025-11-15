#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ELECTION.INP","r",stdin);freopen("ELECTION.OUT","w",stdout);
    int n,m;cin>>n>>m;
    int A[n]={};
    for(int i=0;i<m;i++){
        int B[n];int r=0;
        for(int j=0;j<n;j++){
            cin>>B[j];
            r=max(r,B[j]);
        }
        A[find(B,B+n,r)-B]++;
    }
    
    cout<<find(A,A+n,*max_element(A,A+n))-A+1;
    return 0;
}
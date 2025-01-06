#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int solve(int A[4][1001],int n,int L){
    unordered_map<int,int>R;
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            R[A[0][i]+A[1][j]]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c+=R[L-A[2][i]-A[3][j]];
        }
    }
    return c;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TERA.INP","r",stdin);freopen("TERA.OUT","w",stdout);
    int n,L;cin>>n>>L;
    int A[4][1001]={{}};
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++)cin>>A[i][j];
    }
    cout<<solve(A,n,L);
    return 0;
}

/******************************************************************************
Link: BANANAS
Code: BANANAS
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-09-19.17.54
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

void debug(int A[205][205],int f[205][205],int n){
    cout<<'\n';
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            cout<<f[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=1;i<=n-1;++i){
        for(int j=1;j<=n-i;++j){
            cout<<f[n+i][j]<<' ';
        }
        cout<<'\n';
    }

}

int process(int A[205][205],int m,int n){
    int f[205][205];
    f[1][1]=A[1][1];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            f[i][j]=f[i-1][j]+A[i][j];
            if(j>1)f[i][j]=max(f[i][j],f[i-1][j-1]+A[i][j]);
        }
    }
    for(int i=1;i<=n-1;++i){
        for(int j=1;j<=n-i;++j){
            f[n+i][j]=f[n+i-1][j]+A[n+i][j];
            if(j<n-i+1)f[n+i][j]=max(f[n+i][j],f[n+i-1][j+1]+A[n+i][j]);
        }
    }

    return f[m][1];
}

int solve(){
    int n;
    cin>>n;

    int m=2*n-1;
    int A[205][205];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            cin>>A[i][j];
        }
    }
    for(int i=1;i<=n-1;++i){
        for(int j=1;j<=n-i;++j){
            cin>>A[n+i][j];
        }
    }

    return process(A,m,n);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BANANAS.INP","r",stdin);
    freopen("BANANAS.OUT","w",stdout);
    int t;cin>>t;
    while(t--)
        cout<<solve()<<'\n';

    return 0;
}

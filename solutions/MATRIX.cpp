/******************************************************************************
Link: MATRIX
Code: MATRIX
Time (YYYY-MM-DD-hh.mm.ss): 2025-02-05-19.05.25
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=400;
int n,a[MAXN+1][MAXN+1],dcheo[2][MAXN+1][MAXN+1];

void compute(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dcheo[0][i][j]=dcheo[0][i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=n;j>=1;--j){
            dcheo[1][i][j]=dcheo[1][i-1][j+1]+a[i][j];
        }
    }
}

void solve(){
    int ans=-1e9;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=min(i,j)-1;k>=0;--k){
                int A=dcheo[0][i][j]-dcheo[0][i-k-1][j-k-1];
                int B=dcheo[1][i][j-k]-dcheo[1][i-k-1][j+1];

                ans=max(ans,A-B);
            }
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MATRIX.INP","r",stdin);
    freopen("MATRIX.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }

    compute();
    solve();
    return 0;
}

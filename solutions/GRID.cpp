/******************************************************************************
Link: GRID
Code: GRID
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-13-19.55.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=1000;
string A[MAX],B[MAX];
int m,n,p,q;

bool is_identical(string a[],string b[],int i,int j,int p=::p,int q=::q){
    for(int x=0;x<p;++x){
        for(int y=0;y<q;++y){
            if(a[i+x][j+y]!=b[x][y])return false;
        }
    }
    return true;
}

string solve(){
    for(int i=0;i<m-p+1;++i){
        for(int j=0;j<n-q+1;++j){
            if(is_identical(A,B,i,j,p,q))return "YES\n";
        }
    }
    return "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GRID.INP","r",stdin);
    freopen("GRID.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        cin>>m>>n;
        for(int i=0;i<m;++i)cin>>A[i];

        cin>>p>>q;
        for(int i=0;i<p;++i)cin>>B[i];

        cout<<solve();
    }
    return 0;
}

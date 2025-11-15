/******************************************************************************
Link: PERMUTATIONGEN
Code: PERMUTATIONGEN
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-09-19.18.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n,H[10005];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PERMUTATIONGEN.INP","r",stdin);
    freopen("PERMUTATIONGEN.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>H[i];
    }

    if(next_permutation(H,H+n)){
        for(int i=0;i<n;++i){
            cout<<H[i]<<' ';
        }
    }
    else cout<<-1;
    return 0;
}

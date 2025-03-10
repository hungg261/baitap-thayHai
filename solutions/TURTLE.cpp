/******************************************************************************
Link: TURTLE
Code: TURTLE
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-15-20.13.24
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

bool check(int arr[4],int perm[4]){
    return arr[perm[0]]>=arr[perm[2]]&&arr[perm[1]]<=arr[perm[3]];
}

int a[4],perm[4]={0,1,2,3};
void solve(){
    int ans=0;
    do{
        if(check(a,perm)){
            ans=max(ans,min(a[perm[0]],a[perm[2]])*min(a[perm[1]],a[perm[3]]));
        }
    } while(next_permutation(perm,perm+4));

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("TURTLE.INP","r",stdin);
    freopen("TURTLE.OUT","w",stdout);
    cin>>a[0]>>a[1]>>a[2]>>a[3];

    solve();
    return 0;
}

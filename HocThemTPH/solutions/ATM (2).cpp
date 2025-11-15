/******************************************************************************
Link: ATM
Code: ATM
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-21-21.02.53
*******************************************************************************/
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
using namespace std;

long long solve(int a,int b,int c,int d,int n){
    unordered_map<int,int>Q;
    int max_t=min(d,n/50);
    for(int t=0;t<=max_t;++t){
        int left=n-t*50;

        int max_z=min(a,left/5);
        for(int z=0;z<=max_z;++z){
            ++Q[t*50+z*5];
        }
    }

    long long ans=0;
    int max_y=min(c,n/20);
    for(int y=0;y<=max_y;++y){
        int left=n-y*20;

        int max_x=min(b,left/10);
        for(int x=0;x<=max_x;++x){
            ans+=Q[n-y*20-x*10];
        }
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ATM.INP","r",stdin);
    freopen("ATM.OUT","w",stdout);
    int a,b,c,d,n;
    cin>>a>>b>>c>>d>>n;

    cout<<solve(a,b,c,d,n);
    return 0;
}

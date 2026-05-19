// BT_HungPhan_03102025
/******************************************************************************
Link: FESTIVAL
Code: FESTIVAL
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-17-19.38.24
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=40,HALF=(MAXN+1)/2;
int c[MAXN+5],n,M,store[2][(1<<HALF)+5],len[2];

void generate_subset(int space[],int n,int storage[],int&len){
    for(int mask=0;mask<(1<<n);++mask){
        int sum=0;
        for(int i=0;i<n;++i){
            if(mask&(1<<i)){
                sum+=space[i];
            }
        }

        storage[len++]=sum;
    }
}

void solve(){
    int mid=n/2;
    int space1[mid],space2[n-mid];
    for(int i=0;i<mid;++i){
        space1[i]=c[i];
    }
    for(int i=mid;i<n;++i){
        space2[i-mid]=c[i];
    }

    generate_subset(space1,mid,store[0],len[0]);
    generate_subset(space2,n-mid,store[1],len[1]);

    sort(store[1],store[1]+len[1]);
    int ans=0;
    for(int i=0;i<len[0];++i){
        int low=upper_bound(store[1],store[1]+len[1],M-store[0][i])-store[1];

        ans+=low;
    }
    cout<<ans-1<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("FESTIVAL.INP","r",stdin);
    freopen("FESTIVAL.OUT","w",stdout);
    cin>>n>>M;
    for(int i=0;i<n;++i){
        cin>>c[i];
    }

    solve();
    return 0;
}

/******************************************************************************
Link: MAXGCD
Code: MAXGCD
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-13.05.17
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=5e5,MAXVAL=1e6;
int n,a[MAX+1],b[MAX+1],
    mult_a[MAXVAL+1],mult_b[MAXVAL+1],
    maxa,maxb;
bool marka[MAXVAL+1],markb[MAXVAL+1];

void solve(){
    for(int i=1;i<=maxa;++i){
        for(int j=i;j<=maxa;j+=i){
            if(marka[j]){
                mult_a[i]=max(mult_a[i],j);
            }
        }
    }
    for(int i=1;i<=maxb;++i){
        for(int j=i;j<=maxb;j+=i){
            if(markb[j]){
                mult_b[i]=max(mult_b[i],j);
            }
        }
    }

    int maxval=max(maxa,maxb);
    for(int i=maxval;i>=1;--i){
        if(mult_a[i]>0&&mult_b[i]>0){
            cout<<mult_a[i]+mult_b[i]<<'\n';
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MAXGCD.INP","r",stdin);
    freopen("MAXGCD.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        marka[a[i]]=true;
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
        maxb=max(maxb,b[i]);
        markb[b[i]]=true;
    }

    solve();
    return 0;
}

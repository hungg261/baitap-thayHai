// BT_HungPhan_03102025
/******************************************************************************
Link: ANASEQ
Code: ANASEQ
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-28-20.57.39
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e5,MAXVAL=1e5;
int n,m;
int a[MAX+5],b[MAX+5];
int mark_a[MAXVAL+5],mark_b[MAXVAL+5];
int diff=0;

void solve(){
    for(int i=1;i<=n;++i){
        if(mark_a[a[i]]==mark_b[a[i]])++diff;
        ++mark_a[a[i]];
    }

    for(int i=1;i<=m;++i){
        if(i>n){
            --mark_b[b[i-n]];
            if(mark_a[b[i-n]]>0){
                if(mark_b[b[i-n]]==mark_a[b[i-n]])--diff;
                else if(mark_b[b[i-n]]+1==mark_a[b[i-n]])++diff;
            }
        }

        ++mark_b[b[i]];
        if(mark_a[b[i]]>0){
            if(mark_b[b[i]]==mark_a[b[i]])--diff;
            else if(mark_b[b[i]]-1==mark_a[b[i]])++diff;

            if(diff==0){
                cout<<"YES\n"<<i-n+1<<'\n';
                return;
            }
        }
    }

    cout<<"NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ANASEQ.INP","r",stdin);
    freopen("ANASEQ.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>b[i];
    }

    solve();
    return 0;
}

// BT_HungPhan_03102025
/******************************************************************************
Link: ORDER
Code: ORDER
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-28-19.29.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
int n,m;
int a[MAXN+5];
bool ordered[MAXN+5];
int changes_left=0;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ORDER.INP","r",stdin);
    freopen("ORDER.OUT","w",stdout);
    cin>>n>>m;
    a[0]=-1;
    a[n+1]=1e9+1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        ordered[i]=a[i-1]<=a[i];
        if(!ordered[i])++changes_left;
    }
    ordered[n+1]=true;

    while(m--){
        char type;
        cin>>type;

        if(type=='?'){
            cout<<(changes_left==0?"YES\n":"NO\n");
        }
        else{
            int k,x;
            cin>>k>>x;

            int before=ordered[k]+ordered[k+1];
            a[k]=x;
            ordered[k]=a[k-1]<=a[k];
            ordered[k+1]=a[k]<=a[k+1];

            int after=ordered[k]+ordered[k+1];
            changes_left=changes_left-(after-before);
        }
    }
    return 0;
}

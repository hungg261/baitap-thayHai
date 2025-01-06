/******************************************************************************
Link: EXCURS
Code: EXCURS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-19.47.30
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=1e5;
int n,k,a[MAX+1];
unordered_map<int,int>mark;

struct res{
    int pos=0,value=0;
} ans;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("EXCURS.INP","r",stdin);
    freopen("EXCURS.OUT","w",stdout);
    cin>>n>>k;
    int cur=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];

        if(mark[a[i]]==0)++cur;
        ++mark[a[i]];

        if(i>=k){
            --mark[a[i-k]];
            if(mark[a[i-k]]==0)--cur;

            if(ans.value<cur){
                ans.value=cur;
                ans.pos=i-k+1;
            }
        }

    }
    cout<<ans.pos<<'\n';

    return 0;
}

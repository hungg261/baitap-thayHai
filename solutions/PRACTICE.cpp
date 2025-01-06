/******************************************************************************
Link: PRACTICE
Code: PRACTICE
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-19-20.47.34
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int tknp_high(int target){
    int l=1,h=n,res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(n/mid>=target){
            l=mid+1;
            res=mid;
        }
        else h=mid-1;
    }
    return res;
}

int tknp_low(int target){
    int l=1,h=n,res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(n/mid<=target){
            h=mid-1;
            res=mid;
        }
        else l=mid+1;
    }
    return res;
}

void solve(){
    int ans=0,high=tknp_high(1);
    for(int i=1;i<=n;++i){
        int low=tknp_low(i);
        ans+=i*(high-low+1);

        if(low==1)break;
        high=low-1;
        i=n/high-1;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PRACTICE.INP","r",stdin);
    freopen("PRACTICE.OUT","w",stdout);
    cin>>n;

    solve();
    return 0;
}

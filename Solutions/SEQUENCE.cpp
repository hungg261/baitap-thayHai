// BT_HungPhan_03102025
/******************************************************************************
Link: SEQUENCE
Code: SEQUENCE
Time (YYYY-MM-DD-hh.mm.ss): 2025-03-17-20.24.50
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int tknp(int target){
    int l=1,h=1414214,res=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(mid*(mid+1)/2>=target){
            res=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return res;
}

void solve(int n){
    int range=tknp(n);

    int last=0;
    for(int i=1;i<range;++i){
        int start=(last/i+1)*i;
        last=start+i*(i-1);
    }

    int start=(last/range+1)*range;
    int idx=n-range*(range-1)/2;

    int ans=start+range*(idx-1);
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    int n;
    cin>>n;

    solve(n);
    return 0;
}

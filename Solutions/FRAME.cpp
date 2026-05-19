// BT_HungPhan_03102025
/******************************************************************************
Link: FRAME
Code: FRAME
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-05-20.29.27
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

int solve(int nua_chu_vi){
    int ans=-1;
    for(int delta = -1; delta <= 0; ++delta){
        int n=::n, m=::m;
        int a = nua_chu_vi/2 + delta,
            b = nua_chu_vi - a;

        int used2 = (a/2 + b/2)*2,
            used1 = (a%2 + b%2)*2;

        if(used2>m){
            used1 += (used2 - m)*2;
            used2 = m;
        }

        n -= used1;
        m -= used2;

        if(n>=0&&m>=0){
            ans=max(ans,a*b);
        }
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("FRAME.INP","r",stdin);
    freopen("FRAME.OUT","w",stdout);
    cin >> n >> m;

    int chu_vi = n + 2*m;
    int nua_chu_vi = chu_vi/2;

    if(nua_chu_vi < 2){
        cout << "0\n";
        return 0;
    }

    cout << max(solve(nua_chu_vi), solve(nua_chu_vi-1)) << '\n';
    return 0;
}

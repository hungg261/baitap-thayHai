// BT_HungPhan_05282025
/******************************************************************************
Link: ROOKS
Code: ROOKS
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-28-18.44.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void Possible(int n, int m, int k){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(j == i){
                if(k > 0){
                    cout << "*";
                    --k;
                }
            }
            else cout << ".";
        }

        cout << '\n';
    }
}

void solve(int n, int m, int k){
    if(min(n, m) >= k){
        cout << "Possible\n";
        Possible(n, m, k);
    }
    else{
        cout << "Impossible\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ROOKS.INP","r",stdin);
    freopen("ROOKS.OUT","w",stdout);
    int n, m, k;
    cin >> n >> m >> k;

    solve(n, m, k);
    return 0;
}

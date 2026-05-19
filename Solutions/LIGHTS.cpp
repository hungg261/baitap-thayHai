// BT_HungPhan_03102025
/******************************************************************************
Link: LIGHTS
Code: LIGHTS
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-19-19.33.18
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int LIMIT = 1e18;
const int MAXN = 35;
const int MAX_SUBSET_SIZE = 1LL << ((MAXN + 1) / 2);

unordered_map<int,int> storeMinA;
unordered_map<int,int> storeMinB;

vector<int> children[MAXN + 5];
int n, a[MAXN + 5];

void generate_subset(int n, int space[], unordered_map<int,int>& storeMin, bool is_switch){
    for(int mask = 0; mask < (1LL << n); ++mask){
        int xor_result = 0;
        int chosen = 0; // so bit 1

        for(int i = 0; i < n; ++i){
            if(mask & (1LL << i)){
                int current_xor = 1 << (space[i] - 1);
                for(int j: children[space[i]]){
                    current_xor |= 1LL << (j - 1);
                }

                xor_result ^= current_xor;
                ++chosen;
            }
        }

        if(is_switch){
            xor_result ^= (1LL << ::n) - 1;
        }

        if(storeMin.count(xor_result)){
            storeMin[xor_result] = min(storeMin[xor_result], chosen);
        }
        else storeMin[xor_result] = chosen;
    }
}

void solve(){
    int mid = n/2;
    int space1[mid], space2[n - mid];

    for(int i = 0; i < mid; ++i){
        space1[i] = i + 1;
    }
    for(int j = mid; j < n; ++j){
        space2[j - mid] = j + 1;
    }

    generate_subset(mid, space1, storeMinA, false);
    generate_subset(n-mid, space2, storeMinB, true);

    int ans = LIMIT;
    for(auto p: storeMinA){
        if(storeMinB.count(p.first)){
            ans = min(ans, p.second + storeMinB[p.first]);
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LIGHTS.INP","r",stdin);
    freopen("LIGHTS.OUT","w",stdout);

    int m; // edges
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;

        children[a].push_back(b);
        children[b].push_back(a);
    }

    solve();
    return 0;
}

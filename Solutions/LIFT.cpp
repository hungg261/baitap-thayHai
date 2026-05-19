// BT_HungPhan_03102025
/******************************************************************************
Link: LIFT
Code: LIFT
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-14-19.21.47
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
#define cerr if(false)cerr
using namespace std;

int n;
int a, b, c;

bool check(int mid){
    int highest_walk = mid / a;
    if(highest_walk == n)return true;

    int l = highest_walk + 1, h = n, res = LLONG_MAX;
    while(l <= h){
        int chosen = (l + h)/2;

        int down = chosen * c + b * (chosen - highest_walk - 1);
        int up = chosen * c + a * (n - chosen);

        cerr << "\t" << l << ' ' << h << ' ' << chosen << ' ' << down << ' ' << up << '\n';

        if(down > mid){
            h = chosen - 1;
        }
        else if(up > mid){
            l = chosen + 1;
        }
        else{
            res = min(res, max(down, up));
            if(down < up){
                l = chosen + 1;
            }
            else h = chosen - 1;
        }
    }

    cerr << res << '\n';
    return res <= mid;
}

void tknp(){
    int l = 1, h = a * n, res = -1;
    while(l <= h){
        int mid = (l + h)/2;
        cerr<<l<<' '<<h<<' '<<mid<<'\n';
        if(check(mid)){
            res = mid;
            h = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("LIFT.INP","r",stdin);
    freopen("LIFT.OUT","w",stdout);
    cin >> n;
    cin >> a >> b >> c;

    if(n == 0){
        cout << "0\n";
        return 0;
    }

    cerr << "--------------\n\n";

    cerr << check(1) << '\n';
    tknp();
    return 0;
}

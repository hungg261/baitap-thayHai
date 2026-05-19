// BT_HungPhan_05282025
/******************************************************************************
Link: BASKET
Code: BASKET
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-28-20.07.10
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int VALUE_PADDING = 2; // vi du: 0 -> 00, 12 -> 12, 5 -> 05

int string_to_int(string s){
    int res = 0;
    for(int digit: s){
        res = res * 10 + (digit - '0');
    }

    return res;
}

string int_to_string(int n){
    string res;
    while(n > 0){
        res += n % 10 + '0';
        n /= 10;
    }

    while((int)res.size() < VALUE_PADDING) res += '0';
    reverse(begin(res), end(res));

    return res;
}

int mmss_to_ss(int mm, int ss){
    return mm * 60 + ss;
}

int mmss_to_ss(string format){
    assert((int)format.size() == 5);

    string mm_str = format.substr(0, 2);
    string ss_str = format.substr(3, 2);

    int mm = string_to_int(mm_str);
    int ss = string_to_int(ss_str);

    return mmss_to_ss(mm, ss);
}

string ss_to_mmss(int ss){
    string mm_str = int_to_string(ss / 60);
    string ss_str = int_to_string(ss % 60);

    string format = mm_str + ":" + ss_str;
    return format;
}

const int MAXN = 100;
struct goal{
    int team, time;
} events[MAXN + 5];

void solve(int n){
    int team1_score = 0, team2_score = 0;
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; ++i){
        cerr<<i<<' '<<events[i].team<<' '<<events[i].time<<'\n';

        if(events[i].team == 1) ++team1_score;
        else ++team2_score;

        if(team1_score > team2_score){
            int j = i + 1;
            do{
                if(events[j].team == 1) ++team1_score;
                else ++team2_score;

                ++j;
            } while(j <= n && team1_score > team2_score);

            ans1 += events[j].time - events[i].time;
            i = j - 1;
        }
        else if(team1_score < team2_score){
            int j = i + 1;
            do{
                if(events[j].team == 1) ++team1_score;
                else ++team2_score;

                ++j;
            } while(j <= n && team1_score < team2_score);

            ans2 += events[j].time - events[i].time;
            i = j - 1;
        }
    }

    string format1 = ss_to_mmss(ans1), format2 = ss_to_mmss(ans2);

    cerr<<ans1<<' '<<ans2<<'\n';
    cout << format1 << '\n';
    cout << format2 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("BASKET.INP","r",stdin);
    //freopen("BASKET.OUT","w",stdout);
    int n;
    cin >> n;

    for(int event = 1; event <= n; ++event){
        int team;
        string time;

        cin >> team >> time;

        int time_in_seconds = mmss_to_ss(time);
        events[event] = {team, time_in_seconds};
    }
    events[n + 1] = {-1, mmss_to_ss("48:00")};

    solve(n);
    return 0;
}

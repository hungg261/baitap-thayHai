/******************************************************************************
Link: MARBLES
Code: MARBLES
Time (YYYY-MM-DD-hh.mm.ss): 2025-02-05-18.44.52
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(string s,int n){
    string dupe=string(count(begin(s),end(s),'X'),'X')+
                string(count(begin(s),end(s),'T'),'T')+
                string(count(begin(s),end(s),'D'),'D');

    int x_T=0,x_D=0,
        t_X=0,t_D=0,
        d_X=0,d_T=0;

    for(int i=0;i<n;++i){
        if(dupe[i]=='X'){
            if(s[i]=='T'){
                ++x_T;
            }
            else if(s[i]=='D'){
                ++x_D;
            }
        }
        else if(dupe[i]=='T'){
            if(s[i]=='X'){
                ++t_X;
            }
            else if(s[i]=='D'){
                ++t_D;
            }
        }
        else{
            if(s[i]=='X'){
                ++d_X;
            }
            else if(s[i]=='T'){
                ++d_T;
            }
        }
    }

    int doicho_XT=min(x_T,t_X),
        doicho_TD=min(t_D,d_T),
        doicho_XD=min(x_D,d_X);

    int conlai=(x_T+x_D+t_X+t_D+d_X+d_T)-2*(doicho_XT+doicho_TD+doicho_XD);
    int ans=(doicho_XT+doicho_TD+doicho_XD) + 2*(conlai/3);

    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("MARBLES.INP","r",stdin);
    freopen("MARBLES.OUT","w",stdout);
    int n;
    string s;
    cin>>n>>s;

    solve(s,n);
    return 0;
}

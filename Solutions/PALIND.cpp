// BT_HungPhan_03102025
/******************************************************************************
Link: PALIND
Code: PALIND
Time (YYYY-MM-DD-hh.mm.ss): 2025-05-24-18.40.07
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
#define pow10 sussy
using namespace std;

const int MAXN=15,MAXM=100;
const int MAXHALF=1e7;
int pow10[MAXN+5],pow10mod[MAXN+5];

int n,m,k;

int rev(int n){
    int res=0;
    while(n>0){
        res= (res*10+n%10);
        n/=10;
    }
    return res;
}

int revmod(int n){
    int res=0;
    while(n>0){
        res= (res*10+n%10)%m;
        n/=10;
    }
    return res;
}

void compute(){
    pow10[0]=1;
    pow10mod[0]=1%m;
    for(int power=1;power<=MAXN;++power){
        pow10[power]=pow10[power-1]*10;
        pow10mod[power]=pow10mod[power-1]*10 % m;
    }
}

bool check(int origin,int digitcnt,bool odd_len){
    int mod;
    if(odd_len){
        mod = origin*pow10mod[digitcnt-1] + revmod(origin/10);
    }
    else{
        mod = origin*pow10mod[digitcnt] + revmod(origin);
    }

    mod %= m;
    return mod==0;
}

int build(int origin,int digitcnt,bool odd_len){
    int res;
    if(odd_len){
        res = origin*pow10[digitcnt-1] + rev(origin/10);
    }
    else{
        res = origin*pow10[digitcnt] + rev(origin);
    }

    return res;
}

void solve(){
    int digitcnt=(n+1)/2;
    int cnt=0;

    int res=-1;
    for(int i=pow10[digitcnt-1];i<pow10[digitcnt];++i){
        if(check(i,digitcnt,n%2==1)){
            ++cnt;
            if(cnt==k){
                res=build(i,digitcnt,n%2==1);
            }
        }
    }

    cout<<cnt<<'\n';
    cout<<res<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PALIND.INP","r",stdin);
    freopen("PALIND.OUT","w",stdout);
    cin>>n>>m>>k;

    compute();
    solve();
    return 0;
}

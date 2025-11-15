/******************************************************************************
Link: FROG
Code: FROG
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-17-21.48.29
*******************************************************************************/
#include<bits/stdc++.h>
#define watch(a) cerr<<#a<<" = "<<(a)<<'\n';
#define sep(x) cerr<<"\n-----"<<x<<"-----\n"
using namespace std;

int n,a,b;
vector<int>res;

template<typename func>
void jump(int start,int stop,int step,func f){
    for(int i=start;f(i,stop);i+=step){
        res.push_back(i);
    }
}

void solve1(){
    jump(a,1,-2,greater_equal<int>());

    int low;
    if(a%2==0)low=1;
    else low=2;

    jump(low,a,2,less<int>());
    jump(a+1,b,1,less<int>());
    jump(b+1,n,2,less_equal<int>());

    int high;
    if((n-b)%2==0)high=n;
    else high=n-1;

    jump(high,b+1,-2,greater_equal<int>());
}

void solve2(){
    jump(a,n,2,less_equal<int>());

    int low;
    if((n-a)%2==0)low=n-1;
    else low=n;

    jump(low,a,-2,greater<int>());
    jump(a-1,b,-1,greater<int>());
    jump(b-1,1,-2,greater_equal<int>());

    int high;
    if(b%2==0)high=2;
    else high=1;

    jump(high,b-1,2,less_equal<int>());
}

void solve(){
    if(a<b)solve1();
    else solve2();

    int len=res.size();
    for(int i=1;i<len;++i){
        int diff=abs(res[i]-res[i-1]);
        if((diff!=1&&diff!=2)||res[i]==b){
            cout<<"0\n";
            return;
        }
    }
    res.push_back(b);
    for(int i=1;i<=len;++i){
        cout<<res[i]-res[i-1]<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("FROG.INP","r",stdin);
    freopen("FROG.OUT","w",stdout);
    cin>>n>>a>>b;

    solve();
    return 0;
}

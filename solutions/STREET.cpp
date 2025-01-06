/******************************************************************************
Link: STREET
Code: STREET
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-10-20.03.44
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(int n){
    int cnt=-1,a=1,b,c;
    while(a<=n){
        b=a;
        while(b<=n){
            c=b;
            while(c<=n){
                cnt++;
                c*=7;
            }
            b*=5;
        }
        a*=3;
    }
    return cnt;
}

bool pfactor(int n){
    while(n%3==0)n/=3;
    while(n%5==0)n/=5;
    while(n%7==0)n/=7;
    return n<=1;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("STREET.INP","r",stdin);
    freopen("STREET.OUT","w",stdout);
    int n;
    while(cin>>n){
        if(pfactor(n))cout<<(solve(n)%2==1?'L':'R')<<'\n';
        else cout<<"N\n";
    }
    return 0;
}

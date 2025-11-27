#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("PRODIG.INP","r",stdin);freopen("PRODIG.OUT","w",stdout);
    int n;cin>>n;
    if(n<2)cout<<(n==1?1:10);
    else{
        string s="";
        for(int i=9;i>1;i--){
            while(n%i==0){
                n/=i;
                s+=i+'0';
            }
        }
        if(n==1&&s.size())for(int i=s.size()-1;i>=0;i--)cout<<s[i];
        else cout<<-1;
    }
    return 0;
}
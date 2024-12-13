#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BRACKETS.INP","r",stdin);freopen("BRACKETS.OUT","w",stdout);
    int n;cin>>n;
    char R[2*n]={};

    int p=0,np=0;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        while(R[p]!=0)p++;
        R[p]='(';
        R[p+k+1]=')';
        //np=max(np,p+k+1);
        p++;
        //for(int p:R)cout<<(p==0?'-':(p==1?'(':')'));cout<<endl;
    }
    for(char p:R)cout<<p;
    //for(int p:R)cout<<p;
    return 0;
}

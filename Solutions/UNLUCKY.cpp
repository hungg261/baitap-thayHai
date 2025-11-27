/******************************************************************************
Link: UNLUCKY
Code: UNLUCKY
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-11-20.28.41
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

const int _digit=20,_behon=2,_chua5=2;
int dp[_digit][_behon][_chua5];

int solve(string&n,int pos,bool behon,bool chua5){
    if(pos==n.size()){
        return chua5? 1:0;
    }
    if(dp[pos][behon][chua5]!=-1){
        return dp[pos][behon][chua5];
    }

    int limit=behon? 9:n[pos]-'0';
    int res=0;
    for(int d=0;d<=limit;++d){
        res+=solve(n,pos+1,behon||(d<n[pos]-'0'),chua5||d==5);
    }

    dp[pos][behon][chua5]=res;
    return res;
}

int query(string q){
    memset(dp,-1,sizeof(dp));
    int ans=solve(q,0,false,false);

    return ans;
}

string toString(int num){
    string res="";
    while(num>0){
        res+=num%10+'0';
        num/=10;
    }
    reverse(begin(res),end(res));
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("UNLUCKY.INP","r",stdin);
    freopen("UNLUCKY.OUT","w",stdout);
    int a,b;
    cin>>a>>b;

    cout<<query(toString(b))-query(toString(a-1));
    return 0;
}

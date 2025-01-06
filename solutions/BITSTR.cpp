/******************************************************************************
Link: BITSTR
Code: BITSTR
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-14-15.35.05
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int n;
int solve(string s,char k){
    int c=0;
    for(int i=0;i<n-3;++i){
        if(s[i]!=k){
            for(int j=i;j<i+4;++j)s[j]=s[j]=='0'?'1':'0';
            ++c;
        }
    }
    for(char q:s)if(q!=k)return -1;
    return c;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BITSTR.INP","r",stdin);freopen("BITSTR.OUT","w",stdout);
    string s;cin>>s;
    n=s.size();

    int r1=solve(s,'0'),r2=solve(s,'1');
    if(r1<0&&r2<0)cout<<-1;
    else if(r1>=0&&r2>=0)cout<<min(r1,r2);
    else cout<<(r1<0?r2:r1);
    return 0;
}

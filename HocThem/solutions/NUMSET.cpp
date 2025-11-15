/******************************************************************************
Link: NUMSET
Code: NUMSET
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-15-22.15.16
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int solve(const string&s){
    unordered_set<string>Q;
    int n=s.size();

    int sum=accumulate(begin(s),end(s),0)-n*'0';
    if(sum%3==0)Q.insert(s);

    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            string num="";
            int rem=0;
            for(int k=0;k<n;++k){
                if(k<i||k>j){
                    rem=(rem*10+s[k]-'0')%3;
                    num+=s[k];
                }
            }
//            cout<<num<<' '<<rem<<'\n';

            int pos=0;
            while(!num.empty()&&num[pos]=='0'&&num.size()>1)++pos;
            if(!num.empty()&&rem==0){
                Q.insert(num.substr(pos));
            }
        }
    }
    return Q.size();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("NUMSET.INP","r",stdin);
    freopen("NUMSET.OUT","w",stdout);
    string s;
    cin>>s;

    cout<<solve(s);
    return 0;
}

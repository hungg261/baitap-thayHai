/******************************************************************************
Link: DOWRY
Code: DOWRY
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-29-16.06.14
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

vector<string>res;
int n,target,A[21],mark[21],sum=0;

void solve(int pos,int a,int b,int c){
    if(a>target||b>target||c>target)return;
    if(pos==n){
        if(a==target&&b==target&&c==target){
            string ans="";
            for(int i=0;i<n;++i){
                if(mark[i]==0)ans+='A';
                else if(mark[i]==1)ans+='B';
                else ans+='C';
            }
            res.pb(ans);
        }
        return;
    }

    mark[pos]=0;
    solve(pos+1,a+A[pos],b,c);
    mark[pos]=1;
    solve(pos+1,a,b+A[pos],c);
    mark[pos]=2;
    solve(pos+1,a,b,c+A[pos]);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DOWRY.INP","r",stdin);
    freopen("DOWRY.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i];
        sum+=A[i];
    }

    if(sum%3!=0)cout<<-1;
    else{
        target=sum/3;
        solve(0,0,0,0);

        if(res.empty())cout<<-1;
        else{
            cout<<res.size()<<endl;
            for(string&k:res)cout<<k<<endl;
        }
    }
    return 0;
}

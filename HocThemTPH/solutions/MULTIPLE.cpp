/******************************************************************************
Link: MULTIPLE
Code: MULTIPLE
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-18-18.32.03
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

string solve(const int&n){
    if(n==1)return "1";
    queue<int>que;
    bool mark[10005]={0,1};
    int pre[10005]={},trace[10005];
    pre[1]=-1;
    que.push(1);

    while(!que.empty()){
        int num=que.front();
        que.pop();

        if(num==0){
            string ans;
            while(pre[num]!=-1){
                ans+=trace[num]+'0';
                num=pre[num];
            }
            ans+='1';
            reverse(begin(ans),end(ans));
            return ans;
        }
        int div0=(num*10)%n,div1=(num*10+1)%n;
        if(!mark[div0]){
            que.push(div0);
            pre[div0]=num;
            trace[div0]=0;
        }
        if(!mark[div1]){
            que.push(div1);
            pre[div1]=num;
            trace[div1]=1;
        }
        mark[div0]=mark[div1]=true;
    }
    return "-1";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MULTIPLE.INP","r",stdin);
    freopen("MULTIPLE.OUT","w",stdout);
    int n;
    while(cin>>n){
        if(n==0)break;
        cout<<solve(n)<<'\n';
    }
    return 0;
}

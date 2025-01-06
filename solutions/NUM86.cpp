/******************************************************************************
Link: NUM86
Code: NUM86
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-14-19.00.39
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=200;
int f[205][205];

string build(int num8,int num6){
    return string(num8,'8')+string(num6,'6');
}

string solve_cach1(int MOD){
    for(int i=1;i<=MAX;++i){
        f[i][0]=(f[i-1][0]*10+8)%MOD;
    }

    for(int i=0;i<=MAX;++i){
        for(int j=1;j<=MAX;++j){
            f[i][j]=(f[i][j-1]*10+6)%MOD;
        }
    }

    for(int len=1;len<=MAX;++len){
        for(int i=0;i<=len;++i){
            int j=len-i;
            if(i==0&&j==0)continue;

            if(f[i][j]==0){
                return build(i,j);
            }
        }
    }

    return "-1";
}

string solve_cach2(const int&MOD){
    queue<pair<int,string>>que;
    que.push({6%MOD,"6"});
    que.push({8%MOD,"8"});

    while(!que.empty()){
        auto p=que.front();
        que.pop();

        int rem=p.first;
        string num=p.second;
        if(rem==0){
            return num;
        }

        int div6=(rem*10+6)%MOD,div8=(rem*10+8)%MOD;
        que.push({div6,num+"6"});
        if(num.back()=='8'){
            que.push({div8,num+"8"});
        }
    }
    return "-1";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("NUM86.INP","r",stdin);
    freopen("NUM86.OUT","w",stdout);
    int t;
    cin>>t;

    while(t--){
        int n;cin>>n;
         cout<<solve_cach1(n)<<'\n';
//        cout<<solve_cach2(n)<<'\n';
    }

    return 0;
}

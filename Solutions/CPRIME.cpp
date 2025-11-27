/******************************************************************************
Link: CPRIME
Code: CPRIME
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-25-18.46.17
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

const int MAX=1e6+5;
int Q[MAX],sub5Q[MAX],ans[MAX],sub5ans[MAX];
bool P[MAX];

void compute(){
    fill(Q+1,Q+MAX,1);
    fill(sub5Q+1,sub5Q+MAX,1);
    for(int i=2;i<MAX;++i){
        if(Q[i]==1)for(int j=i;j<MAX;j+=i){
            int r=j,c=0;
            while(r%i==0)
                r/=i,
                ++c;
            Q[j]*=c+1;
            sub5Q[j]*=2*c+1;
        }
    }

    fill(P+2,P+MAX,true);
    for(int i=2;i*i<MAX;++i){
        if(P[i])for(int j=i*i;j<MAX;j+=i){
            P[j]=false;
        }
    }

    ans[0]=0;
    sub5ans[0]=0;
    for(int i=1;i<MAX;++i){
        ans[i]=ans[i-1];
        if(P[Q[i]])++ans[i];

        sub5ans[i]=sub5ans[i-1];
        if(P[sub5Q[i]])++sub5ans[i];
    }
}

int solve(int a,int b){
    if(a>1000000){
        return sub5ans[(int)sqrt(b)]-sub5ans[(int)ceil(sqrt(a))-1];
    }
    return ans[b]-ans[a-1];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CPRIME.INP","r",stdin);
    freopen("CPRIME.OUT","w",stdout);

    compute();
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        cout<<solve(a,b)<<'\n';
    }
    return 0;
}

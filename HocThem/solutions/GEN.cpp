/******************************************************************************
Link: GEN
Code: GEN
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-02-20.41.18
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

const int MAX=1005;
unsigned long long A[MAX],B[MAX];
int n,m;

bool ktsnt(int target){
    for(int i=2;i*i<=target;++i)
        if(target%i==0)return false;
    return target>1;
}

bool check(int target){
    int l=1,h=3162277660LL;
    while(l<=h){
        int mid=(l+h)/2,value=mid*mid;
        if(value==target)return true;
        else if(value>target)h=mid-1;
        else l=mid+1;
    }

    l=1,h=2154434;
    while(l<=h){
        int mid=(l+h)/2,value=mid*mid*mid;
        if(value==target&&ktsnt(mid))return true;
        else if(value>target)h=mid-1;
        else l=mid+1;
    }
    return false;
}

int dp[MAX][MAX];
int solve(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("GEN.INP","r",stdin);
    freopen("GEN.OUT","w",stdout);
    string line1,line2;
    getline(cin,line1);
    getline(cin,line2);

    stringstream str1(line1),str2(line2);
    int val;
    while(str1>>val)if(check(val))A[n++]=val;
    while(str2>>val)if(check(val))B[m++]=val;

    cout<<solve();
    return 0;
}

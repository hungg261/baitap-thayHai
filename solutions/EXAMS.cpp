/******************************************************************************
Link: EXAMS
Code: EXAMS
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-02-20.44.28
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

int n,t,Q[37],A[300000],a=0,B[300000],b=0;
void compute(int space[],int n,int storage[],int&len){
    for(int mask=0;mask<(1<<n);++mask){
        int sum=0;
        for(int i=0;i<n;++i){
            if(mask&(1<<i)){
                sum+=space[i];
            }
        }
        storage[len++]=sum;
    }
}

int solve(){
    int mid=n/2;
    int space1[mid],space2[n-mid];
    for(int i=0;i<mid;++i)
        space1[i]=Q[i];
    for(int i=mid;i<n;++i)
        space2[i-mid]=Q[i];

    compute(space1,mid,A,a);
    compute(space2,n-mid,B,b);
    sort(B,B+b);

    int ans=0;
    for(int i=0;i<a;++i){
        int l=0,h=b-1,pos=b;
        while(l<=h){
            int m=(l+h)/2;
            if(B[m]+A[i]>=t){
                pos=m;
                h=m-1;
            }
            else l=m+1;
        }
        ans+=b-pos;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("EXAMS.INP","r",stdin);
    freopen("EXAMS.OUT","w",stdout);
    cin>>n>>t;
    for(int i=0;i<n;++i)cin>>Q[i];

    cout<<solve();
    return 0;
}

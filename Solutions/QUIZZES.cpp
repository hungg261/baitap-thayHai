/******************************************************************************
Link: QUIZZES
Code: QUIZZES
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-17-15.34.08
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

const int MAX=1e5+1;
int n,q,A[MAX],B[MAX];
bool check(int mid){
    for(int i=0;i<mid;++i)B[i]=A[i];
    sort(B,B+mid);
    int r=1;
    for(int i=0;i<mid&&B[i]<=r;++i){
        r+=B[i];
    }
    return r>q;
}

int tknp(){
    int l=1,h=n,k=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
            k=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return k;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("QUIZZES.INP","r",stdin);freopen("QUIZZES.OUT","w",stdout);
    int t;cin>>t;
    while(t--){
        cin>>n>>q;inp(A,n);
        cout<<tknp()<<endl;
    }
    return 0;
}

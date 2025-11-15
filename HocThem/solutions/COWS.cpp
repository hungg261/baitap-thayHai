/******************************************************************************
Link: COWS
Code: COWS
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-21-22.09.37
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
#define int long long
#define double long double
using namespace std;

const int MAX=1e5+1;
int n,s=0;
struct cow{
    int t,d;
    double avg;

    void calc(){
        avg=2.0*t/d;
    }
} A[MAX];

bool op(cow&a,cow&b){
    if(a.avg==b.avg)return a.t<b.t;
    return a.avg<b.avg;
}

bool check(int mid){
    int r=s;
    for(int i=0;i<n&&mid>=0;++i){
        r-=A[i].d;
        mid-=2*A[i].t*r;
    }
    return mid>=0;
}

int tknp(){
    int l=0,h=1e18,k=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid))k=mid,h=mid-1;
        else l=mid+1;
    }
    return k;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("COWS.INP","r",stdin);freopen("COWS.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i].t>>A[i].d;
        s+=A[i].d;
        A[i].calc();
    }
    sort(A,A+n,op);

//    for(int i=0;i<n;++i){
//        cout<<A[i].t<<' '<<A[i].d<<' '<<A[i].avg<<endl;
//    }
    cout<<tknp();
    return 0;
}

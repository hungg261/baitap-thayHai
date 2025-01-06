#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define int long long
using namespace std;

const int MAX=1e6+1,cst[10]={6,2,5,5,4,5,6,3,7,6};
int n,k,A[MAX],B[MAX];
bool check(int q,int p){
    return 2*p<=q&&q<=7*p;
}

void solve(){
    for(int i=0,t=k;i<n;++i){
        int j=0+(i==0);
        for(;j<10;j++){
            bool chk=check(t-cst[j],n-i-1);
            //cout<<j<<' '<<k<<' '<<' '<<n-i-1<<' '<<chk<<' '<<endl;
            if(chk){
                A[i]=j;
                t-=cst[j];
                break;
            }
        }
        //cout<<endl;
    }

    for(int i=0;i<n;++i){
        for(int j=9;j>=0+(i==0);j--){
            bool chk=check(k-cst[j],n-i-1);
            //cout<<j<<' '<<k<<' '<<' '<<n-i-1<<' '<<chk<<' '<<endl;
            if(chk){
                B[i]=j;
                k-=cst[j];
                break;
            }
        }
        //cout<<endl;
    }

    for(int i=0;i<n;i++)cout<<A[i];cout<<endl;
    for(int i=0;i<n;i++)cout<<B[i];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("LED.INP","r",stdin);freopen("LED.OUT","w",stdout);
    cin>>n>>k;
    if(2*n<=k&&k<=7*n)solve();
    else cout<<"NO SOLUTION";

    return 0;
}

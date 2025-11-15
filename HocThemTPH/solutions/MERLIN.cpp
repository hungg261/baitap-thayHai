#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
#define int long long
using namespace std;

const int MAX=1e5+1;
int n;

bool check(int mid,int A[]){
    int q=0;
    for(int i=0;i<mid;i++){
        q+=A[i];
    }
    //cout<<q<<endl;

    for(int i=mid+1;i<n;i++){
        q-=A[mid]-A[i];
        //cout<<q<<' '<<A[i]<<endl;
    }
    return q>=0;
}

int tknp(int A[]){
    int l=0,h=n-1,k=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid,A)){
            k=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return k;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MERLIN.INP","r",stdin);freopen("MERLIN.OUT","w",stdout);
    cin>>n;
    int A[n];inp(A);
    sort(A,A+n,greater<int>());
    //for(int k:A)cout<<k<<' ';cout<<endl;

    cout<<tknp(A);
    return 0;
}

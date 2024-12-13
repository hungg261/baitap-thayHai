/******************************************************************************
Link: TRIPLE
Code: TRIPLE
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-19-16.28.22
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

const int MAX=5001;
int n,A[MAX];

int tknp(int l,int h,int target){
    while(l<=h){
        int mid=(l+h)/2;
        if(A[mid]==target)
            return mid;
        else if(A[mid]>target)h=mid-1;
        else l=mid+1;
    }
    return -1;
}

void solve(){
    bool f=0;
    sort(A,A+n);
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(A[i]==A[j])continue;
            int pos=tknp(j+1,n-1,2*A[j]-A[i]);
            if(pos!=-1){
                cout<<A[i]<<' '<<A[j]<<' '<<A[pos]<<endl;
                f=1;
                break;
            }
        }
        if(f)break;
    }
    if(!f)cout<<"0 0 0";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TRIPLE.INP","r",stdin);freopen("TRIPLE.OUT","w",stdout);
    cin>>n;inp(A,n);

    solve();
    return 0;
}

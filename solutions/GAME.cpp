/******************************************************************************
Link: GAME
Code: GAME
Time (YYYY-MM-DD-hh.mm.ss): 2025-02-16-08.39.55
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

const int MAX=1e5;
int A[MAX+1],B[MAX+1],n;

int tknp_up(int Q[],int target){
    int l=0,h=n-1,res=n-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(Q[mid]>=target){
            res=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return res;
}

int tknp_low(int Q[],int target){
    int l=0,h=n-1,res=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(Q[mid]<=target){
            res=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return res;
}

ull abs_sum(int a,int b){
    ull res=(ull)a+(ull)b;
    return a<-b?~(res-1):res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GAME.INP","r",stdin);
    freopen("GAME.OUT","w",stdout);
    cin>>n;
    inp(A,n);inp(B,n);
    sort(B,B+n);

    ull ans=-1;
    for(int i=0;i<n;++i){
        int high=tknp_up(B,-A[i]),low=tknp_low(B,-A[i]);
        ans=min({ans,abs_sum(A[i],B[high]),abs_sum(A[i],B[low])});
        if(ans==0)break;
    }
    cout<<ans<<'\n';
    return 0;
}

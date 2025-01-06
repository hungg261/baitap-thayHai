/******************************************************************************
Link: TRIANGLES
Code: TRIANGLES
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-18-20.51.29
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

const int MAX=5005;
int A[MAX],B[MAX],R[MAX],r=0,S[MAX],s=0,Q[MAX],n;

void nen(int a[],int n,int to[]){
    int b[n];
    copy(a,a+n,b);
    sort(b,b+n);

    for(int i=0;i<n;++i){
        to[i]=lower_bound(b,b+n,a[i])-b+1;
    }
}

int solve(int A[]){
    int ans=0;
    for(int i=0;i<MAX;++i){
        if(Q[i]>=3){
            ++ans;
        }
    }

    for(int i=0;i<s;++i){
        if(Q[S[i]]>=2){
            for(int j=0;j<s;++j){
                if(R[i]!=R[j]&&R[j]<2*R[i]){
                        ++ans;
//                    cout<<A[i]<<' '<<A[j]<<'\n';
                }
            }
        }
    }

    int k=2;
    for(int i=0;i<r;++i){
        for(int j=i+1;j<r;++j){
            int l=j+1,h=r-1,k=j;
            while(l<=h){
                int mid=(l+h)/2;
                if(R[i]+R[j]<=R[mid]){
                    h=mid-1;
                }
                else{
                    k=mid;
                    l=mid+1;
                }
            }
            ans+=k-j;
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TRIANGLES.INP","r",stdin);
    freopen("TRIANGLES.OUT","w",stdout);
    cin>>n;
    inp(A,n);

    sort(A,A+n);
    nen(A,n,B);
    for(int i=0;i<n;++i){
        if(Q[B[i]]==0)R[r++]=A[i],S[s++]=B[i];
        ++Q[B[i]];
    }
//    for(int i=0;i<r;++i)cout<<R[i]<<' ';cout<<'\n';
    cout<<solve(A);
    return 0;
}

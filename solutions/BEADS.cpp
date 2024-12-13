/******************************************************************************
Link: BEADS
Code: BEADS
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-14-22.20.44
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

string s;
int k,A[369]={};

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BEADS.INP","r",stdin);freopen("BEADS.OUT","w",stdout);
    cin>>s>>k;
    int n=s.size();

    int i1=0,i2=0,cur=0,r=1e9;
    while(i1<=i2&&i2<n){
        if(cur<k){
            if(A[s[i2]]==0)++cur;
            ++A[s[i2]];
            ++i2;
        }
        while(cur>=k){
            --A[s[i1]];
            if(A[s[i1]]==0)--cur;
            r=min(r,i2-i1);
            ++i1;
        }
        if(r==k)break;
    }
    cout<<(r!=1e9?r:-1);

    return 0;
}

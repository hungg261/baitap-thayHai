#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
using namespace std;

const int MAX=1e5+1;
bool A[MAX]={};
int n,k;

void solve0(){
    int i1=1,i2=0,zpos=0,cur=0,maxcur=0;
    while(i2<=n){
        if(!A[i2+1]){
            i1=zpos+1;
            maxcur=max(maxcur,cur);
            zpos=i2+1;
            cur=i2-i1+1;
        }
        ++cur;
        ++i2;
        //cout<<cur<<' '<<i1<<' '<<i2<<endl;
    }
    cout<<max(maxcur,cur);
}

void solve1(){
    int i1=1,cur=0,maxcur=0;
    while(i1<=n){
        cur=0;
        while(i1<=n&&A[i1++]){
            ++cur;
        }
        maxcur=max(maxcur,cur);
        //cout<<cur<<' '<<i1<<endl;
    }
    cout<<maxcur;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("L_SEQ.INP","r",stdin);freopen("L_SEQ.OUT","w",stdout);
    cin>>n>>k;
    for(int i=0;i<k;++i){
        int q;cin>>q;
        A[q]=1;
    }
    if(A[0])solve0();
    else solve1();

    return 0;
}

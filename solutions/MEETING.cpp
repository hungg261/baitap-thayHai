#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
using namespace std;

const int MAX=1e6+1;
int R[MAX];
struct ev{
    int start,stop,idx;
} A[MAX];

bool op(ev&a,ev&b){
    if(a.stop==b.stop)return a.start>b.start;
    return a.stop<b.stop;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MEETING.INP","r",stdin);freopen("MEETING.OUT","w",stdout);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i].start>>A[i].stop;
        A[i].idx=i+1;
    }
    sort(A,A+n,op);

    int cur=0,c=0;
    for(int i=0;i<n;i++){
        if(A[i].start>=cur){
            cur=A[i].stop;
            R[c++]=A[i].idx;
        }
        //cout<<A[i].start<<' '<<A[i].stop<<endl;
    }
    cout<<c<<endl;
    for(int i=0;i<c;i++)cout<<R[i]<<endl;

    return 0;
}

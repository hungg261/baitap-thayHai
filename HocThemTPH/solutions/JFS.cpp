#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
using namespace std;

const int MAX=1e6+1;
int A[MAX],S[MAX];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("JFS.INP","r",stdin);freopen("JFS.OUT","w",stdout);
    int n=-1;
    while(cin>>A[++n]);

    stack<int>R;
    for(int i=n-1;i>=0;--i){
        while(!R.empty()&&A[i]>=A[R.top()])R.pop();
        if(R.empty())S[i]=-1;
        else S[i]=R.top()+1;

        R.push(i);
    }
    for(int i=0;i<n;++i)cout<<S[i]<<' ';
    return 0;
}

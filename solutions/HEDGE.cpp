/******************************************************************************
Link: HEDGE
Code: HEDGE
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-27-19.40.20
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

const int MAX=1e6;
int n,x,a[MAX+1],P[MAX+1],dqmin[3*MAX+5],dqmax[MAX+2];
void solve(){
    deque<int>dq;
    for(int i=1;i<=n;++i){
        if(!dq.empty()&&i-dq.front()+1>x)dq.pop_front();
        while(!dq.empty()&&a[i]<a[dq.back()])dq.pop_back();
        dq.push_back(i);

        if(i>=x){
            dqmin[i]=a[dq.front()];
        }
    }

    dq.clear();
    int covered=0;
    for(int i=1;i<=n+x-1;++i){
        if(!dq.empty()&&i-dq.front()+1>x)dq.pop_front();
        while(!dq.empty()&&dqmin[i]>dqmin[dq.back()])dq.pop_back();
        dq.push_back(i);

        if(i>=x){
            dqmax[i-x+1]=dqmin[dq.front()];
            covered+=dqmax[i-x+1];
        }
    }

    int i=1,j=1,cnt=0;
    dqmax[n+1]=0;
    while(i<=n&&j<=n){
        while(j+1-i+1<=x&&dqmax[j]==dqmax[j+1]){
            ++j;
        }
        i=j+1;
        j=i;
        ++cnt;
    }

//    int covered=0;
//    for(int i=1;i<=n;++i){
//        covered+=dqmax[i];
//        cerr<<dqmax[i]<<' ';
//    }cerr<<'\n';
    cout<<P[n]-covered<<'\n'<<cnt<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("HEDGE.INP","r",stdin);
    freopen("HEDGE.OUT","w",stdout);
    cin>>n>>x;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        P[i]=P[i-1]+a[i];
    }

    solve();
    return 0;
}

/******************************************************************************
Link: INCRUNS
Code: INCRUNS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-04-19.51.23
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

const int MAX=2e5;
int n,a[MAX+2],m,cur_ans=0;
int first,last;

int dem(){
    int i=1,
        j=1;
    int ans=0;
    while(i<=n&&j<=n){
        while(a[j]<a[j+1]){
            ++j;
        }
        i=j+1;
        j=i;
        ++ans;
    }
    return ans;
}

void solve1(){
    int pos,x;
    cin>>pos>>x;

    int cur=(first+pos-2)%n+1,
        nxt=cur%n+1,
        prv=(cur-2+n)%n+1;

    if(cur!=first&&a[prv]>=a[cur]&&x>a[prv])--cur_ans;
    if(cur!=first&&a[prv]<a[cur]&&x<=a[prv])++cur_ans;
    if(cur!=last&&a[cur]>=a[nxt]&&x<a[nxt])--cur_ans;
    if(cur!=last&&a[cur]<a[nxt]&&x>=a[nxt])++cur_ans;
    a[cur]=x;
}

void solve2(){
    int z;
    cin>>z;
    if(z%n==0)return;

    int left=(first+z-2)%n+1,right=left%n+1;
    if(a[left]<a[right])++cur_ans;
    if(a[last]<a[first])--cur_ans;

    first=right,last=left;
}

void query(){
    int type;
    cin>>type;

    if(type==1){
        solve1();
    }
    else{
        solve2();
    }
    cout<<cur_ans<<'\n';
}

void input(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    a[0]=1e9+5;
    a[n+1]=-1e9-5;
    cur_ans=dem();
    first=1,last=n;

    cin>>m;
    while(m--){
        query();
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("INCRUNS.INP","r",stdin);
    freopen("INCRUNS.OUT","w",stdout);
    input();

    return 0;
}

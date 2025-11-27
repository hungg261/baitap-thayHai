/******************************************************************************
Link: DISHES
Code: DISHES
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-27-20.24.31
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

unordered_set<int>mark;
struct state{
    int arr[8];

    void compress(int len){
        int B[8];
        copy(arr,arr+len,B);
        sort(B,B+len);
        for(int i=0;i<len;++i){
            arr[i]=lower_bound(B,B+len,arr[i])-B;
        }
    }

    int id(int len){
        int res=0;
        for(int i=0;i<len;++i){
            res=res*10+arr[i];
        }
        return res;
    }

    void rev(int idx){
        reverse(arr,arr+idx);
    }

    bool sorted(int len){
        return is_sorted(arr,arr+len);
    }
} start;

void solve(int n){
    queue<pair<int,state>>que;
    que.push({0,start});
    while(!que.empty()){
        auto p=que.front();
        int mov=p.first;
        state cur=p.second;

//        cout<<mov<<'\n';
//        for(int i=0;i<n;++i){
//            cout<<cur.arr[i]<<' ';
//        }cout<<"\n\n";

        if(cur.sorted(n)){
            cout<<mov;
            return;
        }
        que.pop();
        int ide=cur.id(n);
        if(mark.count(ide))continue;
        mark.insert(ide);

        for(int i=1;i<=n;++i){
            cur.rev(i);
            que.push({mov+1,cur});
            cur.rev(i);
        }
    }
    cout<<-1;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DISHES.INP","r",stdin);
    freopen("DISHES.OUT","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>start.arr[i];
    }

    start.compress(n);
    solve(n);
//    for(int i=0;i<n;++i){
//        cout<<start.arr[i]<<' ';
//    }
    return 0;
}

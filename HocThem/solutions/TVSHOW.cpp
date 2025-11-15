#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
using namespace std;

struct ev{
    int time,type;
};

bool op(ev&a,ev&b){
    if(a.time<b.time)return true;
    else if(a.time>b.time)return false;
    return a.type>b.type;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TVSHOW.INP","r",stdin);freopen("TVSHOW.OUT","w",stdout);
    int n,c=0,pv=0,cur=0,r=0;cin>>n;
    vector<ev>A;
    for(int i=0;i<n;i++){
        ev p1,p2;p1.type=0;p2.type=1;
        cin>>p1.time>>p2.time;
        A.pb(p1);A.pb(p2);
    }
    sort(it(A),op);
    for(ev k:A){
        if(k.type){
            cur--;
        }
        else{
            r+=cur;
            cur++;
        }
        //cout<<cur<<' '<<r<<endl;
    }

    //cout<<endl;
    //for(auto k:A){
        //cout<<k.time<<' '<<k.type<<endl;
    //}
    cout<<r;
    return 0;
}

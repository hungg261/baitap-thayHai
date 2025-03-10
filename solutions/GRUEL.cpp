/******************************************************************************
Link: GRUEL
Code: GRUEL
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-15-19.29.34
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=1e4;
int n,m,k;
int mark[MAX+1];

struct at_time{
    int pos,idx;
    bool food,type;

    void create(int p,int i,bool f,bool t){
        tie(pos,idx,food,type)={p,i,f,t};
    }
} guests[2*MAX+1];

bool op(at_time&a,at_time&b){
    if(a.pos==b.pos){
        return a.type>b.type;
    }
    return a.pos<b.pos;
}

void solve(){
    for(int i=1;i<=k*2;++i){
        int pos,idx;
        bool food,type;

        tie(pos,idx,food,type)={guests[i].pos,guests[i].idx,guests[i].food,guests[i].type};
        if(type){
            if(mark[idx]==1){
                ++n;
                if(food)++m;
            }
        }
        else{
            int newn=n-1,newm=m;
            if(food)--newm;

            if(newn<0||newm<0){
                mark[idx]=-1;
            }
            else{
                mark[idx]=1;
                n=newn,m=newm;
            }
        }
    }

    for(int i=1;i<=k;++i){
        cout<<(mark[i]==1?"Yes":"No")<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("GRUEL.INP","r",stdin);
    freopen("GRUEL.OUT","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=k;++i){
        int t,d,a;
        cin>>t>>d>>a;

        guests[i*2-1].create(t,i,a,0);
        guests[i*2].create(t+d,i,a,1);
    }
    sort(guests+1,guests+k*2+1,op);

    solve();
    return 0;
}

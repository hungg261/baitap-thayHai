/******************************************************************************
Link: STICKS
Code: STICKS
Time (YYYY-MM-DD-hh.mm.ss): 2025-02-05-21.18.25
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5;
int n,l[MAXN];
double S;
unordered_map<int,int>mark;

struct positions{
    int mark[4],len=0;

    void push(int value){
        if(len>=4)return;
        mark[len++]=value;
    }
};
unordered_map<int, positions>map_pos;

struct result{
    int self[4]={(int)1e9};

    void update(int i,int j,int k,int t,bool forced){
        int newlist[4]={i,j,k,t};
        sort(newlist,newlist+4);
        if(forced){
            memcpy(self,newlist,sizeof(newlist));
            return;
        }

        for(int i=0;i<4;++i){
            if(self[i]<newlist[i])return;
            else if(self[i]>newlist[i]){
                memcpy(self,newlist,sizeof(newlist));
                return;
            }
        }

    }

    void output(){
        if(self[0]==(int)1e9){
            cout<<"-1\n";
            return;
        }
        for(int i=0;i<4;++i){
            cout<<self[i]<<' ';
        }
        cout<<'\n';
    }
};

void solve(){
    vector<int>values;
    for(auto p:mark){
        for(int i=1;i<=p.second/2;++i){
            values.push_back(p.first);
        }
    }
    sort(begin(values),end(values));

    result ans;
    double mindiff=1e18;
    for(int value:values){
        int pos=upper_bound(begin(values),end(values),S/value)-begin(values)-1;
        if(pos==-1)continue;

        double tich=(double)value*values[pos];
        if(S-tich<=mindiff){
            if(value!=values[pos]){
                ans.update(map_pos[value].mark[0],map_pos[value].mark[1],
                           map_pos[values[pos]].mark[0],map_pos[values[pos]].mark[1],
                           S-tich<mindiff);
            }
            else{
                if(map_pos[value].len/2<=1)continue;

                ans.update(map_pos[value].mark[0],map_pos[value].mark[1],
                           map_pos[value].mark[2],map_pos[value].mark[3],
                           S-tich<mindiff);

            }
            mindiff=min(mindiff,S-tich);
        }
    }

    ans.output();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("STICKS.INP","r",stdin);
    freopen("STICKS.OUT","w",stdout);
    cin>>n>>S;
    for(int i=0;i<n;++i){
        cin>>l[i];
        ++mark[l[i]];
        map_pos[l[i]].push(i+1);
    }

    solve();
    return 0;
}

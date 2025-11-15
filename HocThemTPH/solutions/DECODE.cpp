/******************************************************************************
Link: DECODE
Code: DECODE
Time (YYYY-MM-DD-hh.mm.ss): 2024-07-17-20.12.56
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A) for(int&k:A)cin>>k
using namespace std;

const string cds[9]={"a","b","cc","bbc","cbc","abc","bac","aac","cac"};
string s;
pair<string,int> found[100]={};
int n,k=0;

int build(string s){
    for(int i=0;i<9;++i)if(s==cds[i])return i+1;
    return -1;
}

bool isfind(string q){
    for(int i=0;i<9;++i)if(q==cds[i])return true;
    return false;
}

void solve(){
    int idx=0;
    string cur="";
    while(idx<n){
        cur+=s[idx++];
        if(isfind(cur)){
            found[k].st=cur;
            found[k++].nd=idx;
            cur="";
        }
        else{
            if(k>0&&(idx==n||cur.size()>=3)){
                idx=found[--k].nd;
                cur=found[k].st;
            }
        }
        if(cur.size()>3){
            cout<<-1;
            return;
        }
        //cout<<cur<<' '<<isfind(cur)<<' '<<idx<<endl;
        //for(int i=0;i<k;++i)cout<<found[i].st<<' '<<found[i].nd<<endl;cout<<"\n";
    }
    if(k==0)cout<<-1;
    else for(int i=0;i<k;++i)cout<<build(found[i].st);
    //else for(int i=0;i<k;++i)cout<<found[i].st<<' ';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DECODE.INP","r",stdin);freopen("DECODE.OUT","w",stdout);
    cin>>s;
    n=s.size();
    solve();

    return 0;
}

/******************************************************************************
Link: STRSHIFT
Code: STRSHIFT
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-18-21.08.21
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

string s,t,S[3005],T[3005];

int compare(string&a,string&b){
    int asz=a.size(),bsz=b.size();
    if(asz>bsz)return 1;
    else if(asz<bsz)return -1;

    for(int i=0;i<asz;++i){
        if(a[i]>b[i])return 1;
        else if(a[i]<b[i])return -1;
    }
    return 0;
}

string subtract(string A,string B){
    int cmp=compare(A,B);
    if(cmp==0)return "0";
    else if(cmp==-1){
        swap(A,B);
    }

    int n=A.size(),m=B.size(),nho=0;
    int i=n-1,j=m-1;
    string res="";
    while(i>=0||j>=0||nho){
        int cur=(i>=0?A[i]-'0':0)-(j>=0?B[j]-'0':0)-nho;
        nho=cur<0;
        if(nho)cur+=10;
        res+=cur+'0';
        --i,--j;
    }
    while(res.size()>1&&res.back()=='0')res.pop_back();
    reverse(begin(res),end(res));
    return res;
}

string maxstr(string a,string b){
    if(compare(a,b)==1)return a;
    return b;
}

bool op(string&a,string&b){
    return compare(a,b)==1;
}

int compute(string q,string Q[]){
    int n=q.size(),nsize=0;
    q+=q;
    for(int i=0;i<n;++i){
        if(q[i]=='0'){
            continue;
        }
        Q[nsize++]=q.substr(i,n);
    }
    sort(Q,Q+nsize,op);
    return nsize;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("STRSHIFT.INP","r",stdin);
    freopen("STRSHIFT.OUT","w",stdout);
    cin>>s>>t;

    int ssz=compute(s,S),tsz=compute(t,T);
    cout<<maxstr(subtract(S[0],T[tsz-1]),subtract(S[ssz-1],T[0]));
    return 0;
}

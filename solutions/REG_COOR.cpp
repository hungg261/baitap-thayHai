/******************************************************************************
Link: REG_COOR
Code: REG_COOR
Time (YYYY-MM-DD-hh.mm.ss): 2024-11-13-19.07.46
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

pair<string,int> div2(string S){
    int cur=0,n=S.size();
    string res="";
    for(int i=0;i<n;++i){
        cur=cur*10+S[i]-'0';
        res+=cur/2 +'0';
        cur%=2;
    }
    int pos=0,m=res.size();
    while(pos<m-1&&res[pos]=='0')++pos;
    return {res.substr(pos),cur};
}

string to_bit(string s){
    string res="";
    while(s!="0"){
        auto p=div2(s);
        res+=p.second+'0';
        s=p.first;
    }
    reverse(begin(res),end(res));
    return (res.empty()?"0":res);
}

int compare(const string&A,const string&B){
    int a=A.size(),b=B.size();
    if(a>b)return 1;
    else if(a<b)return -1;

    for(int i=0;i<a;++i){
        if(A[i]>B[i])return 1;
        else if(A[i]<B[i])return -1;
    }
    return 0;
}

string bit_subtract(const string&A,const string&B){
    int cmp=compare(A,B);
    if(cmp==0)return "0";
    else if(cmp==-1)return "-1";

    int n=A.size(),m=B.size(),nho=0;
    int i=n-1,j=m-1;
    string res="";
    while(i>=0||j>=0||nho){
        int cur=(i>=0?A[i]-'0':0)-(j>=0?B[j]-'0':0)-nho;
        nho=cur<0;
        if(nho)cur+=2;
        res+=cur+'0';
        --i,--j;
    }
    while(res.size()>1&&res.back()=='0')res.pop_back();
    reverse(begin(res),end(res));
    return res;
}

string pow2k(int k){
    return "1"+string(k,'0');
}

string range[2][2]={{"t","s"},{"q","r"}};
string solve(int n,string x,string y){
    string pown=pow2k(n-1);
    int cmpx=compare(x,pown),cmpy=compare(y,pown);
    if(cmpx==0||cmpy==0)return "";

    int r=0,c=0;
    if(cmpx==1)
        c=1,x=bit_subtract(x,pown);
    if(cmpy==1)
        r=1,y=bit_subtract(y,pown);

    return range[r][c]+solve(n-1,x,y);

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("REG_COOR.INP","r",stdin);
    freopen("REG_COOR.OUT","w",stdout);
    int n;
    string a,b;
    cin>>n>>a>>b;

    cout<<'t'+solve(n,to_bit(a),to_bit(b));
    return 0;
}

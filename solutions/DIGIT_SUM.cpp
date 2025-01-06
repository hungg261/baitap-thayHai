/******************************************************************************
Link: DIGITS_SUM
Code: DIGITS_SUM
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-28-20.49.32
*******************************************************************************/
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int compare(const string&a, const string&b) {
    if (a.size()!=b.size())return a.size()>b.size()?1:-1;
    return a.compare(b);
}

string add(const string&a, const string&b) {
    string result;
    int carry=0;
    int i=a.size()-1,j=b.size()-1;

    while (i>=0||j>=0||carry){
        int sum=carry;
        if(i>=0)sum+=a[i--]-'0';
        if(j>=0)sum+=b[j--]-'0';
        carry=sum/10;
        result+=sum%10+'0';
    }

    reverse(begin(result),end(result));
    return result;
}

int div9(const string&s){
    int sum=0;
    for(int k:s){
        sum+=k-'0';
    }
    return sum%9;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DIGIT_SUM.INP","r",stdin);
    freopen("DIGIT_SUM.OUT","w",stdout);
    string a,b;
    cin>>a>>b;

    int div=div9(b);
    if(div9(a)==0||div==0||compare(add(a,"9"),b)==-1)cout<<9;
    else{
        for(string i=a;i!=b;i=add(i,"1")){
            div=(div*div9(i))%9;
        }
        cout<<(div%9==0?9:div);
    }

    return 0;
}

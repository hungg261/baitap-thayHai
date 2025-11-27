/******************************************************************************
Link: DIGIT
Code: DIGIT
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-10-19.28.15
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
    credit: none
    template xu li so lon (v1)

    made by hungg_261
*/
typedef string bigint;
namespace BIGINT{
    int compare(const string&a,const string&b){
        if(a.size()!=b.size())return a.size()>b.size()?1:-1;
        return a.compare(b);
    }

    string add(const string&a,const string&b){
        string result;
        int carry=0;
        int i=a.size()-1,j=b.size()-1;

        while(i>=0||j>=0||carry){
            int sum=carry;
            if(i>=0)sum+=a[i--]-'0';
            if(j>=0)sum+=b[j--]-'0';
            carry=sum/10;
            result+=sum%10+'0';
        }

        reverse(begin(result),end(result));
        return result;
    }

    string subtract(string a,string b){
        bool negative=false;
        switch(compare(a,b)){
            case -1:
                swap(a,b);
                negative=true;
                break;
            case 0:
                return "0";
        }

        string result;
        int borrow=0;
        int i=a.size()-1,j=b.size()-1;

        while(i>=0||j>=0||borrow){
            int diff=(i>=0?a[i--]-'0':0)-(j>=0?b[j--]-'0':0)-borrow;
            borrow=diff<0;
            if(borrow)diff+=10;
            result+=diff+'0';
        }

        while(result.size()>1&&result.back()=='0')result.pop_back();
        reverse(result.begin(),result.end());

        if(negative)result='-'+result;
        return result;
    }

    string multiply(const string&a,const string&b){
        vector<int>result(a.size()+b.size(),0);

        for(int i=a.size()-1;i>=0;--i){
            for(int j=b.size()-1;j>=0;--j){
                int mul=(a[i]-'0')*(b[j]-'0');
                int sum=mul+result[i+j+1];
                result[i+j+1]=sum%10;
                result[i+j]+=sum/10;
            }
        }

        string product;
        for(int num:result){
            if(!(product.empty()&&num==0))product+=num+'0';
        }

        return product.empty()?"0":product;
    }

    string divideByTwo(const string &num) {
        string result="";
        int carry=0;

        for(char digit:num){
            int currentDigit=digit - '0';

            int newDigit=currentDigit+carry * 10;
            result+=(newDigit/2)+'0';
            carry=newDigit%2;
        }

        size_t start=result.find_first_not_of('0');
        if(start!=string::npos)result=result.substr(start);
        else result="0";

        return result;
    }

    string divide(const string&a,const string&b){
        if(b=="2"){
            return divideByTwo(a);
        }
        string result,rem;

        for(char digit:a){
            rem+=digit;
            while(rem.size()>1&&rem[0]=='0')rem.erase(0,1);

            int count=0;
            while (compare(rem,b)>=0){
                rem=subtract(rem,b);
                ++count;
            }

            result+=count+'0';
        }

        size_t start=result.find_first_not_of('0');
        if(start!=string::npos)result=result.substr(start);
        else result="0";

        return result;
    }

    string modulo(const string&a,const string&b){
        return subtract(a,multiply(b,divide(a,b)));
    }

    string powmod(string a,string b,string m){
        string res="1";
        a=modulo(a,m);
        while(b!="0"){
            if(b.back()%2==1)res=modulo(multiply(res,a),m);
            a=modulo(multiply(a,a),m);
            b=divide(b,"2");
        }
        return res;
    }

    string power(string a,string b){
        string res="1";
        while(b!="0"){
            if(b.back()%2==1)res=multiply(res,a);
            a=multiply(a,a);
            b=divide(b,"2");
        }
        return res;
    }
}
using namespace BIGINT;

bigint a,b,k;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("DIGIT.INP","r",stdin);
    freopen("DIGIT.OUT","w",stdout);
    cin>>a>>b>>k;

    cout<<divide((multiply(a,powmod("10",subtract(k,"1"),b))+"0"),b).back()<<'\n';;
    return 0;
}

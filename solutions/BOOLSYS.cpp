/******************************************************************************
Link: BOOLSYS
Code: BOOLSYS
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-05-18.09.42
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A)begin(A),end(A)
#define inp(A,n)for(int i=0;i<n;++i)cin>>A[i]
#define int long long
using namespace std;

// module xu li so lon
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

        while (i>=0||j>=0||borrow){
            int diff=(i>=0?a[i--]-'0':0)-(j>=0?b[j--]-'0':0)-borrow;
            borrow=diff<0;
            if(borrow)diff+=10;
            result+=diff+'0';
        }

        while (result.size()>1&&result.back()=='0')result.pop_back();
        reverse(result.begin(),result.end());

        if(negative)result='-'+result;
        return result;
    }

    string multiply(const string&a,const string&b){
        vector<int>result(a.size()+b.size(),0);

        for (int i=a.size()-1;i>=0;--i){
            for (int j=b.size()-1;j>=0;--j){
                int mul=(a[i]-'0')*(b[j]-'0');
                int sum=mul+result[i+j+1];
                result[i+j+1]=sum%10;
                result[i+j]+=sum/10;
            }
        }

        string product;
        for (int num:result){
            if(!(product.empty()&&num==0))product+=num+'0';
        }

        return product.empty()?"0":product;
    }

    string divide(const string&a,const string&b){
        string result,rem;

        for (char digit:a){
            rem+=digit;
            while (rem.size()>1&&rem[0]=='0')rem.erase(0,1);

            int count=0;
            while (compare(rem,b)>=0){
                rem=subtract(rem,b);
                ++count;
            }

            result+=count+'0';
        }

        while (result.size()>1&&result[0]=='0')result.erase(0,1);
        return result.empty()?"0":result;
    }
}

/*
y tuong: de thay,de phuong trinh co nghiem thi ko co bo 3 (x[i],x[i+1],x[x+2])nao la (1,0,1)hoac (0,1,0)
goi dp[i][j] (i= 1->n; j=0|1)la so day bit co do dai i va co tan cung la j sao cho voi j=0 thi day bit i ko chua 010 va voi j=1 thi day bit i ko chua 101
de thay,dp[0][0]=dp[0][1]=1 va dp[1][0]=dp[1][1]=1 (do day con do dai 0 va 1 deu khong chua 010 hoac 101)

xet rieng dp[i][0] <=> neu day bit tai vi tri i ket thuc la 0
=> ta co the ghep no voi day bit do dai i-1 ma ket thuc cung la 0 (do 2 so 0 lien tiep (00)ko bao gio tao ra 010)
=> tuong tu,ta co the ghep no voi day bit do dai i-2 ma ket thuc la 1 (do de ko tao ra 010 thi chi co the la day 110)
=> dp[i][0]=dp[i-1][0]+dp[i-2][1];

tuong tu voi dp[i][1],ta co:
=> dp[i][1]=dp[i-1][1]+dp[i-2][0]

vay ket qua se la dp[n][0]+dp[n][1]

(*)toi uu do phuc tap khong gian:
de thay cac bo nghiem cua phuong trinh luon doi xung nhau (do dieu kien: (!x[i]||x[i+1]||!x[i+2])va (x[i]||!x[i+1]||x[i+2])co tinh doi xung)
=> dp[i][0] va dp[i][1] luon doi xung nhau => dp[i][0]=dp[i][1]
=> cong thuc cho dp[i][0]: dp[i][0]=dp[i-1][0]+dp[i-2][1]=dp[i-1][0]+dp[i-2][0]
=> ko phu thuoc vao dp[i][1] => chi can xet moi dp[i][0]
ket qua se la dp[n][0]+dp[n][1]=dp[n][0]+dp[n][0]=2*dp[n][0] => ko phu thuoc vao dp[n][1]
=> ta chi can khai bao dp[i]
=> cong thuc truy hoi moi se la: dp[i]=dp[i-1]+dp[i-2]
va ket qua la 2*dp[n]
*/

bigint dp[2005];
int k;
using namespace BIGINT;
string solve(){
    int n=k+2;
    dp[0]=dp[1]="1";
    for(int i=2;i<=n;++i){
        dp[i]=add(dp[i-1],dp[i-2]);
    }
    return add(dp[n],dp[n]);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("BOOLSYS.INP","r",stdin);
    freopen("BOOLSYS.OUT","w",stdout);
    cin>>k;
    cout<<solve()<<'\n';

    return 0;
}

/******************************************************************************
Link: HEXA
Code: HEXA
Time (YYYY-MM-DD-hh.mm.ss): 2024-10-15-00.30.06
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

int C[16][16],fact[9]={1},digit_tb[9]={};
bool mark[16];
void compute(){
    for(int i=0;i<=15;++i){
        C[i][0]=1;
    }
    for(int i=1;i<=8;++i){
        fact[i]=fact[i-1]*i;
    }

    for(int i=1;i<=15;++i){
        for(int j=1;j<=15;++j){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    for(int i=1;i<=8;++i){
        digit_tb[i]=15*C[15][i-1]*fact[i-1];
    }
}

char convert(int digit){
    if(digit<=9)
        return digit+'0';
    else return 'A'+digit-10;
}

pair<int,int> getdigit(int n){
    int d=8;
    for(;;){
        int num=15*C[15][d-1]*fact[d-1];
        if(n>num)n-=num;
        else return {d,n};
        --d;
    }
}

void solve(){
    int n;
    cin>>n;
    auto getinf=getdigit(n);
    int pos=digit_tb[getinf.first]-getinf.second+1,curdigit=1,cntdigit=getinf.first;

    while(curdigit<=cntdigit){
        int q=1*C[16-curdigit][cntdigit-curdigit]*fact[cntdigit-curdigit];
        int cur=(pos-1)/q+1;

        if(curdigit==1){
            cout<<convert(cur);
            mark[cur]=true;
        }
        else{
            int cnt=0;
            for(int i=0;i<=15;++i){
                if(!mark[i])++cnt;
                if(cnt==cur){
                    cur=i+1;
                    break;
                }
            }
            cout<<convert(cur-1);
            mark[cur-1]=true;
        }

        pos=(pos-1)%q+1;
        ++curdigit;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//    freopen("HEXA.INP","r",stdin);
//    freopen("HEXA.OUT","w",stdout);
    compute();
    solve();

    return 0;
}

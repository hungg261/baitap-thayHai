/******************************************************************************
Link: ASCII
Code: ASCII
Time (YYYY-MM-DD-hh.mm.ss): 2024-08-13-23.56.48
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

char A[101][101];
bool mark[101][101];
int h,w;
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ASCII.INP","r",stdin);
    freopen("ASCII.OUT","w",stdout);
    cin>>h>>w;

    int cnt=0;
    for(int i=0;i<h;++i)for(int j=0;j<w;++j){
        cin>>A[i][j];
        cnt+=A[i][j]!='.';
    }
    cnt/=2;

    for(int i=0;i<h;++i){
        bool in=0;
        for(int j=0;j<w;++j){
            if(A[i][j]!='.'){
                in=!in;
            }
            else if(in)++cnt,mark[i][j]=1;
        }
    }
    cout<<cnt;
    cout<<'\n';
//    for(int i=0;i<h;++i)for(int j=0;j<w;++j)cout<<mark[i][j]<<" \n"[j==w-1];
    return 0;
}

/* SAMPLE:
8 8
. / \ . . / \ .
/ . . \ / . . \
\ . . . . . . /
/ . . . . . / .
\ . . . . / . .
. \ . . . \ . .
. . \ . . / . .
. . . \ / . . .

-> 34

21 21
. . / \ . . . . . . . . / \ / \ / \ . . .
. / . . \ . . . . . . / . . . . . . \ . .
/ . . . / . . . . . . \ . . . . . . . \ .
\ . . . \ . . . . . . . \ . . . . . . . \
. \ . . / . . . . . . . / . . . . . . . /
. / . / . . . . . . . . \ . . . . . . . \
/ . / . . . . . . . . . . \ . . . . . . /
\ . \ . . . . . . . . . . / . . . . . / .
/ . . \ . . . . . . . . / . . . . . / . .
\ . . . \ . . . . . . / . . . . . / . . .
. \ . . . \ . . . . / . . . . . / . . . .
. . \ . . . \ . . / . . . . . / . . . . .
. . . \ . . . \ / . . . . . / . . . . . .
. . . . \ . . . . . . . . / . . . . . . .
. . . . . \ . . . . . . / . . . . . . . .
. . . . . . \ . . . . / . . . . . . . . .
. . . . . . / . . . . \ . . . . . . . . .
. . . . . / . . . . . / . . . . . . . . .
. . . . . \ . . . . / . . . . . . . . . .
. . . . . . \ . . / . . . . . . . . . . .
. . . . . . . \ / . . . . . . . . . . . .
-> 166

*/

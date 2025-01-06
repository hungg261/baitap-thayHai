#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

char A[6][9];
int mark[100];

struct flag{
    char out[6][9];
} gen[36000];

void compute(){
    string sample="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int idx=0;
    for(int charA=0;charA<26;++charA){
        for(int charB=0;charB<26;++charB){
            for(int charC=0;charC<26;++charC){
                if(charA==charB||charB==charC)continue;

                for(int i=0;i<6;++i){
                    gen[idx].out[i][0]=gen[idx].out[i][1]=gen[idx].out[i][2]=sample[charA];
                    gen[idx].out[i][3]=gen[idx].out[i][4]=gen[idx].out[i][5]=sample[charB];
                    gen[idx].out[i][6]=gen[idx].out[i][7]=gen[idx].out[i][8]=sample[charC];
                }
                ++idx;

                for(int i=0;i<9;++i){
                    gen[idx].out[0][i]=gen[idx].out[1][i]=sample[charA];
                    gen[idx].out[2][i]=gen[idx].out[3][i]=sample[charB];
                    gen[idx].out[4][i]=gen[idx].out[5][i]=sample[charC];
                }
                ++idx;
            }
        }
    }
}

int check(char arr[6][9]){
    int diff=0;
    for(int i=0;i<6;++i){
        for(int j=0;j<9;++j){
            diff+=A[i][j]!=arr[i][j];
        }
    }
    return diff;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("FLAG.INP","r",stdin);
    freopen("FLAG.OUT","w",stdout);
    compute();
    for(int i=0;i<6;++i)for(int j=0;j<9;++j)cin>>A[i][j];

//    cout<<'\n';
    int ans=1e9;
    for(int idx=0;idx<36000;++idx){
        ans=min(ans,check(gen[idx].out));
    }
    cout<<ans;
    return 0;
}

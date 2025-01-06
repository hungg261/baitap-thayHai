/******************************************************************************
Link: GENE
Code: GENE
Time (YYYY-MM-DD-hh.mm.ss): 2024-09-30-19.47.09
*******************************************************************************/
#include<bits/stdc++.h>
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define it(A) begin(A),end(A)
#define inp(A,n) for(int i=0;i<n;++i)cin>>A[i]
using namespace std;

int n,freq[256],curfreq[256];
string s;

bool check(int target){
    return
        freq['A']-curfreq['A']>target ||
        freq['G']-curfreq['G']>target ||
        freq['C']-curfreq['C']>target ||
        freq['T']-curfreq['T']>target;
}

int solve(){
    int target=n/4,i=0,j=0,ans=1e9;
//    if(count(freq,freq+256,target)==4)return 0;
    ++curfreq[s[j]];
    while(i<n&&j<n){
        if(check(target)){
            ++j;
            ++curfreq[s[j]];
        }
        else{
            ans=min(ans,j-i+1);
            --curfreq[s[i]];
            ++i;
        }

//        cout<<i<<' '<<j<<'\n';
//        cout<<freq[s[j]]<<' '<<curfreq[s[j]]<<' '<<i<<' '<<j<<'\n';
//        if(freq[s[j]]-curfreq[s[j]]>target){
//            ++j;
//            ++curfreq[s[j]];
//        }
//        else{
//            if(i<j){
//            --curfreq[s[i]];
//            ++i;
//            }
//            else{
//                ++i,++j;
//                memset(curfreq,0,sizeof(curfreq));
//            }
//        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("GENE.INP","r",stdin);
    freopen("GENE.OUT","w",stdout);
    cin>>n>>s;
    n=s.size();

    for(int k:s)++freq[k];
    cout<<solve();
    return 0;
}

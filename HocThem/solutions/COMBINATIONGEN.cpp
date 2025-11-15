/******************************************************************************
Link: COMBINATIONGEN
Code: COMBINATIONGEN
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-09-18.19.19
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n,m,a[10005];

bool next_combination(int arr[],int len,int n){
    for(int i=len;i>=1;--i){
        if(arr[i]==n-len+i){
            continue;
        }
        else{
            ++arr[i];
            for(int j=i+1;j<=n;++j){
                arr[j]=arr[j-1]+1;
            }
            return true;
        }
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("COMBINATIONGEN.INP","r",stdin);
    freopen("COMBINATIONGEN.OUT","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>a[i];
    }

    if(is_sorted(a+1,a+m+1,less_equal<int>())&&next_combination(a,m,n)){
        for(int i=1;i<=m;++i){
            cout<<a[i]<<' ';
        }
    }
    else cout<<"-1\n";
    return 0;
}

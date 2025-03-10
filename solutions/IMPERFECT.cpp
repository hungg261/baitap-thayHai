/******************************************************************************
Link: IMPERFECT
Code: IMPERFECT
Time (YYYY-MM-DD-hh.mm.ss): 2025-01-06-19.51.32
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAX=1e7;
long long divsum[MAX+5],prefix[MAX+5];

void compute(int high){
    fill(divsum+1,divsum+high+1,1);
    for(int i=2;i<=high;++i){
        if(divsum[i]==1){
            for(int j=i;j<=high;j+=i){
                int temp=j;
                long long total=i;
                while(temp%i==0){
                    temp/=i;
                    total*=i;
                }
                divsum[j]*=(total-1)/(i-1);
            }
        }
    }
    for(int i=1;i<=high;++i){
        prefix[i]=prefix[i-1]+llabs(2*i-divsum[i]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("IMPERFECT.INP","r",stdin);
    freopen("IMPERFECT.OUT","w",stdout);
    int a,b;
    cin>>a>>b;
    compute(b);

    cout<<prefix[b]-prefix[a-1];
    return 0;
}

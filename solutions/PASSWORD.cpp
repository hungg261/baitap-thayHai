/******************************************************************************
Link: PASSWORD
Code: PASSWORD
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-08-21.36.35
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
struct ele{
    int value;
    int sum=0,pos;

    void getsum(){
        int temp=value;
        while(temp>0){
            sum+=temp%10;
            temp/=10;
        }
    }
} a[1000005];

bool op(ele&A,ele&B){
    if(A.sum==B.sum)return A.pos>B.pos;
    return A.sum<B.sum;
}

struct res{
    int value1,value2;
    int diff=1e9;
    int pos1=1e9,pos2=1e9;
} ans;

int tknp(ele arr[],int idx){
    int l=0,h=idx-1,res=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid].sum<arr[idx].sum){
            res=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return res;
}

void solve(){
    sort(a,a+n,op);
    // for(int i=0;i<n;++i)cerr<<a[i].value<<' ';cerr<<'\n';
    for(int i=1;i<n;++i){
        int lowpos=tknp(a,i);
        if(lowpos==-1)continue;

        int diff=a[i].sum-a[lowpos].sum;
        // cerr<<i<<" "<<lowpos<<'\n';
        if(ans.diff>diff){
            ans.diff=diff;

            if(a[lowpos].pos<a[i].pos){
                ans.value1=a[lowpos].value;
                ans.value2=a[i].value;
                ans.pos1=a[lowpos].pos;
                ans.pos2=a[i].pos;
            }
            else{
                ans.value1=a[i].value;
                ans.value2=a[lowpos].value;
                ans.pos1=a[i].pos;
                ans.pos2=a[lowpos].pos;
            }
            // cerr<<diff<<' '<<a[i].value<<' '<<lowpos<<' '<<ans.pos<<'\n';
        }
        else if(ans.diff==diff){
            int minpos=min(a[i].pos,a[lowpos].pos),maxpos=max(a[i].pos,a[lowpos].pos);
            if(ans.pos1==minpos&&ans.pos2<maxpos)continue;
            if(ans.pos1<minpos)continue;

            if(a[lowpos].pos<a[i].pos){
                ans.value1=a[lowpos].value;
                ans.value2=a[i].value;
                ans.pos1=a[lowpos].pos;
                ans.pos2=a[i].pos;
            }
            else{
                ans.value1=a[i].value;
                ans.value2=a[lowpos].value;
                ans.pos1=a[i].pos;
                ans.pos2=a[lowpos].pos;
            }
        }
    }

    cout<<ans.value1<<ans.value2<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PASSWORD.INP","r",stdin);
    freopen("PASSWORD.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].value;
        a[i].pos=i;
        a[i].getsum();
    }

    solve();
    return 0;
}

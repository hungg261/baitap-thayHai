/******************************************************************************
Link: REPORT
Code: REPORT
Time (YYYY-MM-DD-hh.mm.ss): 2024-12-13-21.13.52
*******************************************************************************/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=1e5;
int w,n,m,a[MAX+3],b[MAX+3];

// dem so dong cua moi phan: ben trai/phai (theo arr[])
int countline(int space,int arr[],int len){
    // => bai toan: chia day thanh it nhat cac day con lien tiep sao cho ko day nao co tong >space (space la gia tri mid trong tknp)
    int line=1,sum=0;
    for(int i=1;i<=len;++i){
        if(arr[i]>space)return LLONG_MAX;
        if(sum+arr[i]>space){
            ++line;
            sum=arr[i]+1;
        }
        else sum+=arr[i]+1;
        // (tham lam)
    }

    return line;
}

// ham chat nhi phan:
// goi mid la do rong cua phan ben trai va f(x) la ham dem so dong (f(x)=countline(x)) => so dong cua phan ben phai la f(w-mid)
// ta nhan thay voi x cang nho thi f(x) cang lon (vi do rong cua trang bi thu hep lai nen so dong phai tang len)
// dong thoi, voi x cang nho thi so dong o ben phai la w-x se cang nhieu => f(x) cang lon thi f(w-x) cang nho va nguoc lai
// nhan thay rang, den mot luc nao do thi max(f(mid),f(w-mid) se dat min => ket qua cua bai se la ans=min(ans,max(f(mid),f(w-mid)))
// ta can tim "mot luc nao do".
//
// nhan thay rang, f(x) va f(w-x) nguoc chieu nhau, nghia la x cang lon thi f(x) cang nho va f(w-x) cang lon
// => gtnn cua max(f(x),f(w-x)) co the dat duoc khi khoang cach giua chung la nho nhat, hay |f(x)-f(w-x)| nho nhat
// neu f(mid)<f(w-mid), nghia la ta co the nang f(mid) len de ha f(w-mid) xuong, nham giam khoang cach giua chung => can ha mid xuong
// nguoc lai neu f(mid)>f(w-mid) thi ta tang mid len
//
// o moi lan lap thi ta luu ket qua vao: ans=min(ans,max(f(mid),f(w-mid)))
int tknp(){
    int l=1,h=w-1,ans=LLONG_MAX;
    while(l<=h){
        int mid=(l+h)/2;
        int left=countline(mid,a,n),
            right=countline(w-mid,b,m);

        ans=min(ans,max(left,right));
        if(left<right){
            h=mid-1;
        }
        else if(left>right)l=mid+1;
        else break;
    }
    return ans;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("REPORT.INP","r",stdin);
    freopen("REPORT.OUT","w",stdout);
    cin>>w>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=m;++i){
        cin>>b[i];
    }

    cout<<tknp()<<'\n';
    return 0;
}

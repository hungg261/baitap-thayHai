#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("TRIP.INP","r",stdin);freopen("TRIP.OUT","w",stdout);
    int n,d;
    while(cin>>n>>d){
    int A[n];for(int&k:A)cin>>k;
    sort(A,A+n);

    int l=0,h=n-1,c=0;
    while(l<=h){
        if(A[l]+A[h--]<=d){
            l++;
        }
        c++;
    }
    cout<<c<<endl;
    }
    return 0;
}

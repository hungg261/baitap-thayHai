#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int cy[81]={10,3,5,7,9,11,13,33,35,55,57,77,79,99,101,103,303,305,505,507,707,709,909,911,121,123,323,325,525,527,727,729,929,931,141,143,343,345,545,547,747,749,949,951,161,163,363,365,565,567,767,769,969,971,181,183,383,385,585,587,787,789,989,991,201,104,403,306,605,508,807,710,19,93,41,16,63,38,85,60,8};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SEQUENCE.INP","r",stdin);freopen("SEQUENCE.OUT","w",stdout);
    long long n;
    while(cin>>n)cout<<(n==1?1:cy[(n-1)%81])<<endl;
    return 0;
}
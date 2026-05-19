// BT_HungPhan_03102025
/******************************************************************************
Link: PALINBASE
Code: PALINBASE
Time (YYYY-MM-DD-hh.mm.ss): 2025-04-30-19.44.04
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

bool check_palindrome(string str){
    int len = str.size();
    for(int i = 0; i < len / 2; ++i){
        if(str[i] != str[len - i - 1]) return false;
    }
    return true;
}

char convert_number_to_char(int num){
    if(num <= 9){
        return num + '0';
    }
    return num - 10 + 'A';
}

string convert_to_base(int n, int base){
    string res;
    while(n > 0){
        res.push_back(convert_number_to_char(n % base));
        n /= base;
    }
    return res;
}

void total_check(int n){
    bool found = false;
    for(int base = 2; base <= 16; ++base){
        bool isPalindrome = check_palindrome(convert_to_base(n, base));
        if(isPalindrome){
            if(!found){
                cout << "YES ";
                found = true;
            }
            cout << base << ' ';
        }
    }

    if(!found){
        cout << "NO";
    }

    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("PALINBASE.INP","r",stdin);
    freopen("PALINBASE.OUT","w",stdout);
    int n;
    while(cin >> n){
        if(n == 0) break;

        total_check(n);
    }

    return 0;
}

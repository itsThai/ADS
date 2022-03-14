#include <stdio.h>
#include <iostream>
using namespace std;

int bill(int n, int a, int b, int c, int d, int e, int f){
    if (n == 0){
        cout <<a << " bill $50\n";
        cout <<b << " bill $20\n";
        cout <<c << " bill $10\n";
        cout <<d << " bill $5\n";
        cout <<e << " bill $2\n";
        cout <<f << " bill $1\n";
        return 0;
    }
    else if (n >= 50) {
        return bill( n - 50, a+1 ,b,c,d,e,f);
    }else if (n >= 20) {
        return bill( n - 20,a ,b+1 ,c,d,e,f);
    }else if (n >= 10) {
        return bill( n -10,a,b, c+ 1,d,e,f);
    }else if (n >=5){
        return bill(n - 5,a,b,c, d+1 ,e,f);
    }else if (n >=2){
        return bill(n - 2,a,b,c,d, e+1 ,f);
    }else if (n >=1){
        return bill(n - 1,a,b,c,d,e, f+1) ;
    }
    return 0;
}
int main(){
    int n;
    cout << ("Enter the price: ");
    cin >> n;
    bill(n,0,0,0,0,0,0);
    return 0;
}
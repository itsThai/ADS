#include <stdlib.h>
#include <iostream>

using namespace std;

int i = 0;

int multiply(int a, int b)
{
    if ((a == 0) || ( b == 0)) {
        return 0;
    }else if (b < 0) {
        return (-a + multiply(a, b + 1));
    }
    else {
        return (a + multiply(a, b - 1));
    }
}
int main(){
    int a,b;
    cout << "nhap a,b: ";
    cin >> a >> b;
    cout << "result is: " << multiply(a,b);
}
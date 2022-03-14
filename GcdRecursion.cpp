#include <iostream>

void gcd_recursion(int a, int b) {
    int i = a, j = b;
    if ( j == 0){
        if ( i == 1){
            printf("(%d,%d) ", a,b);
    } else {
        gcd_recursion(j, i % j);
    }
}

int main() {
    int i, j;
    int n = 10;
    int arr[] ={2,10,27,13,90,45,5,26,49,50};
    for (int i = 0; i <= n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            gcd_recursion(arr[i], arr[j]);
        } 
    }
}
#include <iostream>
#include<stdio.h>


void check_coprime(int a, int b) {
    int i;
    int gcd;
    for(i=1; i<=a; i++) {
	    if(a%i==0 && b%i==0) {
	        gcd = i;
	    }
	}
    if (gcd == 1) {
        printf("(%d,%d) ", a,b);
    }
}

int main() {
    int i, j;
    int n = 10;
    int arr[] ={2,10,27,13,90,45,5,26,49,50};
    for (int i = 0; i <= n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            check_coprime(arr[i], arr[j]);
        } 
    }
}
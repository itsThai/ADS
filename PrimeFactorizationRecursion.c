#include<stdio.h>

void prime( int num) {
    int i = 2;
    if(num == 1)
        return;
    while(num%i != 0)
        i++;
    printf("%d ", i);
    prime(num/i);
}

int main( ) {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    prime(num);
    return 0;
}
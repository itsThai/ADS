#include <stdio.h>
#include <stdlib.h>

int main() {
   int n;
   int factorial = 1;
   printf("\n enter the number:");
   scanf("%d", &n);
   int i;
   for (i = 1; i <= n; i++){
        factorial *= i;
   }
   printf("%d! = %d", n, factorial);
}
/*pseudo-code to verify a number is a perfect or not:

int i, n, sum = 0;
enter n
    for(i=1; i<n; i++)
        if(n%i == 0)
            sum += i;
if(sum == n)
    print n is a perfect number
else
    printn is not a perect number

*/
#include <stdio.h>

int main() {
    int n, sum;
    printf("Enter the number:");
    scanf("%d", &n);
    printf("The perfect numbers from 0 to that number are: ");
    int i, j;
    for (i = 1; i <= n; i++) {
        sum = 0;
        for (j = 1; j < i; j++) {
            if ( i % j == 0) 
                sum += j;
        }
        if (sum == i) 
            printf("%d ", i);
    }
}

/* calculate the sum of an array:
a[n]={a1,a2,..,ai};
enter n;
enter values a[i];
int sum;
for (i=0, i<n, i++){
        sum = sum+ a[i];
print sum */


#include <stdio.h>
#include <conio.h> 
void size(int *n){
    printf("\n enter the size of the array:");
    scanf("%d", n);
}
void index(float *a, int n, int i){
    int n;
    printf("Enter each number: ");
    for (i=0; i<n; i++){
        printf("\n a [%d] = ",i);
        scanf("%f", &a[i]);
    }
}
void sum(float a[];,int sum, int n, int i){
    int sum = 0;
    for (i=0, i<n, i++){
        sum = sum+ a[i];
    }
    return sum;
}
void main(){
    int n, *pn;
    float a[];
    clrscr();
    pn=&n;
    size(pn);
    index(a,n);
    sum(a, sum, n, i);
    printf("\n sum of the array is: %d", &sum)
    getch()
}
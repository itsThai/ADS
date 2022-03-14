#include <stdio.h>

void swap(int &x, int &y) {
    int temp;
	temp = x;
    x = y;
	y = temp;
}
int doublebubble(int arr[], int a) { 
    int n, i, m;
    n = a;
    do {
        for (i = 0; i < (n-1); i++) {
            if (arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        n = n - 1;
        for (i = a - 1, m = 0 ;i >= m; i-- ) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        m = m + 1;
    }
    while (n != 0 && m != 0);
    printf("the sorted array is: ");
    for (i = 0; i < a ; i++) {
        printf("%d\t", arr[i]);
    } 
}

int main() {
    int best[] = {1,2,3,4,5}; //complexity O(N)
    printf("\nIn the best case,");
    doublebubble(best,5);

    int worst[] = {5,4,3,2,1}; //complexity O(N^2)
    printf("\nIn the worst case,");
    doublebubble(worst,5);
    
    int average[] = {1,5,3,4,2}; //complexity O(N^2)
    printf("\nIn average case,");
    doublebubble(average,5);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
struct Point {
    int x, y;
};
typedef struct Point Point;
int area (point P1, point P2);
int check (point P1, point P2, point P3);

int main() {
    printf("Enter point 1: ");
    scanf("%d %d", &P1.x, &P1.y);
    printf("Enter point 2: ");
    scanf("%d %d", &P2.x, &P2.y);
    while (P1.x == P2.x || P1.y == P2.y)
    {
        printf("Not an rectangular, re-enter value:\n");
        printf("Enter point 1: ");
        scanf("%d %d", &P1.x, &P1.y);
        printf("Enter point 2: ");
        scanf("%d %d", &P2.x, &P2.y);
    }
    int area;
        int a, b;
        a = abs(P1.x - P2.x);
        b = abs(P1.y - P2.y);
        area = a*b;

    printf("Its area is: %d", &area);

    printf("enter checkpoint: ");
    scanf("%d %d", &P3.x, &P3.y);
    if ( (P1.x <= P3.x && P3.x <= P2.x) && (P1.y <= P3.y && P3.y <= P2.y)
    {
        printf("1"); //in the rectangle
    }
    printf("0"); //not in
}

    



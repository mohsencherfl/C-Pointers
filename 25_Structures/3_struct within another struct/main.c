#include <stdio.h>

typedef struct point {
    int x;
    int y;
} Point;

typedef struct circle {
    Point center;
    double radius;
} Circle;

int main() {

    Point p1 = { 2,7 };
    Circle c1;
    c1.radius = 30.55;
    c1.center = p1;

    printf("Circle 1: \n");
    printf("\t'x' coordinate: %d \n", c1.center.x);
    printf("\t'y' coordinate: %d \n", c1.center.y);
    printf("\tRadius: %.2lf \n", c1.radius);
    c1.center.x = 6;
    c1.center.y = 9;
    c1.radius = 14.81;
    printf("Updated circle 1: \n");
    printf("\t'x' coordinate: %d \n", c1.center.x);
    printf("\t'y' coordinate: %d \n", c1.center.y);
    printf("\tRadius: %.2lf \n", c1.radius);


    Point p2 = { 3,1 };
    Circle c2;
    c2.radius = 18.16;
    c2.center = p2;

    printf("\n------------------------ \n\n");
    printf("Circle 2: \n");
    printf("\t'x' coordinate: %d \n", c2.center.x);
    printf("\t'y' coordinate: %d \n", c2.center.y);
    printf("\tRadius: %.2lf \n", c2.radius);
    c2.center.x = 4;
    c2.center.y = 7;
    c2.radius = 10.31;
    printf("Updated circle 2: \n");
    printf("\t'x' coordinate: %d \n", c2.center.x);
    printf("\t'y' coordinate: %d \n", c2.center.y);
    printf("\tRadius: %.2lf \n", c2.radius);


    return 0;
}

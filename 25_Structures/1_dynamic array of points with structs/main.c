#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {

    Point *p1;
    int totalPoints;

    printf("Enter the total number of points: ");
    scanf("%d", &totalPoints);

    p1 = malloc(sizeof(Point) * totalPoints);

    if(!p1)
        return 1;

    for(int i=0; i<totalPoints; i++)
    {
        printf("Enter point #%d, 'x' coordinate: ", i+1);
        scanf("%d", &p1[i].x);
        printf("Enter point #%d, 'y' coordinate: ", i+1);
        scanf("%d", &p1[i].y);
    }
    for(int i=0; i<totalPoints; i++)
    {
        printf("Point #%d = (%d, %d) \n", i+1, p1[i].x, p1[i].y);
    }

    free(p1);

    return 0;
}


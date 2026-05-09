#include <stdio.h>
#include <stdlib.h>

#include "drone.h"
int main()
{
    int n = 10000;
    Drone *essaim =
        (Drone *)malloc(n * sizeof(Drone));
    for (Drone *p = essaim; p < essaim + n; p++)
    {
        p->id = p - essaim;

        p->x = rand() % 1000;
        p->y = rand() % 1000;
        p->z = rand() % 1000;
    }
    Drone *a = NULL;
    Drone *b = NULL;
    float distanceMin =
        trouverPlusProches(
            essaim,
            n,
            &a,
            &b
        );
    printf("Distance minimale : %f\n", distanceMin);

    printf(
        "Drone A : %d | Drone B : %d\n",
        a->id,
        b->id
    );
    free(essaim);
    return 0;
}
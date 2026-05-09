#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "drone.h"
float calculDistance(Drone *a, Drone *b)
{
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    float dz = a->z - b->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
void trierSelonX(Drone *base, int n)
{
    for (Drone *i = base; i < base + n - 1; i++)
    {
        for (Drone *j = i + 1; j < base + n; j++)
        {
            if (j->x < i->x)
            {
                Drone temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}
static float rechercheBrute(
    Drone *base,
    int n,
    Drone **a,
    Drone **b
)
{
    float min = 1000000;
    for (Drone *i = base; i < base + n; i++)
    {
        for (Drone *j = i + 1; j < base + n; j++)
        {
            float d = calculDistance(i, j);
            if (d < min)
            {
                min = d;

                *a = i;
                *b = j;
            }
        }
    }

    return min;
}
static float rechercheRecursive(
    Drone *base,
    int n,
    Drone **a,
    Drone **b
)
{
    if (n <= 3)
    {
        return rechercheBrute(base, n, a, b);
    }
    int milieu = n / 2;
    Drone *aGauche = NULL;
    Drone *bGauche = NULL;
    Drone *aDroite = NULL;
    Drone *bDroite = NULL;
    float gauche =
        rechercheRecursive(
            base,
            milieu,
            &aGauche,
            &bGauche
        );
    float droite =
        rechercheRecursive(
            base + milieu,
            n - milieu,
            &aDroite,
            &bDroite
        );
    if (gauche < droite)
    {
        *a = aGauche;
        *b = bGauche;
        return gauche;
    }
    *a = aDroite;
    *b = bDroite;
    return droite;
}
float trouverPlusProches(
    Drone *base,
    int n,
    Drone **a,
    Drone **b
)
{
    trierSelonX(base, n);
    return rechercheRecursive(base, n, a, b);
}
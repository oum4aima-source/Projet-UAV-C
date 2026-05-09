#ifndef DRONE_H
#define DRONE_H
typedef struct
{
    int id;
    float x;
    float y;
    float z;
} Drone;
float calculDistance(Drone *a, Drone *b);
void trierSelonX(Drone *base, int n);
float trouverPlusProches(
    Drone *base,
    int n,
    Drone **a,
    Drone **b
);
#endif
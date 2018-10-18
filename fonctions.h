//constantes

#define GEN 50
#define TMPS 100 //en ms
#define NBC 80
#define NBL 80
#define BS 10
#define ECRANL BS * NBC + NBC - 1
#define ECRANH BS * NBL + NBL - 1


// prototypes

void getState(int i, int j, int* etat);

int getProx(int i, int j, int etat, int gridCopy[][NBL]);



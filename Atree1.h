#include<stdlib.h>

//Stucture of BST with array implementation
typedef struct aBST{
	int *A;
	int s;
}aBST;

//typedef node *aBST;

void init(aBST *t);
void insert(aBST *t, int k);

int height(aBST t);
int leafCount(aBST t);
int isComplete(aBST t);
void levelOrder(aBST t);

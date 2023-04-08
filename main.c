#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"Atree1.h"

//main function
int main(){
	aBST t;
	init(&t);
	insert(&t, 10);
	insert(&t, 20);
	insert(&t, 13);
	insert(&t, 1);
	printf("height: %d\n", height(t));
	printf("leaf: %d\n", leafCount(t));
	printf("isComplete: %d\n", isComplete(t));
	printf("LEVEL ORDER TRAVERSAL\n");
	levelOrder(t);
	printf("\n");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"Atree1.h"
#define TRUE 1
#define FALSE 0

//initialize the BST with array implementation
void init(aBST *t){
	t->A = NULL;
	t->s = 0;
	return;
}

//insert an element to the BST
void insert(aBST *t, int k){
  if(t->s == 0){
    //printf("\nEMPTY TREE\n");
    t->A = (int*)malloc(sizeof(int));
    if(!(t->A))
      return;
    t->A[0] = k;
    t->s++;
    return;
  }
  int p = 0;
  while(p < t->s && t->A[p] != -1){
    if(t->A[p] == k)
      return;
    if(t->A[p] > k)
      p = p * 2 + 1;
    else
      p = p * 2 + 2;
  }
  //printf("p = %d, s = %d\n", p, t->s);
  if(p < t->s && t->A[p] == -1){
    t->A[p] = k;
    return;
  }
  t->A = realloc(t->A, (p + 1) * sizeof(int));
  if(!(t->A))
    return;
  for(int i = t->s; i <= p; i++)
    t->A[i] = -1;
  t->s = p + 1;
  t->A[p] = k;
  return;
}

//returns height of the BST
int height(aBST t){
  if(t.A == NULL)
    return -1;
  int i;
  for(i = t.s - 1; i >= 0; i--){
    if(t.A[i] != -1)
      break;
  }
  int index;
  if(t.A[i] != -1){
    index = i;
  }
  int height = 0;
  while(index){
    height++;
    index = (index - 1) / 2;
  }
  return height;
}

////returns the count of leaf nodes in the BST
int leafCount(aBST t){
  if(t.A == NULL)
    return 0;
  if(t.s == 1)
    return 1;
  
  int countLeaf = 0;
  int a = t.s - 1;
  while(a){
    if(t.A[a] != -1){
      if(((a * 2 + 1) >= t.s && (a * 2 + 2) >= t.s) || (t.A[a * 2 + 1] == -1 && t.A[a * 2 + 2] == -1))
        countLeaf++;
    }
    a--;
  }
  return countLeaf;
}

//this returns TRUE if the tree is complete tree, otherwise FALSE
//complete tree is one in which insertion of elements is done from left side the tree
int isComplete(aBST t){
  if(t.A == NULL)
    return TRUE;
  if(t.s == 1)
    return TRUE;
  int p = 0;
  while(p != t.s - 1){
    if(t.A[p] == -1)
      return FALSE;
    p++;
  }
  return TRUE;
}

//this functions prints the level order traversal of the BST
//level order means printing all the nodes of the BST level wise
void levelOrder(aBST t){
  if(t.A == NULL)
    return;
  if(t.s == 1){
    printf("%d\t", t.A[0]);
    return;
  }
  int i = 0, j = 0;
  while(i < t.s){
    while(i <= j){
      if(i < t.s){
        if(t.A[i] != -1)
          printf("%d\t", t.A[i]);
      }
      else
        break;
      i++;
    }
    printf("\n");
    j = j * 2 + 2;
  }
  return;
}

//optimezed version of the Dimaeter Tree
//Time complexity O(n) becoz as we are doing Recursion only one time and calculating
// height using this recursion only.
#include <bits/stdc++.h>
using namespace std;
struct Ntree{
  int data;
  struct Ntree *left;
  struct Ntree *right;
};
struct Ntree* CTree(int data){
  struct Ntree* t=(struct Ntree*)malloc(sizeof(struct Ntree));
  t->data = data;
  t->left=t->right=NULL;
  return(t);
}
// passing height address in this function for calculating height
int diameter1(struct Ntree* root , int *height){
  int ldiameter,rdiameter,lh ,rh=0;
  if(root==NULL){
      *height=0;
      return 0;
    }

   ldiameter = diameter1(root->left,&lh);
   rdiameter= diameter1(root->right, &rh);
  *height=max(lh,rh)+1;

  return max((lh+rh+1),max(ldiameter,rdiameter));
}
int main(){
  struct Ntree* root=CTree(1);
  root->left=CTree(2);
  root->right=CTree(3);
  root->left->left=CTree(4);
  root->left->right=CTree(5);
  root->right->left=CTree(6);
 root->right->right=CTree(7);
 int height =0;
  int diam=diameter1(root, &height);
  printf("DIAMETER IS : %d\n",diam );
  printf("HEIGHT IS : %d\n", height);

  return 0;
}

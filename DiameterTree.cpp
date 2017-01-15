//Diameter of a tree the number of nodes on the longest path between two leaves in the tree.
// for more information go to http://www.geeksforgeeks.org/diameter-of-a-binary-tree/
// time Complexity O(n^2) becoz of 2 times recursion sepeartely calculating
#include <bits/stdc++.h>
using namespace std;

int diameter(struct Ntree* root);
struct Ntree* CTree(int data);
int max(int a, int b);
int height(struct Ntree* root);

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
int max(int a, int b)
{
  return (a >= b)? a: b;
}
int height(struct Ntree *root)
{
  if(root==NULL){
    return 0;
  }
  int lheight=height(root->left);
  int rheight=height(root->right);
  return(max(lheight,rheight)+1);
}
int diameter(struct Ntree *root){
   if(root==NULL){
     return 0;
   }
   // we are calculating height also becoz diameter of a tree can be in the same subtree or through the root .
   int lheight=height(root->left);
   int rheight=height(root->right);

   int ldiam=diameter(root->left);
   int rdiam=diameter(root->right);
   return max((lheight+rheight+1),max(ldiam,rdiam));

}
int main(){
  struct Ntree* root=CTree(1);
  root->left=CTree(2);
  root->right=CTree(3);
  root->left->left=CTree(4);
  root->left->right=CTree(5);
  root->right->left=CTree(6);
 root->right->right=CTree(7);
  int diam=diameter(root);
  printf("%d\n",diam );
  return 0;
}

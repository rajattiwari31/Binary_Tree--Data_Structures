#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};
struct node* CTree(int data){
  struct node* root=(struct node*)malloc(sizeof(struct node));
  root->data=data;
  root->left=root->right=NULL;
  return root;
}
int height(struct node* root){
  if(root==NULL)
      return 0;
  else{
    int leftH = height(root->left);
    int rightH = height(root->right);
    if(leftH>rightH){
      return leftH+1;
    }
    else{return rightH+1;}
    
  }
}
void levelprint(struct node* root , int level)
{
  if(root==NULL)
    return ;
  else if(level == 1)
  {
      printf("%d ", root->data );
  }
  else{
    levelprint(root->left,level-1);
    levelprint(root->right,level-1);
  }
}
void BSTprint(struct node* root)
{
  int h = height(root),i;
  printf("height of the TREE is : %d\n", h);
  for(i=1; i<=h; i++)
    {
      levelprint(root , i);
    }
}

int main(){
  struct node* root=CTree(1);
  root->left=CTree(2);
  root->right=CTree(3);
  root->left->left=CTree(4);
  root->left->right=CTree(5);
  root->right->left=CTree(6);
  root->right->right=CTree(7);
  BSTprint(root);
  return 0;
}

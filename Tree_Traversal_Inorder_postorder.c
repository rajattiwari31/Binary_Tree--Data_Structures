#include <stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};
struct node* createTree(int data) //creating a node
{
  struct node* root=(struct node*)malloc(sizeof(int));
  root->data=data;
  root->left=NULL;
  root->right=NULL;
  return root;
}

void inorder(struct node* root)
{
  if(root==NULL)
     return ;
  inorder(root->left);
  printf("%d" , root->data);
  inorder(root->right);

}
void preorder(struct node* root){
  if(root==NULL) return;
  printf("%d", root->data);
  preorder(root->left);
  preorder(root->right);
}
void postorder(struct node* root)
{
  if(root==NULL)
     return;
  postorder(root->left);
  postorder(root->right);
  printf("%d",root->data);
}
int main()
{
  struct node* root=createTree(1);
  root->left=createTree(2);
  root->right=createTree(3);
  root->left->left=createTree(4);
  root->left->right=createTree(5);
  //root->right->left=createTree(6);
  //root->right->right=createTree(7);
  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
  printf("\n");
  return 0;
}

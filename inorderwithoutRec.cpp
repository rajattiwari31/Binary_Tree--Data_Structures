//Using Stack is the obvious way to traverse tree without recursion.
// below is the ALGORITHM
/*
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/
#include<bits/stdc++.h>
using namespace std;
struct Tnode* createT(int data);
void inorderstack(struct Tnode* root);
void push(struct Snode ** top, struct Tnode* root);
int isEmpty(struct Snode * top);


struct Tnode{
  int data;
  struct Tnode* left;
  struct Tnode* right;
};
struct Tnode* createT(int data){
    struct Tnode* T=(struct Tnode*)malloc(sizeof(struct Tnode));
    T->data=data;
    T->left=T->right=NULL;
    return T;
}
struct Snode{
    struct Tnode* data;
    struct Snode* next;
};
struct Tnode * pop(struct Snode** top_ref){
  if(isEmpty(*top_ref))
    {printf("StAck underflow\n");
     exit(0);}
  else {
      struct Snode* top;
      struct Tnode* res;
      top = *top_ref;
      res = top->data;
      *top_ref= top->next;
      free(top);
      return res;
  }
}

void inorderstack(struct Tnode* root){
    struct Snode* s= NULL;
    struct Tnode* current = root;
    int flag=0;
    while(!flag){
        if(current!=NULL){
          push(&s ,current);
          current = current->left;
        }
        else{
          if(!isEmpty(s))
          {
            current = pop(&s);
            printf("%d  ", current->data);
            current =current->right;
          }
          else
            flag=1;
        }
    }
  }
  void push(struct Snode ** top, struct Tnode* root){
    struct Snode* newnode=(struct Snode*)malloc(sizeof(struct Snode));
    newnode->data=(root);
    newnode->next=(*top);
    *top = newnode;
  }
  int isEmpty(struct Snode * top){
    return (top == NULL)? 1 : 0;
  }

  int main()
  {
    struct Tnode *root = createT(1);
    root->left        = createT(2);
    root->right       = createT(3);
    root->left->left  = createT(4);
    root->left->right = createT(5);

    inorderstack(root);
    printf("\n");
    return 0;
  }

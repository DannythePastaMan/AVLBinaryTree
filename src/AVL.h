#ifndef AVL_H
#define AVL_H

struct Node
{
  int key;
  Node *left;
  Node *right;
  int height;
};

class AVL
{
public:
  int height(Node *);
  Node *rRotation(Node *);
  Node *lRotation(Node *);
  int getBalance(Node *);
  Node *insert(Node *, int);
  Node *newNode(int);
  Node *minimumNode(Node *);
  Node *deleteNode(Node *, int);
};

#endif //AVL_H

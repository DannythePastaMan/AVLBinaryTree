#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <fstream>

struct Node
{
  int key;
  Node *left;
  Node *right;
  int height;
};

struct FileNode
{
  int lChild;
  int value;
  int rChild;
};

class AVL
{
public:
  AVL();
  std::fstream *file;
  FileNode *object;
  int height(Node *);
  Node *rRotation(Node *);
  Node *lRotation(Node *);
  int getBalance(Node *);
  Node *insert(Node *, int);
  Node *newNode(int);
  Node *minimumNode(Node *);
  Node *deleteNode(Node *, int);
  void preOrder(Node *);
  void inOrder(Node *);
  void postOrder(Node *);
  void createFile(char *);
  void saveNodestoFile(char *, int);
  void readFile(char *);
  int getLeftSon(int, Node *);
  int getRightSon(int, Node *);
};

#endif //AVL_H

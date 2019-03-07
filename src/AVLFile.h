#ifndef AVLFILE_H
#define AVLFILE_H

struct FileNode
{
  int lChild;
  int value;
  int rChild;
};

class AVLFile
{
public:
  void createFile();
};

#endif // AVLFILE_H
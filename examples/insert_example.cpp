#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "data_structure.hpp"

using namespace std;
using namespace itis;


int main()
{

  Node *root = NULL;
  string line;
  int keys[10] = {1, 3, 7, 12, 25, 4, 31, 21, 18, 50};

  for(int key : keys){
    root = insert(root, key);
  }

  cout << "Preorder traversal of the "
          "constructed AVL tree is \n";
  preOrder(root);

  return 0;
}

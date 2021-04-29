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
  int keys[5] = {1, 45, 767, 44, 2};

  for(int key : keys){
    root = insert(root, key);
  }
  cout << "Preorder traversal of the "
          "constructed AVL tree is \n";
  preOrder(root);

  root = deleteNode(root, 45);

  cout << "\nPreorder traversal of the "
          "changed AVL tree is \n";
  preOrder(root);




  return 0;
}

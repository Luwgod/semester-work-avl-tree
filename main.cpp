#include <iostream>

#include "data_structure.hpp"

using namespace std;
using namespace itis;

//int main(int argc, char *argv[]) {
//  for (int index = 0; index < argc; index++) {
//    cout << index << ": " << argv[index] << endl;
//  }
//  return 0;
//}


int main()
{
  Node *root = NULL;

  /* Constructing tree given in
  the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  root = insert(root, 27);

  /* The constructed AVL Tree would be
          30
          / \
         20 40
         / \ \
        10 25 50
            \
            27
  */
  cout << "Preorder traversal of the "
          "constructed AVL tree is \n";
  preOrder(root);

  root = deleteNode(root, 40);

  cout << "\nPreorder traversal of the "
          "changed AVL tree is \n";
  preOrder(root);

  cout << "\n" << searchNode(root, 10);
  cout << "\n" << searchNode(root, 40);

  return 0;
}
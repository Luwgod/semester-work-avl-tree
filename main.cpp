#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

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


  string line;
  int key;

  ifstream in("D:\\PycharmProjs\\dataset\\data\\01\\100.csv"); // окрываем файл для чтения
  if (in.is_open())
  {
    while (getline(in, line))
    {
      key = atoi(line.c_str());
      root = insert(root, key);

    }
  }
  in.close();

  cout << "Preorder traversal of the "
          "constructed AVL tree is \n";
  preOrder(root);

  return 0;
}
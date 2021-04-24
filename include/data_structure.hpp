#pragma once
#include "vector"
using namespace std;
// Заголовочный файл с объявлением структуры данных

namespace itis {

  //  inline constexpr auto kStringConstant = "Hello, stranger!";


// Узел АВЛ Дерева
  class Node
  {
   public:
    int key;
    Node *left;
    Node *right;
    int height;
  };


// Вспомогательная функция для нахождения максимума
// из двух чисел
  int max(int a, int b);

  
// Вспомогательная функция для нахождения
// высоты дерева
  int height(Node *N);


/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
  Node* newNode(int key);



// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
  Node *rightRotate(Node *y);



// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
  Node *leftRotate(Node *x);



// Get Balance factor of node N
  int getBalance(Node *N);



// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
  Node* insert(Node* node, int key);


  Node * minValueNode(Node* node);


  Node* deleteNode(Node* root, int key);


  bool searchNode(Node* root, int key);


// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
  void preOrder(Node *root);

  Node* insert_benchmark_func(Node* root, vector<int> keys);

  Node* delete_benchmark_func(Node* root, vector<int> shuffled_keys);

  void search_benchmark_func(Node* root, vector<int> shuffled_keys);

}

#include <iostream>

using namespace std;

template <class T> class Tree;

template <class T>
class TreeNode{
    friend class Tree<T>;
private:
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

template <class T>
class Tree {
public:

private:
    TreeNode<T> *root;
};

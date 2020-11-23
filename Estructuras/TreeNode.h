#ifndef U06_ARBOL_ARBOL_TREENODE_H_
#define U06_ARBOL_ARBOL_TREENODE_H_

template <class T> class TreeNode {
private:
  TreeNode<T> *left, *right;
  T data;
  int height;

public:
  explicit TreeNode(T data) : data(data) {
    left = nullptr;
    right = nullptr;
    height = 0;
  }
  TreeNode() {
    left = nullptr;
    right = nullptr;
    height = 0;
  }

  TreeNode<T> *getLeft() { return left; }
  void setLeft(TreeNode<T> *left) { TreeNode::left = left; }
  TreeNode<T> *getRight() { return right; }
  void setRight(TreeNode<T> *right) { TreeNode::right = right; }
  T &getData() { return data; }
  void setData(T data) { TreeNode::data = data; }
  int getHeight() const { return height; }
  void setHeight(int height) { TreeNode::height = height; }
};

#endif // U06_ARBOL_ARBOL_TREENODE_H_

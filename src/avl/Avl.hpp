#ifndef Avl_Avl_HPP
#define Avl_Avl_HPP

#include "../entity/Product.hpp"
#include <vector>

using Entity::Product, std::max, std::vector;

namespace Avl {

struct Node {
  Product data;
  Node *left;
  Node *right;
  int height;

  Node(Product product)
      : data(product), left(nullptr), right(nullptr), height(1) {}
};

class Avl {
private:
  Node *root;

  int getHeight(Node *node) { return node ? node->height : 0; }

  int getBalance(Node *node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
  }

  Node *rotateRight(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
  }

  Node *rotateLeft(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
  }

  Node *insert(Node *node, Product product) {
    if (!node)
      return new Node(product);

    if (product.name < node->data.name)
      node->left = insert(node->left, product);
    else if (product.name > node->data.name)
      node->right = insert(node->right, product);
    else
      return node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && product.name < node->left->data.name)
      return rotateRight(node);

    if (balance < -1 && product.name > node->right->data.name)
      return rotateLeft(node);

    if (balance > 1 && product.name > node->left->data.name) {
      node->left = rotateLeft(node->left);
      return rotateRight(node);
    }

    if (balance < -1 && product.name < node->right->data.name) {
      node->right = rotateRight(node->right);
      return rotateLeft(node);
    }

    return node;
  }

  Node *getMinValueNode(Node *node) {
    Node *current = node;
    while (current->left)
      current = current->left;
    return current;
  }

  Node *deleteNode(Node *root, string name) {
    if (!root)
      return root;

    if (name < root->data.name)
      root->left = deleteNode(root->left, name);
    else if (name > root->data.name)
      root->right = deleteNode(root->right, name);
    else {
      if (!root->left || !root->right) {
        Node *temp = root->left ? root->left : root->right;

        if (!temp)
          return nullptr;

        *root = *temp;
        delete temp;
      } else {
        Node *temp = getMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.name);
      }
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
      return rotateRight(root);

    if (balance > 1 && getBalance(root->left) < 0) {
      root->left = rotateLeft(root->left);
      return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
      return rotateLeft(root);

    if (balance < -1 && getBalance(root->right) > 0) {
      root->right = rotateRight(root->right);
      return rotateLeft(root);
    }

    return root;
  }

  Node *search(Node *node, string name) {
    if (!node || node->data.name == name)
      return node;

    if (name < node->data.name)
      return search(node->left, name);

    return search(node->right, name);
  }

  void inorder(Node *node, vector<Product *> &result) {
    if (!node)
      return;

    inorder(node->left, result);
    result.push_back(&node->data);
    inorder(node->right, result);
  }

  void preorder(Node *node, vector<Product *> &result) {
    if (!node)
      return;

    result.push_back(&node->data);
    preorder(node->left, result);
    preorder(node->right, result);
  }

  void postorder(Node *node, vector<Product *> &result) {
    if (!node)
      return;

    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(&node->data);
  }

  void searchRangeName(Node *node, const string &prefix,
                       vector<Product *> &result) {
    if (!node)
      return;

    if (node->data.name.find(prefix) == 0)
      result.push_back(&node->data);

    searchRangeName(node->left, prefix, result);
    searchRangeName(node->right, prefix, result);
  }

public:
  Avl() : root(nullptr) {}

  void insert(Product product) { root = insert(root, product); }

  void deleteNode(string name) { root = deleteNode(root, name); }

  Product *search(string name) {
    Node *result = search(root, name);
    return result ? &result->data : nullptr;
  }

  vector<Product *> getInorder() {
    vector<Product *> result;
    inorder(root, result);
    return result;
  }

  vector<Product *> getPreorder() {
    vector<Product *> result;
    preorder(root, result);
    return result;
  }

  vector<Product *> getPostorder() {
    vector<Product *> result;
    postorder(root, result);
    return result;
  }

  vector<Product *> searchRangeName(const string &prefix) {
    vector<Product *> result;
    searchRangeName(root, prefix, result);
    return result;
  }
};

} // namespace Avl
#endif

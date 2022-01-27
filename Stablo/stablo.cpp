#include <iostream>

using namespace std;

struct node{
  int value;
  node* left;
  node* right;

  node(int value) {
    this->value = value;
    this->left = this->right = NULL;
  }
};

node* insertNode(node* root, int value) {
  if (root == NULL) 
        return new node(value); 

  if (value < root->value) {
    root->left = insertNode(root->left, value);
  } else if (value > root->value){
    root->right = insertNode(root->right, value);
  }

  return root;
}

void printBST(const std::string& prefix,node* node, bool isLeft)
{
    if( node != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout << node->value << endl;

        // enter the next tree level - left and right branch
        printBST( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBST( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

struct BST {

  node* root;

  BST();

  BST(node *root) {
    this->root = root;
  };

  void insert(int value) {
    insertNode(this->root, value);
  }

  node* search(int value) { 
    return this->searchBTS(this->root, value);
  }

  node* searchBTS(node* root, int value) { 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->value == value) 
       return root;
     
    // Key is greater than root's key 
    if (root->value < value) 
       return searchBTS(root->right, value); 
  
    // Key is smaller than root's key 
    return searchBTS(root->left, value); 
  }

  void inorder() { 
    printBST("", this->root, false);
  } 
};

int main() {

  // 12, 15, 5, 3, 7, 18 
  node* root = new node(12);
  BST* stablo = new BST(root);

  stablo->insert(15);
  stablo->insert(5);
  stablo->insert(3);
  stablo->insert(7);
  stablo->insert(18);
  stablo->insert(16);
  stablo->insert(14);
  stablo->inorder();
}

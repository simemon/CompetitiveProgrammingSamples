#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void columnPrintHelper(Node* root, int c, map<int,list<int> > &columnMap)
{
  if(root != NULL)
  {
    if(columnMap.find(c) == columnMap.end())
    {
      list<int> temp;
      temp.push_back(root -> data);
      columnMap[c] = temp;
    }
    else
    {
      columnMap[c].push_back(root -> data);
    }
    columnPrintHelper(root -> left, c - 1, columnMap);
    columnPrintHelper(root -> right, c + 1, columnMap);
  }
}

void columnPrint(Node* root)
{
  map<int,list<int> > columnMap;
  int c = 0;
  columnPrintHelper(root, c, columnMap);
  
  for(auto it : columnMap)
  {
    for(auto lit : it.second)
    {
      cout << lit  << " " ;
    }
  }
  cout << endl;
}


// Driver program to test above functions
int main()
{
    Node *root = newNode(6);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    root->left->right = newNode(1);
    root->left->left -> left = newNode(9);
    root->left-> left -> right = newNode(2);
    root->left-> left -> right -> right = newNode(7);
    root->right -> right = newNode(0);
    root->right -> right -> left = newNode(8);
  
    columnPrint(root);   

    return 0;
}

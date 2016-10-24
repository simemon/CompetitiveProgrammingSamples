#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  public:
  int data;
  TreeNode* left, *right;
  TreeNode(int d)
  {
    data = d;
  }
};

TreeNode* createBSTUtil(int left, int right, vector<int> &v)
{
  if(right < left)  return NULL;
  int mid = left + (right - left) / 2 ;
  
  TreeNode* root = new TreeNode(v[mid]);
  root -> left = createBSTUtil(left, mid - 1, v);
  root -> right = createBSTUtil(mid + 1, right , v);
  return root;
}

TreeNode* createBST(vector<int> &v)
{
  return createBSTUtil(0, v.size() - 1, v);
}

void inorder(TreeNode* root)
{
  if(root != NULL)
  {
    inorder(root -> left);
    cout << root -> data << endl;
    inorder(root -> right);
  }
}

int main()
{
  vector<int> v = {-5,10,15,25,56,98,100};
  TreeNode* root = createBST(v);
  
  inorder(root);
  
  return 0;
}
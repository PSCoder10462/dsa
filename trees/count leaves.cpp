int countLeaves(Node* root)
{
  // Your code here
  if (!root) return 0;
  if (!root->left and !root->right) return 1;
  return countLeaves(root->left) + countLeaves(root->right);
}

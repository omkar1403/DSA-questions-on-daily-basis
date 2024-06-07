bool Path_from_root_to_a_given_node(node *root, vector<int>& path, int n)
{
    // if root is NULL
    // there is no path
    if (!root)
       return false;
    

    path.push_back(root->data);

    if (root->data == n)
       return true;
    

    if (Path_from_root_to_a_given_node(root->left, path, n) ||
       Path_from_root_to_a_given_node(root->right, path, n))
       return true;
    
    
    path.pop_back();
    return false;        
}

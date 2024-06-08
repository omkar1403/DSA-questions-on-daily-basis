/*1)children sum property states that ki left and right wale node ka sum same hi hona chahiye root ke value ke sath
2)soo we just traverse and sabko root ki value asign kardi agar eqaul nahi honge to and then we will traverse
soo from after traversal we will asign the sum of left and right node to the root node*/

#include <bits/stdc++.h>
void changeTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    int child = 0;
    if (root->left != NULL)
    {
        child = child + root->left->data;
    }
    if (root->right != NULL)
    {
        child = child + root->right->data;
    }
    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        if (root->right)
        {
            root->right->data = root->data;
        }
    }

    changeTree(root->left);  // here we traverse to the left
    changeTree(root->right); // here we traverse to the right

    int tot = 0;
    if (root->left)
    {
        tot += root->left->data;
    }
    if (root->right)
    {
        tot += root->right->data;
    }
    if (root->left || root->right)
    {
        root->data = tot; // after traversal aur sum karne ke baad we asign the value to the root ka data
    }
}
/**
 here we just did level order traversal but we have assign the values to the array in answer
 by defining an array and then if an odd comes then start from right else start from right
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> output;
        queue<TreeNode *> q;
        if (root == NULL)
        {
            return output;
        }
        q.push(root);
        int j = 0;
        while (!q.empty())
        {
            int n = q.size();

            vector<int> ans(n);

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                int index = (j % 2 == 0) ? i : (n - i - 1);
                ans[index] = node->val;
                q.pop();

                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            output.push_back(ans);
            j++;
        }
        return output;
    }
};
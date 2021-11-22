/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        else{
            if(key > root->val){
                root->right = deleteNode(root->right,key);
            }else if(key < root->val){
                root->left = deleteNode(root->left,key);
            }else{//找到
                //cout << "find\n";
                if(root->left && root->right == NULL){
                    root = root->left;
                }else if(root->left == NULL && root->right){
                    root = root->right;
                }else if(root->left && root->right){//有2個child
                    //找右子樹最小的num
                    int min_num = root->right->val;
                    auto prev = root;
                    auto it = root->right;
                    while(it){
                        if(it->val < min_num)
                            min_num = it->val;
                        if(it->left){
                            prev = it;
                            it = it->left;
                        }else
                            break;
                    }
                    root->val = min_num;
                    
                    
                    if(prev != root){
                        prev->left = it->right;
                    }else{
                        prev->right = it->right;
                    }
                   
                    //root->right = deleteNode(root->right,root->val);
                    
                }else{
                    root = NULL;
                }
            }
        }
        return root;
    }
};

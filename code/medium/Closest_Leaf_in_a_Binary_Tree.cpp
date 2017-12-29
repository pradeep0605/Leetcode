/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode *, int> NodeDistPair;
typedef  unordered_map<TreeNode *, NodeDistPair> ClosestLeafMap;
typedef  unordered_map<TreeNode *, NodeDistPair> ClosestSubtreeLeafMap;
class Solution {
    ClosestSubtreeLeafMap ClosestSubtreeLeafMap_;
    ClosestLeafMap ClosestLeafMap_;
public:
    
    NodeDistPair nearestLeafInSubtree(TreeNode *root) {
        if (root == nullptr) {
            return NodeDistPair(nullptr, INT_MAX);
        }
        
        // use memoized solution.
        if (ClosestSubtreeLeafMap_.find(root) != ClosestSubtreeLeafMap_.end()) {
            return ClosestSubtreeLeafMap_[root];
        }
        
        NodeDistPair left = nearestLeafInSubtree(root->left);
        NodeDistPair right = nearestLeafInSubtree(root->right);
        
        // Root is leaf
        if (left.first == nullptr && right.first == nullptr) {
            // Closest leaf to a leaf node is itself.
            ClosestSubtreeLeafMap_[root] = NodeDistPair(root, 0);
            // Needs 0 traversals to reach leaf
            return ClosestSubtreeLeafMap_[root];
        }
        
        if (left.second < right.second) {
            ClosestSubtreeLeafMap_[root] = NodeDistPair(left.first, left.second + 1);
        } else {
            ClosestSubtreeLeafMap_[root] = NodeDistPair(right.first, right.second + 1);
        }
        return ClosestSubtreeLeafMap_[root];
    }
    // node with the distance
    void __populate_closest_leaf(TreeNode* root, TreeNode *parent) {
        if (root == nullptr) {
            return;
        }
        
        NodeDistPair subtreeClosestLeaf = nearestLeafInSubtree(root);
        
        if (parent != nullptr) {
            if (ClosestLeafMap_.find(parent) != ClosestLeafMap_.end()) {
                NodeDistPair parentsClosestLeaf =  ClosestLeafMap_[parent];
                if (subtreeClosestLeaf.second < (parentsClosestLeaf.second + 1)) {
                    ClosestLeafMap_[root] = subtreeClosestLeaf;
                } else {
                    ClosestLeafMap_[root] = NodeDistPair(parentsClosestLeaf.first, parentsClosestLeaf.second + 1);
                }
            }
        } else {
            ClosestLeafMap_[root] = subtreeClosestLeaf;
        }   
        
        __populate_closest_leaf(root->left, root);
        __populate_closest_leaf(root->right, root);
            
        // cout << "Closest substree leaf is " << subtreeClosestLeaf.first->val << " at a distance " << subtreeClosestLeaf.second << endl;
        return;
    }
    
    int findkNodesClosestLeaf(TreeNode* root, int k) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val == k) {
            return ClosestLeafMap_[root].first->val;
        }
        
        int left = findkNodesClosestLeaf(root->left, k);
        int right = findkNodesClosestLeaf(root->right, k);
        
        if (left != 0) {
            return left;
        } else if (right != 0) {
            return right;
        } else {
            return 0;
        }
    }
    
    int findClosestLeaf(TreeNode* root, int k) {
       __populate_closest_leaf(root, nullptr);
        
        return findkNodesClosestLeaf(root, k);
    }
};
/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    vector<int> res;
public:
    vector<int> postorder(Node* root) {
        post(root);
        return res;
    }

    void post(Node* root)
    {
        if(root)
        {
            for(Node* c : root->children)
                post(c); 
            res.push_back(root->val);
        }
    }
};


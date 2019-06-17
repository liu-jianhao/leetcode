/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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
    vector<int> preorder(Node* root) {
        pre(root);
        return res;
    }

    void pre(Node* root)
    {
        if(root)
        {
            res.push_back(root->val);
            for(Node* c: root->children)
                pre(c);
        }
    }
};


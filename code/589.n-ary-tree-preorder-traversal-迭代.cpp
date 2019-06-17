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
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == nullptr)
            return res;

        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node* cur = s.top();
            s.pop();
            res.push_back(cur->val);

            for(auto it = cur->children.rbegin(); it != cur->children.rend(); it++)
            {
                s.push(*it);
            }
        }

        return res;
    }
};


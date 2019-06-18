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
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == nullptr)
            return res;

        stack<pair<Node*, int>> s;
        s.push(make_pair(root, 0));
        while(!s.empty())
        {
            auto cur = s.top();
            s.pop();

            // 根节点最后插入
            if(cur.second == 1)
            {
                res.push_back(cur.first->val);
                continue;
            }

            // 1说明此时为根节点
            s.push(make_pair(cur.first, 1));
            for(auto it = cur.first->children.rbegin(); it != cur.first->children.rend(); ++it)
            {
                s.push(make_pair(*it, 0));
            }
        }

        return res;
    }
};


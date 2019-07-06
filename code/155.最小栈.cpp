/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(m_min.empty() || x <= m_min.top())
            m_min.push(x);
        m_data.push(x);
    }
    
    void pop() {
        if(m_data.empty())
            return;
        if(m_data.top() == m_min.top())
            m_min.pop();
        m_data.pop();
    }
    
    int top() {
        return m_data.top();
    }
    
    int getMin() {
        return m_min.top(); 
    }

private:
    stack<int> m_data;
    stack<int> m_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


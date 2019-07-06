/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it = m_.find(key);
        if(it == m_.end())
        {
            if(l_.empty() || l_.front().value != 1)
                l_.push_front({1, {key}});
            else
                l_.front().keys.insert(key);
            m_[key] = l_.begin();
            return;
        }

        auto lit = it->second;

        auto nit = next(lit);
        if(nit == l_.end() || nit->value != lit->value + 1)
            nit = l_.insert(nit, {lit->value + 1, {}});
        nit->keys.insert(key);
        m_[key] = nit;

        lit->keys.erase(key);
        if(lit->keys.empty())
            l_.erase(lit);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it = m_.find(key);
        if(it == m_.end())
            return;

        auto lit = it->second;

        if(lit->value > 1)
        {
            auto pit = prev(lit);
            if(lit == l_.begin() || pit->value != lit->value - 1)
                pit = l_.insert(lit, {lit->value - 1, {}});
            pit->keys.insert(key);
            m_[key] = pit;
        }
        else
        {
            m_.erase(key);
        }

        lit->keys.erase(key);
        if(lit->keys.empty())
            l_.erase(lit);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return l_.empty() ? "" : *l_.back().keys.cbegin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return l_.empty() ? "" : *l_.front().keys.cbegin();
    }
private:
    struct Node {
        int value;
        unordered_set<string> keys;
    };
    list<Node> l_;
    unordered_map<string, list<Node>::iterator> m_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */


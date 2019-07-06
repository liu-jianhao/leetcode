/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        auto it = keyMap.find(key);
        int value = -1;
        if(it != keyMap.end())
        {
            value = it->second->second;
            lists.erase(it->second);
            lists.push_front(make_pair(key, value));
            keyMap[key] = lists.begin();
        }
        return value;
    }
    
    void put(int key, int value) {
        auto it = keyMap.find(key);
        if(it != keyMap.end())
        {
            lists.erase(it->second);
            lists.push_front(make_pair(key, value));
            keyMap[key] = lists.begin();
        }
        else if(keyMap.size() < _cap)
        {
            lists.push_front(make_pair(key, value));
            keyMap[key] = lists.begin();
        }
        else
        {
            keyMap.erase(lists.back().first);
            lists.pop_back();
            lists.push_front(make_pair(key, value));
            keyMap[key] = lists.begin();
        }
    }

private:
    int _cap;
    list<pair<int, int>> lists;
    unordered_map<int, list<pair<int, int>>::iterator> keyMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


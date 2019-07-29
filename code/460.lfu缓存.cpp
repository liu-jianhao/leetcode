/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 */
class LFUCache {
public:
    LFUCache(int capacity) : _capacity(capacity), _min_freq(0) {
        
    }
    
    int get(int key) {
        auto it = _n.find(key);
        if(it == _n.end())
            return -1;
        touch(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        if(_capacity == 0)
            return;
        
        auto it = _n.find(key);
        if(it != _n.cend())
        {
            it->second.value = value;
            touch(it->second);
            return;
        }

        if(_n.size() == _capacity)
        {
            const int key_to_evict = _l[_min_freq].back();
            _l[_min_freq].pop_back();
            _n.erase(key_to_evict);
        }

        const int freq = 1;
        _min_freq = freq;

        _l[freq].push_front(key);
        _n[key] = {key, value, freq, _l[freq].cbegin()};
    }

private:
    struct CacheNode {
        int key;
        int value;
        int freq;
        list<int>::const_iterator it;
    };

    void touch(CacheNode& node)
    {
        const int prev_freq = node.freq;
        const int freq = ++(node.freq);

        _l[prev_freq].erase(node.it);

        if(_l[prev_freq].empty() && prev_freq == _min_freq)
        {
            _l.erase(prev_freq);
            ++_min_freq;
        }

        _l[freq].push_front(node.key);

        node.it = _l[freq].cbegin();
    }

    int _capacity;
    int _min_freq;

    // key -> CacheNode
    unordered_map<int, CacheNode> _n;

    // freq -> keys with freq
    unordered_map<int, list<int>> _l;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


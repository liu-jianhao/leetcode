/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
class Solution {
    void move_down(vector<int>& heap, int first, int last)
    {
        int smallest = 2 * first + 1;
        while(smallest <= last)
        {
            if(smallest < last && heap[smallest] > heap[smallest+1])
            {
                smallest = smallest + 1;
            }

            if(heap[first] > heap[smallest])
            {
                swap(heap[first], heap[smallest]);
                first = smallest;
                smallest = 2 * first + 1;
            }
            else
                break;
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap(nums.begin(), nums.begin()+k);
        for(int i = heap.size()/2 - 1; i >= 0; --i)
        {
            move_down(heap, i, heap.size()-1);
        }
        for(int i = k; i < nums.size(); ++i)
        {
            if(nums[i] > heap[0])
            {
                heap[0] = nums[i];
                move_down(heap, 0, heap.size()-1);
            }
        }
        return heap.front();
    }
};


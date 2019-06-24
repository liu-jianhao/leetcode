/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& list, int l, int r)
    {
        if(l > r)
            return nullptr;
        if(l == r)
            return list[l];
        if(l + 1 == r)
            return mergeTwoLists(list[l], list[r]);

        int mid = (r - l) / 2;
        auto l1 = merge(list, mid+1, r);
        auto l2 = merge(list, l, mid);
        return mergeTwoLists(l1, l2);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
                swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }       
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
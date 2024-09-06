// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// #include <map>
// #include <vector>
// #include <algorithm>

// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        std::unordered_set<int> toRemove(nums.begin(), nums.end());

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        ListNode *p = head;
        while (p != nullptr) {
            if (toRemove.find(p->val) == toRemove.end()) {
                temp->next = new ListNode(p->val);
                temp = temp->next;
            }
            p = p->next;
        }
        

        ListNode *newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};

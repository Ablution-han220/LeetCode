/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
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
    bool hasCycle(ListNode *head) {
    //     // (1) hash table  time:O(n) space:O(n)
    //     unordered_set<ListNode*> seen;
    //     while (head != nullptr) {
    //         if (seen.count(head)) {
    //             return true;
    //         }
    //         seen.insert(head);
    //         head = head->next;
    //     }
    //     return false;
    // }
        // (2) Two pointers:Floyd’s Cycle Finding Algorithm time:O(n) space:O(1)
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
// @lc code=end


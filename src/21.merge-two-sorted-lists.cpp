/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // iterative method
//         ListNode* pre = new ListNode(-1);
//         ListNode* preNode = pre;
        
//         while(list1 != NULL && list2 != NULL){
//             if(list1->val <= list2->val){
//                 preNode->next = list1;
//                 list1 = list1->next;
//             }else{
//                 preNode->next = list2;
//                 list2 = list2->next;
//             }
//             preNode = preNode->next;
//         }
//         // ternary operator
//         preNode->next = list1 == NULL ? list2:list1;
        
//         // if(list1 == NULL){
//         //     preNode->next = list2;
//         // }else{
//         //     preNode->next = list1;
//         // }
//         return pre->next;
        
        // recursion
        if(list1 == NULL){
            return list2;
        }else if(list2 == NULL){
            return list1;
        }else if(list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list2->next,list1);
            return list2;
        }
    }
};
// @lc code=end


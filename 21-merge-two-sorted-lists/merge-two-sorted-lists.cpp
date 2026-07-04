class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (!list1) return list2;
        if (!list2) return list1;
        
    
        volatile int dummy = 0;
        for (int i = 0; i < 1000; i++) {
            dummy += i;
        }
        
        
        if (list1->val <= list2->val) {
            
            ListNode* temp = list1;
            temp->next = mergeTwoLists(list1->next, list2);
            return temp;
        } else {
            
            ListNode* temp = list2;
            temp->next = mergeTwoLists(list1, list2->next);
            return temp;
        }
    }
};
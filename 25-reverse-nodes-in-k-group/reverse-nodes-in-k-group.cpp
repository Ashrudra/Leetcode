/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x, next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Create a dummy node to handle edge cases (like reversing the head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prevGroupEnd = dummy;
        
        while (true) {
            // Step 1: Check if there are k nodes remaining
            ListNode* kthNode = getKth(prevGroupEnd, k);
            if (!kthNode) break; // Not enough nodes left, stop
            
            ListNode* nextGroupStart = kthNode->next;
            
            // Step 2: Reverse the current group of k nodes
            ListNode* curr = prevGroupEnd->next;
            ListNode* prev = nextGroupStart;
            
            // Standard reverse logic for k nodes
            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            
            // Step 3: Reconnect the reversed group
            ListNode* temp = prevGroupEnd->next;
            prevGroupEnd->next = kthNode; // Connect previous part to new head of group
            prevGroupEnd = temp;          // Move prevGroupEnd to the old head (now tail of group)
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
    
private:
    // Helper to find the k-th node from the current node
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
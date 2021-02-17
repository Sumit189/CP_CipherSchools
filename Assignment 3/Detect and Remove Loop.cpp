class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    bool isloop = true;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
         if(fast == slow){
          isloop = true;
             break;
        }
      }
      slow = head;
      while(fast !=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            slow->next = NULL;
            break;
        }
    }
    return slow;
    }
};

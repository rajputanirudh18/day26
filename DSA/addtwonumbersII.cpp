class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr!=NULL)
        {
            ListNode* temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tempA = reverse(l1);
        ListNode* tempB = reverse(l2);
        int carry=0;
        ListNode* dummy = new ListNode(-1);
        ListNode* itr=dummy;
        
        while(tempA || tempB || carry){
            int sum=carry+(tempA!=NULL?tempA->val:0)+(tempB!=NULL?tempB->val:0);
            int digit=sum%10;
            itr->next=new ListNode(digit);
            itr=itr->next;
            carry=sum/10;
            if(tempA!=NULL) tempA=tempA->next;
            if(tempB!=NULL) tempB=tempB->next;
        }
        ListNode* ans=reverse(dummy->next);
        return ans;
        
        
        
        
        
        
    }
};
/*See carefully how i used current and other variables that is the main approach of this 
as well read the code of reverse linked list properly
*/


//APPROACH 1(ACCEPTED)

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // Reverse the linked list
        ListNode* reversedList = reverseList(head);
        // Initialize variables to track carry and previous node
        int carry = 0;
        ListNode* current = reversedList, *previous = nullptr;

        // Traverse the reversed linked list
        while (current != nullptr) {
            // Calculate the new value for the current node
            int newValue = current->val * 2 + carry;
            // Update the current node's value
            current->val = newValue % 10;
            // Update carry for the next iteration
            if (newValue > 9) {
                carry = 1;
            } else {
                carry = 0;
            }
            // Move to the next node
            previous = current;
            current = current->next;
        }

        // If there's a carry after the loop, add an extra node
        if (carry != 0) {
            ListNode* extraNode = new ListNode(carry);
            previous->next = extraNode;
        }

        // Reverse the list again to get the original order
        ListNode* result = reverseList(reversedList);

        return result;
    }

    // Method to reverse the linked list
    ListNode* reverseList(ListNode* node) {
        ListNode* previous = nullptr, *current = node, *nextNode;

        // Traverse the original linked list
        while (current != nullptr) {
            // Store the next node
            nextNode = current->next;
            // Reverse the link
            current->next = previous;
            // Move to the next nodes
            previous = current;
            current = nextNode;
        }
        // Previous becomes the new head of the reversed list
        return previous;
    }
};



//APPROACH (PARTIAL ACCEPTED) SEE HOW I USED TO PASS OUT THE POINTER

 ListNode* curr=head;
        int ans=0;
        while(curr!=NULL){
        ans=(ans*10)+(curr->val);
        curr=curr->next;
        }
        int k=2*ans;
        string s=to_string(k);
        ListNode* ans2=new ListNode(0);//how i assigned this
        ListNode* ans1=ans2; //how i pass it through pointer
        for(int i=0;i<s.length();i++){
            int l=s[i]-'0';
            ans1->next=new ListNode(l);
            ans1=ans1->next;
        }
        ListNode* temp=ans2; //also how i delete first element
        temp=temp->next;
      
        return temp;
        



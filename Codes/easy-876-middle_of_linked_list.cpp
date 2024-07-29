// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.



// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

// Example 2:

// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.


class Solution {
	int findsize(ListNode* head){
		int i=0;
		ListNode* temp=head;
		i+=1;
		while(temp!=nullptr){
			temp=temp->next;	i++;
		}
		return i;
	}
public:
    ListNode* middleNode(ListNode* head) {
        int mid=(findsize(head)/2);
        ListNode* temp=head;
        if(findsize(head)%2==0)
        	mid--;
        while(mid!=0){
        	temp=temp->next;
        	mid--;
		}
		return temp;
    }
};

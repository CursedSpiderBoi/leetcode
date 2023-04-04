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

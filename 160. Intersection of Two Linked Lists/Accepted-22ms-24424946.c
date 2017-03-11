// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// 

int getLen(struct ListNode *head)
{
	int len = 0;
	while(NULL != head)
	{
		head = head->next;
		len++;
	}
	return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (NULL == headA || NULL == headB)
    {
    	return NULL;
    }
    int lenA = getLen(headA);
    int lenB = getLen(headB);
    int lenDiff = lenA > lenB ? lenA - lenB : lenB - lenA;
 	if (lenA > lenB)
 	{
 		while(lenDiff--)
	    {
	    	headA = headA->next;
	    }
 	}
 	else
 	{
 		 while(lenDiff--)
	    {
	    	headB = headB->next;
	    }
 	}
 	while(headA != headB)
 	{
 		headA = headA->next;
 		headB = headB->next;
 	}
 	return headA;
}

/*
Write a program to find the node at which the intersection of two singly linked lists begins. For example, the following two linked lists: 
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
 begin to intersect at node c1. Notes: If the two linked lists have no intersection at all, return null. The linked lists must retain their original structure after the function returns. You may assume there are no cycles anywhere in the entire linked structure. Your code should preferably run in O(n) time and use only O(1) memory. Credits: Special thanks to @stellari for adding this problem and creating all test cases. Subscribe to see which companies asked this question. Show Tags Linked List
*/

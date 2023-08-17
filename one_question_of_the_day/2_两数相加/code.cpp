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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int over10 = 0;
        ListNode *l3, *temp;
        l3 = temp = new ListNode();

        while(l1 != nullptr && l2 != nullptr)
        {
            ListNode *insert_node = new ListNode(l1->val + l2->val + over10);
            over10 = 0;

            if(insert_node->val >= 10)
            {
                over10 = 1;
                insert_node->val = insert_node->val%10;
            }

            temp->next = insert_node;
            temp = insert_node;
            l1 = l1->next, l2 = l2->next; 
        }

        while(l1 != nullptr)
        {
            temp->next = l1;
            temp = l1;

            temp->val += over10;
            over10 = 0;

            if(temp->val >= 10)
            {
                temp->val = temp->val%10;
                over10 = 1;
            }

            l1 = l1->next;
        }

        while(l2 != nullptr)
        {
            temp->next = l2;
            temp = l2;

            temp->val += over10;
            over10 = 0;

            if(temp->val >= 10)
            {
                temp->val = temp->val%10;
                over10 = 1;
            }

            l2 = l2->next;
        }

        if(over10)
        {
            ListNode *insert_node = new ListNode(1);
            temp->next = insert_node;
        }

        l3 = l3->next;

        return l3;
    }
};
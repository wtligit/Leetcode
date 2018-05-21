# 2. Add Two Numbers

标签（空格分隔）： Leetcode

---
>You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
**You may assume the two numbers do not contain any leading zero, except the number 0 itself.**

**Example**
Input: `(2 -> 4 -> 3) + (5 -> 6 -> 4)`
Output: `7 -> 0 -> 8`
Explanation: `342 + 465 = 807.`

主要分析`Explanation`，如果两个链表是`2->4->3->3`+`5->6->4`，得到的结果应该是`7->0->8->3`，即`3342+465=3807`。那么在运算的过程中，我们顺着两个链表的顺序来进行按位加和进位，是恰好符号`Explanation`中描述的运算规则的。
此外还要注意链表为空的情况。
```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode pre(0);
        ListNode* p=&pre;
        int carry=0;
        while(l1||l2||carry){
            int sum=(l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry=sum/10;
            p->next=new ListNode(sum%10);
            p=p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return pre.next;
    }
};
```





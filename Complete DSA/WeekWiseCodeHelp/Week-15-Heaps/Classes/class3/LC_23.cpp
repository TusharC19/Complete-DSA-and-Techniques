# include<bits/stdc++.h>
using namespace std; 
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

class compare {
public:
    // star isliye pass kiya kyunki copy nhi lena chahte hai
    // so object copy nhi hua original object hi liya hai
    bool operator()(ListNode* a, ListNode* b) {
        // ye min hep bnata hai
        // bigger element niche hoga and smaller uppar
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        // process first k elements
        // hr list kka phla element process
        int totalrows = arr.size();

        for (int row = 0; row < totalrows; row++) {
            ListNode* list = arr[row];
            ListNode* startptr = list;
            if (startptr != NULL) {
                pq.push(startptr);
            }
        }

        // main logic of processing the data
        while (!pq.empty()) {
            ListNode* front = pq.top();
            pq.pop();
            // insertion cases
            if (head == NULL && tail == NULL) {
                // no elment in list
                head = front;
                tail = front;
            }
            // not needed here
            // else if(head == tail){
            //     // single element
            //     tail->next = front;
            //     tail = front;
            // }
            else {
                tail->next = front;
                tail = front;
            }

            if (tail->next != NULL) {
                ListNode* nextnode = tail->next;
                pq.push(nextnode);
            }
        }

        return head;
    }
};
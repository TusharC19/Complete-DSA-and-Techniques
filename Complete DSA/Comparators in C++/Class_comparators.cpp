# include<bits/stdc++.h>
using namespace std; 

class ListNode{
    public:
        int val;
        ListNode* next;
        
        ListNode(int val){
            this->val=val;
            this->next=NULL;
        }

        void insertNode(int n,ListNode*&head){
            ListNode* temp=head;
            while(temp->next != NULL) temp=temp->next;
            ListNode* node = new ListNode(n);
            temp->next=node;
        }
};


class cmp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto &it : lists) {
            if (it != NULL)
                pq.push(it);
        }

        if (pq.empty()) return NULL;

        ListNode* head = NULL;
        ListNode* temp = NULL;

        while (!pq.empty()) {

            ListNode* top = pq.top();
            pq.pop();

            if (head == NULL) {
                head = top;
                temp = head;
            }
            else {
                temp->next = top;
                temp = temp->next;
            }

            if (top->next != NULL)
                pq.push(top->next);
        }

        return head;
    }
};

int main(){
    
 return 0;
}
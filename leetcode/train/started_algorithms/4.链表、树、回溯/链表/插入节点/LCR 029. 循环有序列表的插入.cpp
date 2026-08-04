/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* cur = head;
        Node* aft = head;
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
        }
        else {
            long long mx = head->val;
            long long mi = head->val;
            cur = cur->next;
            while (cur != head) {
                if (cur->val > mx) {
                    mx = cur->val;
                }
                if (cur->val < mi) {
                    mi = cur->val;
                }
                cur = cur->next;
            }
            while (mi != mx && cur->next->val >= cur->val) {
                cur = cur->next;
            }
            if (insertVal >= mx) {
                aft = cur->next;
                cur->next = new Node(insertVal);
                cur->next->next = aft;
            }
            else if (insertVal <= mi) {
                aft = cur->next;
                cur->next = new Node(insertVal);
                cur->next->next = aft;
            }
            else {
                while (cur->next->val < insertVal) {
                    cur = cur->next;
                }
                aft = cur->next;
                cur->next = new Node(insertVal);
                cur->next->next = aft;
            }
        }
        return head;
    }
};
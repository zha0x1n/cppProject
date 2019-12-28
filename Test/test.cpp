#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int main() {
	ListNode *head = new ListNode(0);
	ListNode *result = head;
	ListNode *sec = new ListNode(1);
	result->next = sec;
        result = result->next;
	if(!head->next) cout << "!" << endl;	
	cout << "head: " << head->val << endl;
	cout << "result: " << result->val << endl;
}

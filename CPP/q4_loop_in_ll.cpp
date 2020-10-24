// C++ program to detect and remove loop in linked list 
#include <bits/stdc++.h> 
using namespace std; 

// Link list node
struct Node { 
	int data; 
	struct Node* next; 
}; 

/* Function to remove loop. 
loop_node --> Pointer to one of the loop nodes 
head --> Pointer to the start node of the linked list */
void removeLoop(struct Node* loop_node, struct Node* head) 
{ 
	struct Node* slow; 
	struct Node* fast; 

	/* Set a pointer to the beginning of the Linked List and 
	move it one by one to find the first node which is 
	part of the Linked List */
	slow = head; 
	while (1) { 
		/* Now start a pointer from loop_node and check if it ever 
	reaches fast */
		fast = loop_node; 
		while (fast->next != loop_node && fast->next != slow) 
			fast = fast->next; 

		/* If fast reahced slow then there is a loop. So break the 
		loop */
		if (fast->next == slow) 
			break; 

		// If fast did't reach slow then try the next node after slow
		slow = slow->next; 
	} 

	/* After the end of loop fast is the last node of the loop. So 
	make next of fast as NULL */
	fast->next = NULL; 
} 

/* This function detects and removes loop in the list 
If loop was there in the list then it returns 1, 
otherwise returns 0 */
int detectAndRemoveLoop(struct Node* list) 
{ 
	struct Node *slow_p = list, *fast_p = list; 

	while (slow_p && fast_p && fast_p->next) { 
		slow_p = slow_p->next; 
		fast_p = fast_p->next->next; 

		/* If slow_p and fast_p meet at some point then there 
		is a loop */
		if (slow_p == fast_p) { 
			removeLoop(slow_p, list); 

			// Return 1 to indicate that loop is found
			return 1; 
		}  
	} 

	// Return 0 to indeciate that ther is no loop
	return 0; 
}

// Function to print linked list
void printList(struct Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

// Driver Code 
int main() 
{ 
	int n, val;
    struct Node* head, temp;
    cout << "Enter number of nodes in the linkedlist: \n";
    cin >> n;

    for(int i=0; i<n; i++) {
        cout << "Enter value: ";
        cin >> val;
        //Check for first node
        if (i == 0) {
            head = new Node();
            head -> data = val;
            head -> next = NULL;
        }
        else {
            //Allocating value of the new pointer to the previous node's next
            temp -> next = new Node();

            //Allocating values to the node
            temp = temp -> next;
            temp -> data = val;
            temp -> next = NULL;
        }
    }

    //Calling the function
	val = detectAndRemoveLoop(head);
    if (val == 0)
        cout << "No loop present in the linkedlist";

	cout << "Linked List after removing loop" << endl; 
    printList(head); 

	return 0; 
} 
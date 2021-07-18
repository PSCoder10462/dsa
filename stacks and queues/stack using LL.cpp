/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

class Stack
{
    //Write your code here
	Node *head, *last;
    int s;
public:
    Stack()
    {
        //Write your code here 
        head = last = nullptr;
    	s = 0;
    }

    int getSize()
    {
        //Write your code here
        return s;
    }

    bool isEmpty()
    {
        //Write your code here 
        return head == nullptr;
    }

    void push(int data)
    {
        //Write your code here
        if (!head) {
            head = new Node (data);
            last = head;
        } else {
            last -> next = new Node (data);
            last = last -> next;
        }
        s++;
    }

    void pop()
    {
        //Write your code here
        if (!head) return;
        s--;
        if (!head->next) { 
            Node *temp = head; 
            head = last = nullptr; 
            delete temp;
            return;
        }
        Node *ptr = head;
        while (ptr ->next != last) ptr = ptr->next;
     	ptr -> next = nullptr;        
        delete last;
        last = ptr;
    }

    int getTop()
    {
        //Write your code here
        return last ? last->data : -1;
    }
};

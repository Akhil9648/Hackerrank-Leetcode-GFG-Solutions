//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node * reverse(Node *num)
    {
        Node*curr=NULL;
        Node *prev=num;
        Node*ptr=num;
        while(ptr)
        {
            ptr=prev->next;
            prev->next=curr;
            curr=prev;
            prev=ptr;
        }
        return curr;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        int carry=0;
        num1=reverse(num1);
        num2=reverse(num2);
        Node *list=new Node(0);
        Node *ans=list;
        while(num1 || num2 || carry)
        {
            int sum=0;
            if(num1!=NULL)
            {
                sum+=num1->data;
                num1=num1->next;
            }
            if(num2!=NULL)
            {
                sum+=num2->data;
                num2=num2->next;
            }
            sum+=carry;
            carry=sum/10;
            ans->data=(sum%10);
            if(num1 || num2 || carry)
            {
                ans->next=new Node(0);
                ans=ans->next;
            }
        }
        reverse(list);
        while(ans->data==0 && ans->next)
        {
            ans=ans->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends

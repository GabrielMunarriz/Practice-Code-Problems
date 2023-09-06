#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

//custom findLength function
int findLength(SinglyLinkedListNode* node) {
    
    SinglyLinkedListNode* temp;
    temp = node;
    int length = 0;
    
    while (temp) {
        
        length++;
        //cout << length << endl;
        temp = temp->next;
        
    }
    
    return length;
    
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
 
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    //assign currentLong and currentShort based on list length.
    //we want to find the mergepoint by iterating through the entire currentLong list for each element of currentShort
    
    bool breakFlag = false;
    SinglyLinkedListNode* currentLong;
    SinglyLinkedListNode* currentLongAnchor;
    SinglyLinkedListNode* currentShort;
    SinglyLinkedListNode* mergePoint;
    
    if (findLength(head1) > findLength(head2)) {
        
        currentLong = head1;
        currentLongAnchor = head1;
        currentShort = head2;
        
    } else {
        
        currentLong = head2;
        currentLongAnchor = head2;
        currentShort = head1;
        
    }
    
    mergePoint = nullptr;

    //We only need to iterate until 2nd to the last element.
    
    //Edits: current2 here needs to be the shorter list. current 1 needs to be the longer list.
    while (currentShort->next) {
        
        while (currentLong->next) {
        
            if (currentLong->next == currentShort->next) {
                
                mergePoint = currentLong->next;
                breakFlag = true;
                break;
                
            } else {
                
                currentLong = currentLong->next;
                
            }
            
        }
        
        if (breakFlag) {
            
            break;
            
        } else {
            
            currentLongAnchor = currentLongAnchor->next;
            currentLong = currentLongAnchor;
            currentShort = currentShort->next;
            
        }
        
    }
    
    return mergePoint->data;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }
      
      	SinglyLinkedListNode* ptr1 = llist1->head;
      	SinglyLinkedListNode* ptr2 = llist2->head;
      
      	for (int i = 0; i < llist1_count; i++) {
            if (i < index) {
          		ptr1 = ptr1->next;
            }
        }
      
      	for (int i = 0; i < llist2_count; i++) {
          	if (i != llist2_count-1) {
          		ptr2 = ptr2->next;
            }
        }
      
      	ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

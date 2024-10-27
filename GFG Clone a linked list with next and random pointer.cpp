

// T.C = O(N) AND S.C == O(N)
class Solution {
    
    private:
        void insertAtTail(Node*& head , Node*& tail ,int d){
            Node* temp = new Node(d);
            if(head==NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next  = temp;
                tail = temp;
            }
        }
    
  public:
    Node *copyList(Node *head) {
        // Write your code here
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
            
        }
        
        unordered_map<Node*,Node*>map;
        Node* original = head;
        Node* clone = cloneHead;
        while(original!=NULL && clone!=NULL){
            map[original] = clone;
            clone = clone->next;
            original = original->next;
            
        }
        
        original = head;
        clone = cloneHead;
        while(original!=NULL){
            clone->random = map[original->random];
            clone = clone->next;
            original = original->next;
            
        }
        
        return cloneHead;
        
        
        
    }






// best approach T.C == O(N) && S.C == O(1)

class Solution {
    private:
        void insertAtTail(Node* &head, Node*&tail , int d){
            Node* newnode = new Node(d);
            if(head==NULL){
                head = newnode;
                tail = newnode;
            }
            else{
                tail->next = newnode;
                tail = newnode;
            }
        }
        
        
  public:
    Node *copyList(Node *head) {
        // Write your code here
        //step1
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }
        
        // step2 : add karni thi nodes
        Node* original = head;
        Node* clone = cloneHead;
        while(original!=NULL){
            Node* next1 = original->next;
            original->next = clone;
            original = next1;
            
            next1 = clone->next;
            clone->next = original;
            clone = next1;
            
        }
        
        // step3
        original = head;
        clone = cloneHead;
        
        while(original!=NULL && clone!=NULL){
            if(original->random !=NULL){
                clone->random = original->random->next;
                
            }
            else{
                clone->random = NULL;
            }
            clone = clone->next;
            original = original->next;
        }
        
        // step4
        original = head;
        clone = cloneHead;
        while(original!=NULL && clone!=NULL){
            original->next = original->next?original->next->next:original->next;
               
            clone->next = clone->next?clone->next->next:clone->next;
            
            
            clone = clone->next;
            original = original->next;
            
        }
        
        // step5
        return cloneHead;
        
        
    }

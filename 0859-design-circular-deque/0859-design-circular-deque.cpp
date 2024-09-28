struct doubleLinkedList{
    int val;
    doubleLinkedList *prev,*next;
    doubleLinkedList(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};
class MyCircularDeque {
    // vector<int> v;
    int front,rear,k,cnt=0;
    doubleLinkedList *head,*tail;
public:
    MyCircularDeque(int k){
        this->k=k;
        cnt=0;
    }

    bool insertFront(int value) {
    if(cnt==k){
        return false;
    }
    doubleLinkedList *node=new doubleLinkedList(value);
    if(cnt==0){
        head=node;
        tail=node;
    }
    else{
        head->prev=node;
        node->next=head;
        head=node;
    }
    cnt++;
    return 1;
    }
    
    bool insertLast(int value) {
        if(cnt==k)
        return 0;
         doubleLinkedList *node=new doubleLinkedList(value);
        if(cnt==0){ 
            head=node;
        tail=node;

        }
        else{
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
        cnt++;
return 1; 
    }
    
    bool deleteFront() {
        if(cnt==0)
        return 0;
        auto *temp=head;
        head=head->next;
        if(head) head->prev=NULL;
        delete temp;
        cnt--;
        return 1;
    }
    
    bool deleteLast() {
        if(cnt==0)
        return 0;
        auto *temp=tail;
        tail=tail->prev;
        if(tail)
        tail->next=NULL;
        delete temp;
        cnt--;
        return 1;
    }
    
    int getFront() {
        if(cnt==0)
        return -1;
       return head->val;
    }
    
    int getRear() {
     if(cnt==0)
     return -1;
     return tail->val;   
    }
    
    bool isEmpty() {
        if(cnt==0)
        return 1;
        return 0;
    }
    
    bool isFull() {
        if(cnt==k)
        return 1;
        return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
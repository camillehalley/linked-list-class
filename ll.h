#include <iostream>


namespace CS270 {
template<class T>
class forward_list {

  class Node { 
   public:
    Node(const T& v) : val(v), next(NULL) {}
    T& getVal() { return val; }
    Node* getNext() { return next; }
    void setNext(Node* ptr) { next = ptr; }
   private:
    T val;
    Node* next;
  };

 public:
  T& front() {return head->getVal();} //Return the item at the front of the list
  const T& front() const {return head->getVal();} //Const version
    
  void push_front(const T& toInsert) {
    Node* newNode = new Node(toInsert);
    newNode->setNext(head);
    head = newNode;
  } //Add a new item to the front

  bool empty() {
    return (head == NULL);
  } //Is the list empty?
  //Assume that this function is not called on an empty list
  void pop_front() {
    Node* toDelete = head;
    head = head->getNext();
    delete toDelete;
  } //Removing item at the front
  //Function to remove all instances of a value from the list
  void remove(const T& val) {
    Node* previous = NULL;
    Node* current = head;
    //while the list is not empty
    while(current != NULL) {
      //if the current value is the value to be removed
      if (current->getVal() == val) {
        Node* toDelete = current;
        //if previous is null, we cannot set the next of previous
        if (previous==NULL){
            //set head to the next of current
            head = current->getNext();
        //if previous is not null
        } else {
            //set previous to the next of current
            previous->setNext(current->getNext());
        }
        //current equals node after the one to be deleted
        current = current->getNext();
        //delete the node to be deleted, nothing else should 
        //point to it now
        delete toDelete;
      } else { //if the current value does not need to be removed
        //move on to the next one
        previous = current;
        current = current->getNext();
      }   
    }
  }
    
  void merge(forward_list<int>& second){
    //current will be the value that we compare with the value of the second list
    Node* current = head;
    //iterator1 will be a pointer that goes through and points to the appropriate node depending on our comparison
    Node* iterator1 = head;
    //iterator2 will be the value that we compare with the value of the first list
    Node* iterator2 = second.head;
    //set current to be the nest value after head
    if (current != NULL){
        current = current->getNext();
    }
    //go through until there is one value left in list1 and no values left in list2
    while((current != NULL) && (iterator2 != NULL)) {
        if (current->getVal() <= iterator2->getVal()) {
            //point the value of it1's next to the next smallest value
            iterator1->setNext(current);
            //advance current
            current = current->getNext();
            //advance it1
            iterator1 = iterator1->getNext();
        } else { 
            //point value of it1's next to next smallest value
            iterator1->setNext(iterator2);
            //advance it2
            iterator2 = iterator2->getNext();
            //advance it1
            iterator1 = iterator1->getNext();
        }
    }
    //if list one is empty, it becomes list2
    if (current==NULL && iterator1==NULL){
        head = second.head;
    //else if there is one value left in list one, point it1's next to it2
    } else if(current==NULL){
        iterator1->setNext(iterator2);
    }
    //if both lists are empty, do nothing  
    if(iterator2==NULL && current==NULL){}
    //else if there are no values left in list 2 but still in list1, point it1's next //to current
    else if (iterator2==NULL){ 
        iterator1->setNext(current);
    }  
    second.head = NULL;
 }

  forward_list() : head(NULL) { }; //Constructor
  ~forward_list() {
      while (head != NULL){
          Node* temp = head;
          head = head->getNext();
          delete temp;    
      } 
  } //Destructor

 private:
  Node* head;
    
};
}


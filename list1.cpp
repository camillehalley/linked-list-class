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
    while(current != NULL) {
      if (current->getVal() == val) {
        previous->setNext(current->getNext());
      } else {
        previous = current;
      }
      current = current->getNext();
    }
  }


  forward_list() : head(NULL) { }; //Constructor
  ~forward_list() {}; //Destructor

 private:
  Node* head;
};

}

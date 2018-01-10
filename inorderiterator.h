#ifndef CS270_INORDER_ITERATOR
#define CS270_INORDER_ITERATOR
#include <iostream>
#include "binary_tree.h"

template<class Pos, class T>
class InOrderIterator :  std::iterator< std::forward_iterator_tag, T > {
 public:
  InOrderIterator(Pos pos) : current(pos) {
    //The first position to be visited is the leftmost descendent of the root position
    while (current.isValid() && current.left().isValid()) {
      current = current.left();
    }
  }

  // Go to next location
  InOrderIterator& operator++() { 
    //Precondition: the current node has been visited
    //Rules for advancement:
    //  If the current node has a right child, the next node to visit is the leftmost 
    //    descendent of the right child.
    //  Otherwise, the next node to visit is the first ancestor whose left subtree contains 
    //    the current node, or an invalid position if there is none.
      
    if(current.right().isValid()){
        current = current.right();
        while (current.isValid() && current.left().isValid()) {
          current = current.left();
        }
    }
      
    else{
        if((current.parent().right() == current) && current.right().isValid()){
            current = current.parent().parent();
            if(current.right().isValid()){
                current = current.right();
                while (current.isValid() && current.left().isValid()) {
                    current = current.left();
                }
            }
        }
        if((current.parent().right() == current) && (!current.right().isValid())){
            while(*current.parent() < *current){
                current = current.parent();
            }
            if(!current.isRoot()){
            current = current.parent();}
        }
        else{
            current = current.parent();
        }
    }
    return *this;
  }

  //Comparisons
  bool operator!=(const InOrderIterator& other) {
//      if(*this == other){
//          return false;
//      }
//      else{return true;}

  } 
  bool operator==(const InOrderIterator& other) {
//      if(*this == other){
//          return true;
//      }
//      else{return false;}

  }
  T& operator*() {

  } //Dereference
 private:
  Pos current;
};

#endif
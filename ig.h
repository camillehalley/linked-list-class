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

   if (current.right() != NULL)
     {
      // successor is the furthest left node of
      // right subtree
      current = current().right();
     
      while (current().left().isValid()) {
        current = current.left();
        }
     }
   else
     {
       // have already processed the left subtree, and
       // there is no right subtree. move up the tree,
       // looking for a parent for which nodePtr is a left child,
       // stopping if the parent becomes NULL. a non-NULL parent
       // is the successor. if parent is NULL, the original node
       // was the last node inorder, and its successor
       // is the end of the list
       current = current.parent();
       while (current.isValid() &&  == p->right)
         {
           nodePtr = p;
           p = p->parent;
         }
       
       // if we were previously at the right-most node in
       // the tree, nodePtr = NULL, and the iterator specifies
       // the end of the list
       nodePtr = p;
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
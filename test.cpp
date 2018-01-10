#include "ll.h"
#include <forward_list>
#include <gtest/gtest.h>

//Test file for our linked list


//To test our linked list class, use this line to search for classes in the CS270 namespace
//using namespace CS270;
//To test your test cases, use this line to search for classes in the std namespace
using namespace CS270;

TEST(SLL, constructor) {
  //Empty constructors only - passes if it doesn't crash
  forward_list<int> intlist;
  forward_list<float> floatlist;
}

TEST(SLL, front_and_push) {
  forward_list<int> list;
    //size 1
  list.push_front(0);
  EXPECT_EQ(0, list.front());
    //size 2
  list.push_front(1);
  EXPECT_EQ(1, list.front());
    //size 3
  list.push_front(2);
  EXPECT_EQ(2, list.front());
  
}

TEST(SLL, pop) {
  //size 4
  forward_list<int> list;
  list.push_front(0);
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  EXPECT_EQ(3, list.front());
  list.pop_front();
  //size 3
  EXPECT_EQ(2, list.front());
  list.pop_front();
  //size 2
  EXPECT_EQ(1, list.front());
  list.pop_front();
  //size 1
  EXPECT_EQ(0, list.front()); 
}

TEST(SLL, empty) {
  forward_list<int> list;
  //Empty
  EXPECT_EQ(true, list.empty());
  //Size 1
  list.push_front(0);
  EXPECT_EQ(false, list.empty());
  //Size 2
  list.push_front(1);
  EXPECT_EQ(false, list.empty());

  //Size 3
  list.push_front(2);
  EXPECT_EQ(false, list.empty());
  //Size 2
  list.pop_front();
  EXPECT_EQ(false, list.empty());
  //Size 1
  list.pop_front();
  EXPECT_EQ(false, list.empty());
  //Empty again
  list.pop_front();
  EXPECT_EQ(true, list.empty());
}

TEST(SLL, remove) {
  //list of size 3, removing one of the values
  forward_list<int> list;
  list.push_front(0);
  list.push_front(1);
  list.push_front(2);
  list.remove(1);
  EXPECT_EQ(2, list.front());
  list.pop_front();
  ASSERT_EQ(false, list.empty());
  EXPECT_EQ(0, list.front());
  list.pop_front();
  EXPECT_EQ(true, list.empty());
    
  //list of size one    
  forward_list<int> list2;
  list2.push_front(4);
  list2.remove(4);
  EXPECT_EQ(true, list2.empty());
    
  //list of size 5, multiple copies of value to be removed
  forward_list<int> list3;
  list3.push_front(0);
  list3.push_front(1);
  list3.push_front(1);
  list3.push_front(2);
  list3.push_front(1);
  list3.remove(1);
  EXPECT_EQ(2, list3.front());
  list3.pop_front();
  ASSERT_EQ(false, list3.empty());
  EXPECT_EQ(0, list3.front());
  list3.pop_front();
  EXPECT_EQ(true, list3.empty());
}

TEST(SLL, merge){
    //two lists of the same size
    forward_list<int> list;
        list.push_front(42);
        list.push_front(23);
        list.push_front(6);
        list.push_front(3);
        list.push_front(1);

    
    forward_list<int> list2;
        list2.push_front(42);
        list2.push_front(37);
        list2.push_front(25);
        list2.push_front(20);
        list2.push_front(8);

       
    list.merge(list2);
    EXPECT_TRUE(list2.empty());
    int length_list= 0;
    
    while(!(list.empty())){
        length_list++;
        int temp = list.front();
        list.pop_front();

        if(!(list.empty())){
            EXPECT_TRUE(temp<=list.front());
        }
    }
    
    //two lists of different sizes
    forward_list<int> list3;
    
    list3.push_front(11);
    list3.push_front(9);
    list3.push_front(3);

    forward_list<int> list4;
    list4.push_front(12);
    list4.push_front(4);
   
    list3.merge(list4);
    EXPECT_TRUE(list4.empty());
    int length_list2= 0;
    
    while(!(list3.empty())){
        length_list2+=1;
        int temp = list3.front();
        list3.pop_front();
        if(!(list.empty())){
        EXPECT_TRUE(temp<=list3.front());}
    }
    
    //one empty list and one not empty list
    //two empty lists
    
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
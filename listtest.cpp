#include "ll.h"
#include <forward_list>
#include <gtest/gtest.h>

//Test file for our linked list


//To test our linked list class, use this line to search for classes in the CS270 namespace
using namespace CS270;
//To test your test cases, use this line to search for classes in the std namespace
//using namespace std;

TEST(SLL, constructor) {
  //Empty constructors only - passes if it doesn't crash
  forward_list<int> intlist;
  forward_list<float> floatlist;
}

TEST(SLL, front_and_push) {
  forward_list<int> list;
  list.push_front(0);
  EXPECT_EQ(0, list.front());
  list.push_front(1);
  EXPECT_EQ(1, list.front());
}

TEST(SLL, pop) {
  forward_list<int> list;
  list.push_front(0);
  list.push_front(1);
  list.push_front(2);
  EXPECT_EQ(2, list.front());
  list.pop_front();
  EXPECT_EQ(1, list.front());
  list.pop_front();
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
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
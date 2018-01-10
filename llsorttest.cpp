#include "ll.h"
#include <gtest/gtest.h>

//Test file for our linked list
using namespace CS270;

TEST(LLSort, simple) {
  LL<int> list;
  list.push_front(4);
  list.push_front(2);
  list.push_front(3);
  list.push_front(1);
  list.push_front(5);
  list.sort();
  for (int i = 1; i <= 5; i++) {
    ASSERT_FALSE(list.empty());
    ASSERT_EQ(i, list.front());
    list.pop_front();
  }

}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
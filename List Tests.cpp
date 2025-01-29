#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_List_default_ctor) {
    List<int> list;
    ASSERT_TRUE(list.empty());
}

TEST(test_List_copy_ctor) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    List<int> list2(list);
    ASSERT_TRUE(true);
}

TEST(test_List_empty) {
    List<int> list;
    ASSERT_TRUE(list.empty());

    List<int> list2;
    list2.push_back(2);
    ASSERT_FALSE(list2.empty());
}

TEST(test_List_size) {
    List<int> list;
    ASSERT_EQUAL(0, list.size());
    list.push_back(0);
    list.push_back(2);
    ASSERT_EQUAL(2, list.size());
}

TEST(test_List_front) {
    List<int> list;
    list.push_back(1);
    ASSERT_EQUAL(1, list.front());
    list.push_back(2);
    ASSERT_EQUAL(1, list.front());
}

TEST(test_List_back) {
    List<int> list;
    list.push_back(0);
    ASSERT_EQUAL(0, list.back());
    list.push_back(3);
    ASSERT_EQUAL(3, list.back());
}

TEST(test_List_default_ctor2) {
    List<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

// Test push_back and size increment
TEST(test_List_push_back) {
    List<int> list;
    list.push_back(10);
    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 10);
    ASSERT_EQUAL(list.back(), 10);
}

TEST(test_List_push_back2) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 10);
    ASSERT_EQUAL(list.back(), 20);
}

TEST(test_List_push_front) {
    List<int> list;
    list.push_front(10);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 10);
    ASSERT_EQUAL(list.back(), 10);
    list.push_front(20);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 20);
    ASSERT_EQUAL(list.back(), 10);
}

TEST(test_List_pop_front) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 20);
}

TEST(test_List_pop_front3) {
    List<int> list;
    list.push_back(10);
    list.pop_front();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_List_pop_back3) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.back(), 10);
}

TEST(test_List_pop_back) {
    List<int> list;
    list.push_back(10);
    list.pop_back();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_List_copy_ctor2) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    List<int> copy(list);
    ASSERT_EQUAL(copy.size(), 2);
    ASSERT_EQUAL(copy.front(), 10);
    ASSERT_EQUAL(copy.back(), 20);
}



// Test push_front and size increment
TEST(test_List_push_front2) {
    List<int> list;
    list.push_back(10);
    list.push_front(5);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 5);
    ASSERT_EQUAL(list.back(), 10);
}

// Test pop_back and correct element removal
TEST(test_List_pop_back2) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.back(), 10);
}

// Test pop_front and correct element removal
TEST(test_List_pop_front2) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 20);
}

// Test clear method and emptiness
TEST(test_List_clear) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);

    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);

    List<int> list2;
    list.push_back(10);
    list.clear();
    ASSERT_TRUE(list2.empty());
    ASSERT_EQUAL(list2.size(), 0);
}

TEST(test_List_empty_ctor) {
    List<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}

// Test copy constructor with a list
TEST(test_List_copy_ctor3) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    List<int> copied_list(list);
    ASSERT_EQUAL(copied_list.size(), 2);
    ASSERT_EQUAL(copied_list.front(), 10);
    ASSERT_EQUAL(copied_list.back(), 20);
}

// Test assignment operator
TEST(test_List_assignment_operator) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    List<int> assigned_list;
    assigned_list = list;
    ASSERT_EQUAL(assigned_list.size(), 2);
    ASSERT_EQUAL(assigned_list.front(), 10);
    ASSERT_EQUAL(assigned_list.back(), 20);
}

TEST(test_List_assignment_operator2) {
    List<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    List<int> list2;
    list2 = list1;
    ASSERT_EQUAL(list2.size(), 2);
    ASSERT_EQUAL(list2.front(), 10);
    ASSERT_EQUAL(list2.back(), 20);
}

TEST(test_List_assignment_operator3) {
    List<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    List<int> list2;
    list2.push_back(3);
    list2.push_back(12);
    list2 = list1;
    ASSERT_EQUAL(list2.size(), 2);
    ASSERT_EQUAL(list2.front(), 10);
    ASSERT_EQUAL(list2.back(), 20);

    ASSERT_EQUAL(list1.front(), list2.front());
    ASSERT_EQUAL(list1.back(), list2.back());
    ASSERT_EQUAL(list1.size(), list2.size());
}

TEST(test_List_assignment_operator4) {
    List<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    List<int> list2;
    list2.push_back(4);
    list2.push_back(22);
    list2 = list1;
    ASSERT_EQUAL(list2.size(), 2);
    ASSERT_EQUAL(list2.front(), 10);
    ASSERT_EQUAL(list2.back(), 20);
}

// Test iterator forward traversal
TEST(test_List_forward_iterator) {
    List<int> list;
    for (int i = 1; i <= 5; ++i) {
        list.push_back(i);
    }
    int j = 1;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++j) {
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(j, list.size() + 1);
}

TEST(test_List_forward_iterator2) {
    List<int> list;
    for (int i = 1; i <= 5; ++i) {
        list.push_back(i);
    }
    int j = 1;
    for (List<int>::Iterator it = list.begin(); it != list.end(); it++, ++j) {
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(j, list.size() + 1);
}

TEST(test_List_clear2) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
}



// Test iterator reverse traversal
TEST(test_List_reverse_iterator) {
    List<int> list;
    for (int i = 1; i <= 5; ++i) {
        list.push_back(i);
    }
    int j = 5;
    for (List<int>::Iterator it = list.end(); it != list.begin();) {
        --it;
        ASSERT_EQUAL(*it, j);
        --j;
    }
    ASSERT_EQUAL(j, 0);
}

// Test insert method at the front of the list
TEST(test_List_insert_front) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    List<int>::Iterator it = list.begin();
    list.insert(it, 5);
    ASSERT_EQUAL(list.size(), 3);
    ASSERT_EQUAL(list.front(), 5);
}

// Test insert method in the middle of the list
TEST(test_List_insert_middle) {
    List<int> list;
    list.push_back(10);   // list: 10
    list.push_back(20);   // list: 10, 20
    List<int>::Iterator it = list.begin(); // points to 10
    ++it;  // points to 20
    list.insert(it, 15);  // inserting 15 before 20
    ASSERT_EQUAL(list.size(), 3);  // size should be 3
    ASSERT_EQUAL(*(--it), 15);  // after incrementing, iterator should point to 15
}

TEST(test_List_insert_end) {
    List<int> list;
    list.push_back(10);
    List<int>::Iterator it = list.end();
    list.insert(it, 20);
    ASSERT_EQUAL(list.size(), 2);  // size should be 3
    ASSERT_EQUAL(*(--it), 20);
}

TEST(test_List_insert_empty) {
    List<int> list;
    List<int>::Iterator it = list.begin();
    list.insert(it, 10);
    ASSERT_EQUAL(list.size(), 1);  // size should be 3
    ASSERT_EQUAL(*(--it), 10);
}

TEST(test_List_begin_empty) {
    List<int> list;
    List<int>::Iterator it = list.begin();
    List<int>::Iterator it2 = list.end();
    ASSERT_EQUAL(it, it2);
}

TEST(test_List_iterator) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 10);
    ++it;
    ASSERT_EQUAL(*it, 20);
    ++it;
    ASSERT_EQUAL(*it, 30);
}

TEST(test_List_erase) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    List<int>::Iterator it = list.begin();
    ++it;  // points to 20
    list.erase(it);  // removes 20
    
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 10);
    ASSERT_EQUAL(list.back(), 30);
}

TEST(test_List_erase_front) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    List<int>::Iterator it = list.begin();
    it = list.erase(it);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(*it, 20);
    list.erase(it);
    ASSERT_TRUE(list.empty());
}

// Test erase method
TEST(test_List_erase2) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    List<int>::Iterator it = list.begin();
    ++it;  // Pointing to 20
    ++it;
    list.erase(it);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 10);
    ASSERT_EQUAL(list.back(), 20);
}

TEST(test_default_list_equality) {
    List<int>::Iterator it;
    List<int>::Iterator it2;
    ASSERT_TRUE(it == it2);
    ASSERT_FALSE(it != it2);

    List<int> list;
    list.push_back(10);
    list.push_front(20);
    List<int>::Iterator it3 = list.end();
    List<int>::Iterator it4 = list.end();
    List<int>::Iterator it5 = list.begin();

    ASSERT_FALSE(it == it3);
    ASSERT_TRUE(it != it3);
    ASSERT_TRUE(it3 == it4);
    ASSERT_FALSE(it3 != it4);
    ASSERT_FALSE(it3 == it5);
    ASSERT_TRUE(it3 != it5);

    it3--;
    it4--;

    ASSERT_FALSE(it == it3);
    ASSERT_TRUE(it != it3);
    ASSERT_TRUE(it3 == it4);
    ASSERT_FALSE(it3 != it4);
    ASSERT_FALSE(it3 == it5);
    ASSERT_TRUE(it3 != it5);

}

TEST_MAIN()

// # File Name:  ./Auto_Ptr__test.hpp
// # Build Date: Wed Nov  8 08:33:47 AM CST 2023
// # Version:    0.1

#ifndef _Balanced_tree__TEST_H
#define _Balanced_tree__TEST_H

#include <cppunit/Test.h>

class Balanced_tree_test : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(Balanced_tree_test);
    CPPUNIT_TEST(test_tree_getroot);
    CPPUNIT_TEST(test_tree_create_default);
    CPPUNIT_TEST(test_tree_create_from_params);
    CPPUNIT_TEST(test_node_create_default);
    CPPUNIT_TEST(test_node_create_from_params);
    CPPUNIT_TEST(test_insert_node);
    CPPUNIT_TEST(test_remove_node);
    CPPUNIT_TEST(test_find_node);
    CPPUNIT_TEST(test_node_copy_ctor);
    CPPUNIT_TEST(test_node_assignment);
    CPPUNIT_TEST(test_node_getval);
    // CPPUNIT_TEST(test_node_setval);
    // CPPUNIT_TEST(test_node_setparent);
    // CPPUNIT_TEST(test_node_getparent);
    // CPPUNIT_TEST(test_node_getleft);
    // CPPUNIT_TEST(test_node_setleft);
    // CPPUNIT_TEST(test_node_getright);
    // CPPUNIT_TEST(test_node_setright);

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    void test_tree_getroot();
    void test_tree_create_default();
    void test_tree_create_from_params();
    void test_node_create_default();
    void test_node_create_from_params();
    void test_insert_node();
    void test_remove_node();
    void test_find_node();
    void test_node_copy_ctor();
    void test_node_assignment();
    void test_node_getval();
};

#endif

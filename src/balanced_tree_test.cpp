// # File Name:  ./rx_test.cpp
// # Build Date: Wed Nov  8 08:33:47 AM CST 2023
// # Version:    0.1

#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
//#include "balanced_tree.hpp"
#include "balanced_tree_test.hpp"
#include "tree.hpp"
#include "node.hpp"

using namespace CppUnit;

void Balanced_tree_test::setUp()
{
}

void Balanced_tree_test::tearDown()
{
}

void Balanced_tree_test::test_tree_getroot()
{
    node<int> root;
    tree<int> t(&root);
    node<int>* n = t.get_root();
    CPPUNIT_ASSERT(n != 0);
}

void Balanced_tree_test::test_tree_create_default()
{
    node<int> root;
    tree<int> t;
    CPPUNIT_ASSERT(&t != 0);
}


void Balanced_tree_test::test_tree_create_from_params()
{
    node<int> left;
    node<int> right;
    node<int> root((node<int>*)0, &left, &right);
    left.set_parent(&root);
    right.set_parent(&root);
    tree<int> t(&root);
}

void Balanced_tree_test::test_node_create_default()
{
}

void Balanced_tree_test::test_node_create_from_params()
{
}

void Balanced_tree_test::test_insert_node()
{
}

void Balanced_tree_test::test_remove_node()
{
}

void Balanced_tree_test::test_find_node()
{
}

void Balanced_tree_test::test_node_copy_ctor()
{
}

void Balanced_tree_test::test_node_assignment()
{
}
void Balanced_tree_test::test_node_getval()
{
}

// void Balanced_tree_test::test_node_copy_ctor()
// {
// }
// void Balanced_tree_test::test_node_copy_ctor()
// {
// }
// void Balanced_tree_test::test_node_copy_ctor()
// {
// }
// void Balanced_tree_test::test_node_copy_ctor()
// {
// }
// void Balanced_tree_test::test_node_copy_ctor()
// {
// }

CPPUNIT_TEST_SUITE_REGISTRATION( Balanced_tree_test );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry#include <stdio.h>
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output resint* pn = new int;ults in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    std::ofstream xmlFileOut("cppAuto_Ptr_TestResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}

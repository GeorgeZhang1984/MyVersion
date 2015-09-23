/*
 * File:   newtestclass.h
 * Author: hz740
 *
 * Created on 14/09/2015, 4:59:04 PM
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include <filearchiver.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(test_setReference);
    CPPUNIT_TEST(test_retrieveVersion);
    CPPUNIT_TEST(test_update);
    CPPUNIT_TEST(test_insertNew);
    CPPUNIT_TEST(test_getComment);
    CPPUNIT_TEST(test_getVersionInfo);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void test_setReference();
    void test_retrieveVersion();
    void test_update();
    void test_insertNew();
    void test_getComment();
    void test_getVersionInfo();
};

#endif	/* NEWTESTCLASS_H */
    
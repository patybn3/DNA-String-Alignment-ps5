/*
    Copyright 2023 Patricia Antlitz
*/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/included/unit_test.hpp>
#include "EDistance.hpp"

BOOST_AUTO_TEST_CASE(testPenalty) {
    // Write test cases for the penalty function
    BOOST_CHECK_EQUAL(EDistance::penalty('A', 'A'), 0);
    BOOST_CHECK_EQUAL(EDistance::penalty('A', 'C'), 1);
}

BOOST_AUTO_TEST_CASE(testMin3) {
    // Write test cases for the min3 function
    BOOST_CHECK_EQUAL(EDistance::min3(1, 2, 3), 1);
    BOOST_CHECK_EQUAL(EDistance::min3(5, 3, 7), 3);
}

BOOST_AUTO_TEST_CASE(testOptDistance) {
    // Test case 1
    EDistance eDistance1("AACAGTTACC", "TAAGGTCA");
    int distance1 = eDistance1.optDistance();
    BOOST_CHECK_EQUAL(distance1, 7);

    // Test case 2, add more test cases as needed
    EDistance eDistance2("Example", "Sample");
    int distance2 = eDistance2.optDistance();
    BOOST_CHECK_EQUAL(distance2, 3);
}

BOOST_AUTO_TEST_CASE(tesEmptyStrings) {
    EDistance eDistance("", "");
    int distance = eDistance.optDistance();

    BOOST_CHECK_EQUAL(distance, 0);

    std::string stringAlignment = eDistance.alignment();
    BOOST_CHECK_EQUAL(stringAlignment, "");
}

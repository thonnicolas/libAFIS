#include "unity.h"
#include "unity_fixture.h"

extern int Test_LocalHistogram_testNumber;

TEST_GROUP_RUNNER(LocalHistogram)
{
    RUN_TEST_CASE(LocalHistogram, LocalHistogram_Analyze_same_values_go_into_same_bucket);
    RUN_TEST_CASE(LocalHistogram, LocalHistogram_Analyze_different_values_go_into_different_buckets);
    RUN_TEST_CASE(LocalHistogram, LocalHistogram_Analyze_multiple_blocks);
    RUN_TEST_CASE(LocalHistogram, LocalHistogram_SmoothAroundCorners_2x2x1);
    RUN_TEST_CASE(LocalHistogram, LocalHistogram_Regression_Analyze);
    RUN_TEST_CASE(LocalHistogram, LocalHistogram_Regression_SmoothAroundCorners);
}

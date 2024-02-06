#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <time.h>
#include "doctest.h"
#include "prefix_sum.h"
#include "fisher_yates.h"

int test_ary_0[] = {};
int test_ary_1[] = {1, 1, 1, -1, -1, -1};
int test_ary_1comp[] = {1, 1, 1, -1, -1, -1};
int test_ary_2[] = {1, 1, 1, -1, -1, -1, -1, -1};

int first1 = -99;
int save_first1 = first1;
int second1 = 4;
int save_second1 = second1;

int i = swap(&first1, &second1);

TEST_CASE("Fisher-Yates")
{
    SUBCASE("swap tests"){
        CHECK_EQ(save_first1, second1);
    };

    SUBCASE("scramble test (light)"){
        srand(time(NULL));
        fisher_yates(test_ary_1, 6, std::rand);
        CHECK_NE(test_ary_1, test_ary_1comp); //may fail, if original array is created again
    };

    SUBCASE("validity check test"){
        CHECK_EQ(non_pos_prefix_sum(test_ary_1, 6) || !non_neg_prefix_sum(test_ary_1, 6), !check_validity(test_ary_1, 6));
        CHECK_EQ(non_pos_prefix_sum(test_ary_2, 8) || !non_neg_prefix_sum(test_ary_2, 8), !check_validity(test_ary_2, 8));
    };

}
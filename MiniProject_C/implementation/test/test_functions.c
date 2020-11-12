#include "unity.h"
#include "functions.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_adminpass(void)
{
  TEST_ASSERT_EQUAL(0,admin_password("1723"));
  TEST_ASSERT_EQUAL(1,admin_password("1264"));
  TEST_ASSERT_EQUAL(1,admin_password("agst"));

}
void test_voter_check(void)
{
  TEST_ASSERT_EQUAL(1,voter_check("1234"));
  TEST_ASSERT_EQUAL(0,voter_check("1829"));
  TEST_ASSERT_EQUAL(0,voter_check("werg"));
}
int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_adminpass);
  RUN_TEST(test_voter_check);

  /* Close the Unity Test Framework */
  return UNITY_END();
}


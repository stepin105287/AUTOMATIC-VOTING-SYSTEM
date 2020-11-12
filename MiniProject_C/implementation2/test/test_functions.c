#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <functions.h>
#define PROJECT_NAME    "AutomaticVotingSystem"

/* Prototypes for all the test functions */
void test_adminpass(void);
void test_voter_check(void);

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "check admin password", test_adminpass);
  CU_add_test(suite, "check voter id", test_voter_check);



/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */
void test_adminpass(void) {
  CU_ASSERT(0==admin_password("1723"));

  CU_ASSERT(1 == admin_password("1827"));
  CU_ASSERT(1 == admin_password("wyeu"));

}

void test_voter_check(void) {
  CU_ASSERT(1==voter_check("1234"));

  CU_ASSERT(0==voter_check("4678"));
  CU_ASSERT(0==voter_check("sghd"));
}




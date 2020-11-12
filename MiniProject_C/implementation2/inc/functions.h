/**
* @file functions.h
*
*/
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

/**
* Checks if entered admin password is correct or incorrect
* @param[in] a[5] is the password entered by user which has to be checked
* @return returns 0 if password is correct
* @note returns 1 if password is incorrect
*/

int admin_password(char a[5]);

/**
* Checks if entered voter id is valid or invalid
* @param[in] num[5] is the voter id entered by voter which has to be checked
* @return returns 1 if voter id is valid
* @note returns 0 if voter id is invalid
*/
int voter_check(char num[5]);
#endif

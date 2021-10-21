/*
 * Validate.h
 * created by Chotiya Pertpring (Fon) 62070503413 
 * Date 7 DEC 2019 
*/
/* This function use to check special string */
int checkSpecialString(char string[]) ;

/* this function use to check country */
int checkCountry(char passport[]) ;

/* this function use to check date month year */
int checkDateMonthYear (int date, int month, int year) ;

/* this function is about use to check valid of date in buddhist year */
int validateDate (char inputDate[]) ;

/* this function is about use to check postal code */
int checkPostalCode (char postalCode[]) ;

/* this function is about use to check house number */
int checkHouseNumber (char houseNumber[]) ;

/* this function is about check house number and postal code */
int validateStreet (char houseNumber[],char postalCode[]) ; 
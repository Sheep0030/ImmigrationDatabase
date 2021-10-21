/* this program is about use to check validate the
 * data that you input are correct.
 * created by Chotiya Pertpring (Fon) 62070503413 
 * Date 7 DEC 2019 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "validate.h"
/* This function use to check special string */
int checkSpecialString(char string[])
	{
	int length = 0 ; 	/* keep length of data */
	int check ; 		/* use to check valide and invalid */
	int i = 0 ; 		/* use to count the loop */
	length = strlen(string) ; /* keep length of data */
	/* loop to check special String */
	for (i = 3;i < length;i++)
		{
		/* in case data has special string */
		if (isalnum(string[i]) == 0)
			{
			check = 4 ;
			break ;
			}
		else 
			{
			check = 3 ;
			}
		}
	/* in case invalid data */
	if (check == 4)
		{
		check = 2 ;
		return check ; /* retrun value to checkCountry function */
		}
	/* in case valid data */
	else if (check == 3)
		{	
		check = 12 ;
		return check ; /* retrun value to checkCountry function */
		}
	}
/* this function use to check country */
int checkCountry(char passport[])
	{
	int i = 0 ; 				/* use to count the loop */
	int check = 0 ;				/* use to check valid and invalid */
	char countryCheck[2] ; 		/* use to keep 2 letters of country */
	/* string that keep all the country */
	char country[264][4] = {"AD","AE","AF","AG","AI","AL","AM","AO","AQ","AR","AS","AT","AU","AW","AX","AZ","BA","BB","BD","BE","BF","BG","BH","BI","BJ","BM","BN","BO","BQ","BR","BS","BT","BV","BW","BY","BZ","CA","CC","CD","CF","CG","CI","CK","CL","CM","CN","CO","CR","CU","CV","CW","CX","CY","CZ","DE","DJ","DK","DM","DO","DZ","EC","EE","EG","EH","ER","ES","ET","FI","FJ","FK","FM","FO","FR","GA","GB","GD","GE","GF","GG","GH","GI","GL","GM","GN","GP","GQ","GR","GS","GT","GU","GW","GY","HK","HM","HN","HR","HT","HU","ID","IE","IL","IM","IN","IQ","IR","IS","IT","JE","JM","JO","JP","KE","KG","KH","KI","KM","KN","KP","KR","KW","KY","KZ","LA","LB","LC","LI","LK","LR","LS","LT","LU","LY","MA","MD","ME","MF","MG","MH","MK","ML","MM","MN","MO","MP","MQ","MR","MS","MT","MU","MV","MW","MX","MY","MZ","NA","NC","NE","NF","NG","NI","NL","NO","NP","NR","NU","NZ","OM","PA","PE","PF","PG","PH","PK","PL","PM","PN","PR","PS","PT","PW","QA","RE","RO","RS","RU","RW","SA","SB","SC","SD","SE","SG","SH","SI","SJ","SK","SL","SM","SN","SO","SR","SS","ST","SV","SX","SY","SZ","TC","TD","TF","TG","TH","TJ","TK","TL","TM","TN","TO","TR","TV","TW","TZ","UA","UG","UM","US","UY","UZ","VA","VC","VE","VG","VI","VN","VU","WF","WS","YE","YT","ZA","ZM","ZW"};
	strncpy(countryCheck,passport,2) ; 
	/* loop to check valide country */
	for (i = 0;i < 264;i++)
		{
		/* in case country that you input is correct */
		if (strcmp(countryCheck,country[i]) == 0)
			{
			check = 1 ;
			break ;
			}
		/* in case country that you input is incorrect */
		else
			{
			check  = 2 ;
			}
		}
	/* in case country that you input is correct */
	if (check == 1)
		{
		/* in case third letter is - */
		if (passport[2] == '-')
			{
			/* check length of passport between 10-18 */
			if ((strlen(passport) > 10) && (strlen(passport) < 18))
				{
				/* check special string */
				check = checkSpecialString(passport) ;
				if (check == 2)
					{
					return 2 ; /* retrun value to checkPassport function */
					}
				if (check == 12)
					{
					return 1 ; /* retrun value to checkPassport function */
					}
				}
			/* in case passport less than 11 and more than 17 */
			else if ((strlen(passport) < 11) && (strlen(passport) > 17))
				{
				return 2 ; /* retrun value to checkPassport function */
				}
			}
		/* in case third letter is not - */
		else if (passport[2] != '-')
			{	
			return 2 ; /* retrun value to checkPassport function */
			}
		}
	else if (check = 2)
		{
		return check ; /* retrun value to checkPassport function */
		}
	}
/* 
 *	Valid = 0
 *	Invalid = 1
 *
/* this function use to check date month year */
int checkDateMonthYear (int date, int month, int year)
	{
	/* in case you input month less than 1 or more than 12 (month can set number until 1-12) */
	if ((month < 1) || (month > 12))
		{
		return 1 ; /* retrun value to validateDate function */
		}
	/* in case you input year less than 2462 or more than 2662 */
	else if ((year < 2462) || (year > 2662))
		{
		return 1 ; /* retrun value to validateDate function */
		}
	/* in case some year in Feb has 29 days */
	else if (year % 4 == 3)
		{
		if (month == 2)
			{
			/* in case you input date less than 1 or more than 29 */
			if ((date > 29) || (date < 0))
				{				
				return 1 ; /* retrun value to validateDate function */
				}
			/* in case you input is correct */
			else 
				{
				return 0 ; /* retrun value to validateDate function */
				}
			}	
		}
	/* in case you input year 2462-2662 */
	else if ((year > 2461) && (year < 2663))
		{
		/* in case you input month 1,3,5,7,8,10,12 */
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
			{
			/* in case you input date less than 1 or more than 31 */
			if ((date > 31) || (date < 0))
				{	
				return 1 ; /* retrun value to validateDate function */
				}
			}
		/* in case you input month 2 */	
		else if (month == 2)
			{
			/* in case you input date less than 1 or more than 28 */
			if ((date > 28) || (date < 0))
				{								
				return 1 ; /* retrun value to validateDate function */
				}
			}	
		/* in case you input month 4,6,9,11 */
		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
			{
			/* in case you input date less than 1 or more than 30 */
			if ((date > 30) || (date < 0))
				{	
				return 1 ; /* retrun value to validateDate function */
				}	
			}
		}
	return 0 ; /* retrun value to validateDate function */
	}
/* this function is about use to check valid of date in buddhist year */
int validateDate (char inputDate[])
	{
	char input [128] ; 	/* hold the data from the keyboard */
	int checkDate ; 	/* use to check data that you input is correct or incorrect*/
	int year ; 			/* keep integer of year */
	int date ; 			/* keep integer of date */
	int month ; 		/* keep integer of month */
	/* in case you input the date do not follow the foem */
	if ((strlen(inputDate) > 10) || (strlen(inputDate) < 10))
		{
		return 1 ; /* retrun value to checkDateInput function */
		}
	/* in case you follow the form */
	else if (strlen(inputDate) == 10)
		{
		/* in case you do not use / to separate the day and month And the month and year */
		if ((inputDate[2] != '/') || (inputDate[5] != '/'))
			{
			return 1 ; /* retrun value to checkDateInput function */
			}
		/* in case you input string in date, month or year */
		if ((isdigit(inputDate[0]) == 0) || (isdigit(inputDate[1]) == 0) || (isdigit(inputDate[3]) == 0) || (isdigit(inputDate[4]) == 0) || (isdigit(inputDate[6]) == 0) || (isdigit(inputDate[7]) == 0) || (isdigit(inputDate[8]) == 0) || (isdigit(inputDate[9]) == 0))
			{
			return 0 ; /* retrun value to checkDateInput function */
			}
		/* in case you input digit */
		else 
			{
			/* keep date month and year in integer */
			year = (((inputDate[6]-48)*1000) + ((inputDate[7]-48)*100) + ((inputDate[8]-48)*10) + (inputDate[9]-48)) ;
			month = (((inputDate[3]-48)*10) + (inputDate[4]-48)) ;
			date = (((inputDate[0]-48)*10) + (inputDate[1]-48)) ;
			if (date == 0)
				{
				return 1 ; /* retrun value to checkDateInput function */
				}
			checkDate = checkDateMonthYear(date,month,year) ; /* sent date month and year to checkDateMonthYear function */
			/* in case data that you input is correct */
			if (checkDate == 0)
				{
				return 0 ; /* retrun value to checkDateInput function */
				} 
			if (checkDate == 1)
				{
				return 1 ; /* retrun value to checkDateInput function */
				} 		
			}
		}
	}
/* this function is about use to check postal code */
int checkPostalCode (char postalCode[])
	{
	int numberPostalCode = 0 ; /* keep postal code [integer] */
	/* in case you did not input postal code */
	if(strlen(postalCode) == 0)
		{
		return 1 ; /* retrun value to validateStreet function */
		}	
	/* in case you input postal code more than 5 numbers */	
	if (strlen(postalCode) != 5)
		{
		return 1 ; /* retrun value to validateStreet function */
		}
	if (strlen(postalCode) == 5)
		{
		/* keep postal code in integer */
		numberPostalCode = (((postalCode[0]-48)*10) + (postalCode[1]-48)) ;
		/* in case postal code not start with 10 */
		if (numberPostalCode > 10)
			{
			return 1 ; /* retrun value to validateStreet function */
			}
		/* in case postal code start with 10 */
		else if ((numberPostalCode < 11) && (numberPostalCode > 0))
			{
			return 2 ; /* retrun value to validateStreet function */
			}
		}
	}
/* this function is about use to check house number */
int checkHouseNumber (char houseNumber[])
	{
	int i = 0 ; 					/* use to count the round */
	int checkHouseNumber = 0 ; 		/* use to check houde number that you input are correct or incorrect */
	int count = 0 ; 				/* use to count house number is digit */
	char string[10];				/* keep the copy house number */
	/* in case first character of house number that you input is not digit */
	strcpy(string,houseNumber) ;
	checkHouseNumber = 0 ;
	if (isdigit(string[0]) == 0)
		{
		return 1 ; /* retrun value to validateStreet function */
		}
	/* loop that check before and after / follow with number */
	for (i = 0;i < strlen(string);i++)
		{
		/* in case find position that / live */
		if (string[i] == '/') 
			{
			/* check next to / is number */
			if (isdigit(string[i+1]) == 0)
				{	
				return 1 ; /* retrun value to validateStreet function */
				}
			}
		/* in case chand / to 0 */
		if (string[i] == '/')
			{
			string[i] = '0' ;
			}
		}
	/* loop to check house number is all digits */
	for (i=0;i<strlen(string);i++)
		{
		/* in case house number is not digit */
		if (isdigit(string[i]) == 0)
			{
			return 1 ; /* retrun value to validateStreet function */
			}
		/* in case house number is digit */
		else if (isdigit(string[i]) != 0)
			{
			count ++ ;
			}
		/* in case house number is all digit */	
		if (count == strlen(string))
			{
			return 2 ; /* retrun value to validateStreet function */
			}
		}
	}
/* this function is about check house number and postal code */
int validateStreet (char houseNumber[],char postalCode[])
	{
	int check = 0 ; 	/* keep the number that use to check valide and invalide house number */
	int check2 = 0 ; 	/* keep the number that use to check valide postal code and invalide postal code */
	int check3 = 0 ; 	/* keep the number that use to check valide and invalide */
	check = 0 ; 		/* set check = 0 when you restart the loop */
	check = checkHouseNumber(houseNumber) ; /* call the function to check house number (call checkHouseNumber function) */
	/* in case valide house number */
	if (check == 2)
		{
		check2 = checkPostalCode(postalCode) ; /* call the function to check postal code (call checkPostalCode function) */
		}
	/* in case invalide house number */
	if (check == 1)
		{
		check3 = 1 ;
		}
	/* in case invalide postal code */
	if (check2 == 1)
		{
		check3 == 1 ;
		}
	/* in case invalide data */
	if (check3 == 1)
		{
		return 2 ; /* retrun value to checkAddressBangkok function */
		}
	/* in case valide data */
	else if (check3 != 1)
		{
		return 1 ; /* retrun value to checkAddressBangkok function */
		}
	}
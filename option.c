/* this program is about keep all the option that have in database
 * created by Chotiya Pertpring (Fon) 62070503413 
 * Date 7 DEC 2019 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "option.h"
#include "validate.h"
#include "dateFunctions.h"
#include "fileoption.h"
/* this function is add data option */
void addData()
	{
	char input[128] ; 		/* hold the data from the keybroad */
	DATA_T inputData ; 		/* keep the data that you input */
	int check1 = 0 ; 		/* use to check passport that you input */
	int check2 = 0 ; 		/* use to check the date that you input */
	int check3 = 0 ;		/* use to check name that you input */
	int check4 = 0 ;		/* use to check address that you input */
	int check5 = 0 ;		/* use to check first visit that you input */
	int check6 = 0 ;		/* use to check visa length that you input */
	rules() ; /* show the rule that you must follow when you add the data */	
	/* loop to input the passport */	
	while(1)
		{
		check1 = 0 ;
		memset(inputData.passport,0,sizeof(inputData.passport)) ;
		printf("\n=Input passport : ") ;
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",inputData.passport) ;
		check1 = checkPassport(inputData.passport) ; /* check the passport that you input is correct (call checkPassport function) */
		/* in case you input is correct */ 
		if (check1 == 1)
			{
			break ;
			}
		}
	/* loop to input date */
	while(1)
		{
		memset(inputData.date,0,sizeof(inputData.date)) ;
		printf("\n=Input the date : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%s",inputData.date) ;
		sscanf(input,"%d/%d/%d",&inputData.day1,&inputData.month,&inputData.year) ;
		check2 = checkDateInput(inputData.date,inputData.day1,inputData.month,inputData.year) ; /* check the date that you input is correct (call checkDateInput function) */
		/* in case you input is correct */ 
		if (check2 == 0)
			{
			break ;
			}
		}
	/* loop to input name */
	while(1)
		{
		memset(inputData.name,0,sizeof(inputData.name)) ;
		printf("\n=Input name : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%s",inputData.name) ;
		check3 = checkName(inputData.name) ; /* check name that you input is correct (call checkName function) */
		/* in case you input is correct */ 
		if (check3 == 1)
			{
			break ;
			}
		}
	/* loop to input address */
	while(1)
		{
		memset(inputData.lane,0,sizeof(inputData.lane)) ;
		memset(inputData.houseNumber,0,sizeof(inputData.houseNumber)) ;
		printf("\n=Input address in Bangkok : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%s %s %s %s",inputData.houseNumber,inputData.road,inputData.lane,inputData.postalCode) ;
		check4 = checkAddressBangkok(inputData.houseNumber,inputData.road,inputData.lane,inputData.postalCode) ; /* check address that you input is correct (call checkAddressBangkok function) */
		/* in case you input is correct */ 
		if (check4 == 1)
			{
			break ;
			}
		}
	/* loop to input first visit */
	while(1)
		{
		memset(inputData.firstVisit,0,sizeof(inputData.firstVisit)) ;
		printf("\n=Is this youre first time traveling to Thailand?\n") ;
		printf("=Y = Yes, N = No, U = Unknow\n") ;
		printf("=Please select : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%c",inputData.firstVisit) ;
		check5 = checkFirstVisit(inputData.firstVisit) ; /* check first visit that you input is correct (call checkFirstVisit function) */
		/* in case you input is correct */ 
		if (check5 == 1)
			{
			break ;
			}
		}
	/* loop to input visa length */
	while(1)
		{
		printf("\nInput length of visa : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%d",&inputData.visaLength) ;
		check6 = checkVisa(inputData.visaLength,inputData.year) ; /* check visa length that you input is correct (call checkVisa function) */
		/* in case you input is correct */ 
		if (check6 == 1)
			{
			break ;
			}
		}
	/* sent the data to write in the file (call keepData function) */
	keepData(inputData.passport,inputData.date,inputData.name,inputData.houseNumber,inputData.road,
			 inputData.lane,inputData.postalCode,inputData.firstVisit,inputData.visaLength) ;
	printf("\n===========================================\n") ;
	printf("========== Add data successfully ==========\n") ;
	printf("===========================================\n\n") ;
	}
/* this function use to show the rule that you must follow when you input the data */
void rules()
	{
	printf("\n\n==================================================") ;
	printf("\n==========Welcome to Add data option==========") ;
	printf("\n==================================================\n\n") ;
	printf("\n\t===Please follow the form===\n\n") ;
	printf("-------Passport must be unique CC-XXXXXXXX\n") ;
	printf("-------CC = country and XXXXXXXX = length of passport must be 8 - 14\n") ;
	printf("-------Date must be in the past and use form dd/mm/yyyy (Buddist year)\n") ;
	printf("-------Any combination of letters, digits and spaces\n") ;
	printf("-------House number must have at leat one digit and one digit after the slash\n") ;
	printf("-------Please use form C/C Stree Lane XXXXX\n") ;
	printf("-------C/C for house number, XXXXX for postal code\n") ;
	printf("-------Postal code must start with '10'\n") ;
	printf("-------And visa length in day must be 10-365 or 10-366\n") ;
	}
/* this function use to check the passport */
int checkPassport (char passport[])
	{
	int check = 0 ;		/* use to check valid passport */
	int check2 = 0 ;	/* use to check repeat passport */
	check = 0 ;
	check2 = 0 ;
	check = checkCountry(passport) ; /* check valid or in valid passport (call checkCountry function) */
	check2 = checkPassportRepeat(passport) ; /* check repeat passport (call checkPassportRepeat function) */
	/* incase invalid passport */
	if (check == 2)
		{
		printf("Invalid\n") ;
		check = 2 ;
		}
	/* incase repeat passport */	
	else if (check2 == 2)
		{
		printf("Do not repeat passport\n") ;
		check = 2 ;
		}
	/* incase valid passport */	
	else 
		{
		check = 1 ;
		}
	return check ; /* retrun value to addData function */
	}
/* this function use to check the date */
int checkDateInput (char date[], int day, int month, int year)
	{
	int check = 0 ;				/* use to check valide or invalid date */
	int dayMoment = 0 ;			/* use to keep day totay that you use this program */
	int monthMoment = 0 ;		/* use to keep month totay that you use this program */
	int yearMoment1 = 0 ;		/* use to keep year[AD] today that you use this program */
	int yearMoment2 = 0 ;		/* use to keep year[BE] today that you use this program */
	check = validateDate(date) ; /* sent the date to check valid or invalid */
	/* in case valid date form  */
	if (check == 0)
		{
		dateToday(&dayMoment,&monthMoment,&yearMoment1) ; /* keep date today that you use the program */
		yearMoment2 = yearMoment1 + 543 ;
		check = dateCompare(dayMoment,monthMoment,yearMoment2,day,month,year) ; /* call dateCompare function */
		/* in case you input date before today */
		if (check == 1)
			{
			check = 0 ;
			}
		/* in case you input date after today */	
		else 
			{
			check = 1 ;
			}
		}
	/* in case date that you input is invalid */	
	if (check == 1)
			{
			printf("Invalid\n") ;
			check = 1 ;
			}
	return check ; /* retrun value to addData function */
	}
/* this function use to check name that you input is valid */
int checkName (char name[])
	{
	int check = 0 ;			/* use to check valid or invalid */
	int lengthName = 0 ;	/* keep length of name */
	int i = 0 ;				/* use to count the loop */
	lengthName = strlen(name) ;
	/* loop to find special string */
	for (i = 0;i < lengthName;i++)
		{
		/* in case has the special string */
		if (isalnum(name[i]) == 0)
			{
			check = 1 ;
			break ;
			}
		/* in case did not have the special string */	
		else 
			{
			check = 2 ;
			}	
		}
	/* in case you did not input anything */
	if (strlen(name) == 0)
		{
		check = 2 ;
		}
	/* in case name that you input is invalid */
	if (check == 1)
		{
		printf("Invalid\n") ;
		check = 0 ;
		}
	/* in case name that you input is valid */
	else if (check == 2)
		{	
		check = 1 ;
		}
	return check ; /* retrun value to addData function */
	}
/* this function use to check address that you input */
int checkAddressBangkok (char houseNumber[], char road[], char lane[], char postalCode[])
	{
	int check = 0 ;		/* use to check data that you input valid or invalid */
	int i = 0 ;			/* use to count the loop */
	check = validateStreet(houseNumber,postalCode) ; /* check house number and postal code that you input valid or invalid (call validateStreet function) */
	/* house number and postal code that you input valid */
	if (check == 1)
		{
		/* loop to check special string in road */
		for (i = 0;i < strlen(road);i++)
			{
			/* data has special string */	
			if (isalnum(road[i]) == 0)
				{
				check = 2 ;
				break ; 
				}
			/* data did not have special string */	
			else
				{
				check = 1 ;
				}
			}
		/* loop to check special string in lane */
		for (i = 0;i < strlen(lane);i++)
			{
			/* data has special string */
			if (isalnum(lane[i]) == 0)
				{
				check = 2 ;
				}
			/* data did not have special string */
			else
				{
				check = 1 ;
				}
			}
		}
	/* in case you did not input lane and house number */
	if ((strlen(lane) == 0) || (strlen(houseNumber) == 0))
		{
		check = 2 ;
		}
	/* in case data the you input is invalid */
	if (check == 2)
		{
		printf("Invalid\n") ;
		check = 2 ;
		}
	/* in case data the you input is valid */
	else if (check == 1)
		{
		check = 1 ;
		}
	return check ; /* retrun value to addData function */
	}
/* this function use to check the first visit that you input is correct */
int checkFirstVisit (char string[])
	{
	int check = 0 ; /* use to check the data valid or invalid */
	/* in case you input is match */
	if((strcmp(string,"Y") == 0) || (strcmp(string,"N") == 0) || (strcmp(string,"U") == 0))
		{
		check = 1 ;
		}
	/* in case you input is not match */	
	else
		{
		printf("Invalid\n") ;
		check = 0 ;
		}
	return check ; /* retrun value to addData function */
	}
/* this function use to check length of visa that you input is correct */
int checkVisa (int visa, int year)
	{
	int check = 0 ; /* use to check the data valid or invalid */
	/* in case you input less than 10 and more than 366 */	
	if ((visa > 9) && (visa < 366))
		{
		check = 1 ;
		}
	/* in case some year has 366 days */
	else if (year % 4 == 3)
		{
		/* in case you input less than 10 and more than 367 */
		if ((visa > 9) && (visa < 367))
			{
			check = 1 ;
			}
		/* in case you input is incorrect */
		else 
			{
			check = 2 ;
			}
		}
	/* in case you input is correct */
	if (check == 1)
		{
		check = 1 ;
		}
	/* in case you input is incorrect */
	else 
		{
		check = 0 ;
		printf("Invalid\n") ;
		}
	return check ; /* retrun value to addData function */
	}
/* this function use to keep the data that you add in the file */
void keepData(char *passport, char *date, char *name, char *houseNumber, char *road, char *lane,
				char *postalCode, char *firstVisit, int visa)
	{
	FILE* pIn = NULL ;
	pIn = fopen("Immigrationdatabase.txt","a") ; /* open the file */
	/* in case you can not open the file */
	if (pIn == NULL)
		{
		printf("Error to open the file\n") ;
		exit(0) ;
		}
	/* in case you can open the file and add the data in file */
	else 
		{
		fprintf(pIn,"%s ",passport) ;
	 	fprintf(pIn,"%s ",date) ;
	 	fprintf(pIn,"%s ",houseNumber) ;
	 	fprintf(pIn,"%s ",road) ;
	 	fprintf(pIn,"%s ",lane) ;
	 	fprintf(pIn,"%s ",postalCode) ;
	 	fprintf(pIn,"%s ",firstVisit) ;
	 	fprintf(pIn,"%d ",visa) ;
	 	fprintf(pIn,"%s\n",name) ;
		}
	fclose(pIn) ; /* close the file */
	}
/* this function use to display the search option and you can set the option that you want to do next */
void searchData()
	{
	char input[300] ; 	/* hold the data from the keybroad */
	int number = 0 ;	/* keep the number that you want to search by */
	int check = 0 ;		/* use to check in file has data */
	check = howManyData() ; /* call howManyData function to find amount of data in the file */
	/* in case in file did not have data */
	if (check == 0)
		{
		printf("\n===========================================\n") ;
		printf("============ No data to search ============\n") ;
		printf("===========================================\n\n") ;
		}	
	/* in case in file had data */
	else 
		{
		printf("\n===========================================\n") ;
		printf("============== Search Option ==============\n") ;
		printf("===========================================\n\n") ;
		printf("You can search by\n") ;
		printf("1. Passport\n") ;
		printf("2. Date\n") ;
		/* loop to ask what you want to search by */
		while(1)
			{
			printf("What number do you want to choose? : ") ;
			fgets(input,sizeof(input),stdin) ;
			sscanf(input,"%d",&number) ;
			/* in case you set search by passport */
			if (number == 1) 
				{
				searchByPassport() ; /* call searchByPassport function */
				break ;
				}
			/* in case you set search by date */
			else if (number == 2)
				{
				searchByDate() ; /* call searchByDate function */
				break ;
				}
			/* in case you set is incorrect */
			else 
				{
				printf("Please input number again\n") ;
				}
			}
		}
	}
/* this function is about you set to search by passport */
void searchByPassport()
	{
	char input[300] ;		/* hold the data from the keybroad */
	char dataInput[20] ;	/* keep the passport (you want to search) that you input */
	printf("Form : CC-XXXXXXXXXX\n") ;
	printf("CC = country and XXXXXXXX = length of passport must be 8 - 14\n") ;
	printf("Please input the passport that you want to search : ") ;
	fgets(input,sizeof(input),stdin) ;
	sscanf(input,"%s",dataInput) ;
	passportSearch(dataInput) ; /* sent passport that you input to passportSearch function */
	}
/* this function is about you set to search by date */
void searchByDate()
	{
	char input[300] ;		/* hold the data from the keybroad */
	char dataInput[20] ;	/* keep the date (you want to search) that you input */
	int check = 0 ;			/* use to check data that you input is valid or invalid */
	printf("Form : dd/mm/yyyy\n") ;
	/* loop to input the date */
	while (1)
		{
		printf("Please input the date that you want to search : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%s",dataInput) ;
		check = validateDate(dataInput) ; /* sent date that you input to check in validateDate function */
		/* in case you input date is correct */
		if (check == 0)
			{
			dateSearch(dataInput) ; /* sent date that you input to dateSearch function */
			break ;
			}
		/* in case you input date is incorrect */
		else
			{
			printf("Please follow the form\n") ;
			}
		}  
	}
/* this function use to search by passport */
void passportSearch(char passport[])
	{
	int datafFind = 0 ; 		/* use to check in case data not found */
	char input[300] ;			/* hold the data from the file */
	int count = 0 ;				/* use to keep amount of data in the file */
	DATA_T *sameData ;			/* use to keep the data the you search */
	int numberOfData = 0 ;		/* use to tell the position of data */	
	int b = 0 ; 				/* use to keep how many data that you search found */
	DATA_T *info ;				/* keep the data from the file */
	int length = 0 ; 			/* keep the length of passport */
	FILE* pIn = NULL ;
	int i = 0 ;					/* use to count the loop */
	int position = 0 ;			/* use to tell position of data that you search */
	int foundData = 0 ; 		/* use to print Found data when the data was found */
	count = howManyData() ;  	/* find amount of data in the file (call howManyData function) */
	pIn = fopen("Immigrationdatabase.txt","r") ;
	/* in case can not open the file */
	if (pIn == NULL)
		{
		printf("Error to open file\n") ;
		exit(2) ;
		}
	info = calloc(count,sizeof(DATA_T)) ; /* reserve space in info */
	sameData = calloc(count,sizeof(DATA_T)) ; /* reserve space in sameData */
	/* keep the data from the file */
	while(fgets(input,sizeof(input),pIn) != NULL)
		{
		sscanf(input,"%s %s %s %s %s %s %s %d %s",info[i].passport,info[i].date,info[i].houseNumber,info[i].road,info[i].lane,info[i].postalCode,info[i].firstVisit,&info[i].visaLength,info[i].name) ;
		i++ ;
		}
	fclose(pIn) ; /* clode the file */
	length = strlen(passport) ; /* keep the length of passport */
	/* loop to search the data that you input */
	for(i = 0;i < count;i++)
		{
		if (strncasecmp(passport,info[i].passport,length) == 0)
			{
			foundData++ ;
			/* in case the data that you input is found */
			if (foundData == 1)
				{
				printf("\n===========================================\n") ;
				printf("================ Found data ===============\n") ;
				printf("===========================================\n\n") ;
				}
			position = i ;
			b++ ;
			/* keep the data from info to dameData */
			sscanf(info[i].passport,"%s",sameData[numberOfData].passport) ;
			sscanf(info[i].date,"%s",sameData[numberOfData].date) ;
			sscanf(info[i].houseNumber,"%s",sameData[numberOfData].houseNumber) ;
			sscanf(info[i].road,"%s",sameData[numberOfData].road) ;
			sscanf(info[i].lane,"%s",sameData[numberOfData].lane) ;
			sscanf(info[i].postalCode,"%s",sameData[numberOfData].postalCode) ;
			sscanf(info[i].firstVisit,"%s",sameData[numberOfData].firstVisit) ;
			sameData[numberOfData].visaLength = info[i].visaLength ;
			sscanf(info[i].name,"%s",sameData[numberOfData].name) ;
			numberOfData++ ; 
			SearchDataDisplay(position,count,b) ; /* display the same data that you want to search (call DataDisplay function) */
			}
		}
	/* in case the data that you input is not found */	
	if (foundData == 0) 
		{
		printf("\n===========================================\n") ;
		printf("============== Data not found =============\n") ;
		printf("===========================================\n\n") ;
		datafFind = 1 ;
		}
	if (datafFind == 0)
		{
		editData(sameData,numberOfData) ; /* go to edit function (call editData function) */
		}
	free(info) ; /* free the data */
	free(sameData) ; /* free the data */
	}
/* this function is about you set to search by date */
void dateSearch(char date[])
	{
	char input[300] ;				/* hold the data from the file */
	int numberOfData = 0 ;			/* use to tell the position of data */
	int b = 0 ; 					/* use to keep how many data that you search found */
	int count = 0 ;					/* use to keep amount of data in the file */
	DATA_T *info ;					/* keep the data from the file */
	DATA_T *sameData ;				/* use to keep the data the you search */
	FILE* pIn = NULL ;
	int i = 0 ;						/* use to count the loop */
	int position = 0 ;				/* use to tell position of data that you search */
	int foundData = 0 ;				/* use to print Found data when the data was found */
	int datafFind = 0 ; 					/* use to check in case data not found */
	count = howManyData() ;			/* find amount of data in the file (call howManyData function) */
	pIn = fopen("Immigrationdatabase.txt","r") ;
	/* in case can not open the file */
	if (pIn == NULL)
		{
		printf("Error to open file\n") ;
		exit(2) ;
		}
	info = calloc(count,sizeof(DATA_T)) ;		/* reserve space in info */
	sameData = calloc(count,sizeof(DATA_T)) ;	/* reserve space in sameData */
	/* keep the data from the file */
	while(fgets(input,sizeof(input),pIn) != NULL)
		{
		sscanf(input,"%s %s %s %s %s %s %s %d %s",info[i].passport,info[i].date,info[i].houseNumber,info[i].road,info[i].lane,info[i].postalCode,info[i].firstVisit,&info[i].visaLength,info[i].name) ;
		i++ ;
		}
	fclose (pIn) ; /* close the file */
	/* loop to search the data that you input */
	for(i = 0;i < count;i++)
		{
		if (strcmp(date,info[i].date) == 0)
			{
			foundData++ ;
			/* in case the data that you input is found */
			if (foundData == 1)
				{
				printf("\n===========================================\n") ;
				printf("================ Found data ===============\n") ;
				printf("===========================================\n\n") ;
				}
			position = i ;
			b++ ;
			/* keep the data from info to dameData */
			sscanf(info[i].passport,"%s",sameData[numberOfData].passport) ;
			sscanf(info[i].date,"%s",sameData[numberOfData].date) ;
			sscanf(info[i].houseNumber,"%s",sameData[numberOfData].houseNumber) ;
			sscanf(info[i].road,"%s",sameData[numberOfData].road) ;
			sscanf(info[i].lane,"%s",sameData[numberOfData].lane) ;
			sscanf(info[i].postalCode,"%s",sameData[numberOfData].postalCode) ;
			sscanf(info[i].firstVisit,"%s",sameData[numberOfData].firstVisit) ;
			sameData[numberOfData].visaLength = info[i].visaLength ;
			sscanf(info[i].name,"%s",sameData[numberOfData].name) ;
			numberOfData++ ;
			SearchDataDisplay(position,count,b) ;
			}
		}
	/* in case the data that you input is not found */
	if (foundData == 0)  
		{
		printf("\n===========================================\n") ;
		printf("============== Data not found =============\n") ;
		printf("===========================================\n\n") ;
		datafFind = 1 ;
		}
	/* in case not found data do not go to edit option */
	if (datafFind == 0)
		{
		editData(sameData,numberOfData) ; /* go to edit function (call editData function) */
		}
	free(info) ; /* free the data */
	free(sameData) ; /* free the data */
	}
/* this function use to check the passport that you input is not same in the file */
int checkPassportRepeat(char string[])
	{
	char input[300] ;			/* hold the data from the file */
	int countData = 0 ;			/* use to keep amount of data in the file */
	DATA_T *check ;				/* keep the data from the file */
	int i = 0 ;					/* use to count the loop */
	FILE *pIn = NULL ;
	pIn = fopen("Immigrationdatabase.txt","r") ;
	/* in case you can not open the file */
	if (pIn == NULL)
		{
		printf("Error to open the file\n") ;
		exit(7) ;
		}
	countData = howManyData();	/* find amount of data in the file (call howManyData function) */
	/* in case not have data in the file */
	if (countData == 0)
		{
		return 1 ;
		}
	else 
		{
		check = calloc(countData,sizeof(DATA_T)) ;		/* reserve space in check */
		/* keep the data from the file */
		while(fgets(input,sizeof(input),pIn) != NULL)
			{
			sscanf(input,"%s %s %s %s %s %s %s %d %s",check[i].passport,check[i].date,check[i].houseNumber,check[i].road,check[i].lane,check[i].postalCode,check[i].firstVisit,&check[i].visaLength,check[i].name) ;
			i++ ;
			}
		fclose(pIn) ; /* close the file */
		/* loop to fine to fine passport that you input are not same */
		for(i = 0;i < countData;i++)
			{
			if (strcmp(string,check[i].passport) == 0)
				{
				return 2 ;	/* retrun value to checkPassport function */
				}
			}
		free(check) ; /* free the data */
		return 1 ;	/* retrun value to checkPassport function */
		}
	}
/* this function is about use to edit the data */
void editData (DATA_T sameData[], int count)
	{
	char input[300] ; 	/* hold the data from the keybroad */
	char yesNo[4] ;  	/* keep the string yes and no */
	printf("\n===========================================\n") ;
	printf("=============== Edit Option ===============\n") ;
	printf("===========================================\n\n") ;
	/* loop to ask do you want edit the data */
	while(1)
		{
		printf("Do you want to edit the data? (Yes or No) : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%s",yesNo) ;
		/* in case you want to edit the data */
		if (strcasecmp(yesNo,"Yes") == 0)
			{
			DataEditfunction(sameData,count) ; /* call DataEditfunction */
			break ;
			}
		/* in case you do not want to edit the data */
		else if (strcasecmp(yesNo,"No") == 0)
			{
			break ; 
			}
		/* in case you do not input yes or no */
		else 
			{
			printf("Please input Yes or No only\n") ;
			}
		}
	}
/* thsi function about ask you to add new data replace old data */
void DataEditfunction(DATA_T sameData[], int count)
	{
	DATA_T chosenData;  	/* keep the data that you want to edit */
	char input[300] ;		/* hold the data from the keybroad */
	int number = 0 ;		/* keep the number of data that you want to edit */
	/* loop to ask you what number of data that you want to edit */
	while(1)
		{
		printf("What number data that you want to edit? : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%d",&number) ;
		/* in case you input number more than the display data */
		if (number > count)
			{
			printf("Please input again\n") ;
			}
		/* in case you input correct */
		else 
			{
			break ;
			}
		}
	/* keep the data from sameData to chosenData */
	sscanf(sameData[number-1].passport,"%s",chosenData.passport) ;
	sscanf(sameData[number-1].date,"%s",chosenData.date) ;
	sscanf(sameData[number-1].houseNumber,"%s",chosenData.houseNumber) ;
	sscanf(sameData[number-1].road,"%s",chosenData.road) ;
	sscanf(sameData[number-1].lane,"%s",chosenData.lane) ;
	sscanf(sameData[number-1].postalCode,"%s",chosenData.postalCode) ;
	sscanf(sameData[number-1].firstVisit,"%s",chosenData.firstVisit) ;
	chosenData.visaLength = sameData[number-1].visaLength ;
	sscanf(sameData[number-1].name,"%s",chosenData.name) ;
	editNewData(chosenData) ; /* call editNewData function */
	}
/* this function about ask you to add new data (you choose to edit the data) */
void editNewData(DATA_T chosenData)
	{
	char input[300] ;		/* hold the data from file */
	FILE *pIn = NULL ;
	DATA_T *info ;			/* keep the data from the file */
	int i = 0 ;				/* use to count the loop */
	int count = 0 ;			/* keep amount of data from the file */
	DATA_T newdata ;		/* keep the new data the you want to add */
	int check1 = 0 ; 		/* use to check passport that you input */
	int check2 = 0 ; 		/* use to check the date that you input */
	int check3 = 0 ;		/* use to check name that you input */
	int check4 = 0 ;		/* use to check address that you input */
	int check5 = 0 ;		/* use to check first visit that you input */
	int check6 = 0 ;		/* use to check visa length that you input */
	pIn = fopen("Immigrationdatabase.txt","r") ;
	/* in case you can not open the file */
	if (pIn == NULL)
		{
		printf("Error to open the file\n") ;
		exit(7) ;
		}
	count = howManyData();	/* find amount of data in the file (call howManyData function) */
	info = calloc(count,sizeof(DATA_T)) ;	/* reserve space in info */
	/* loop to keep the data from the file */
	while(fgets(input,sizeof(input),pIn) != NULL)
		{
		sscanf(input,"%s %s %s %s %s %s %s %d %s",info[i].passport,info[i].date,info[i].houseNumber,info[i].road,info[i].lane,info[i].postalCode,info[i].firstVisit,&info[i].visaLength,info[i].name) ;
		i++ ;
		}
	fclose(pIn) ; /* close the file */
	rules() ; /* show the rule that you must follow when you add the data */
	/* loop to input new passport */
	while(1)
		{
		check1 = 0 ;
		memset(newdata.passport,0,sizeof(newdata.passport)) ;
		printf("\n=Input new passport : ") ;
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%s",newdata.passport) ;
		check1 = checkPassport(newdata.passport) ; /* check the passport that you input is correct (call checkPassport function) */
		/* in case you input is correct */ 
		if (check1 == 1)
			{
			break ;
			}
		}
	/* loop to input new date */
	while(1)
		{
		memset(newdata.date,0,sizeof(newdata.date)) ;
		printf("\n=Input new date : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%s",newdata.date) ;
		sscanf(input,"%d/%d/%d",&newdata.day1,&newdata.month,&newdata.year) ;
		check2 = checkDateInput(newdata.date,newdata.day1,newdata.month,newdata.year) ; /* check the date that you input is correct (call checkDateInput function) */
		/* in case you input is correct */ 
		if (check2 == 0)
			{
			break ;
			}
		}
	/* loop to input new name */
	while(1)
		{
		memset(newdata.name,0,sizeof(newdata.name)) ;
		printf("\n=Input new name : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%s",newdata.name) ;
		check3 = checkName(newdata.name) ; /* check name that you input is correct (call checkName function) */
		/* in case you input is correct */ 
		if (check3 == 1)
			{
			break ;
			}
		}
	/* loop to input new address */
	while(1)
		{
		memset(newdata.road,0,sizeof(newdata.road)) ;
		memset(newdata.lane,0,sizeof(newdata.lane)) ;
		printf("\n=Input new address in Bangkok : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%s %s %s %s",newdata.houseNumber,newdata.road,newdata.lane,newdata.postalCode) ;
		check4 = checkAddressBangkok(newdata.houseNumber,newdata.road,newdata.lane,newdata.postalCode) ; /* check address that you input is correct (call checkAddressBangkok function) */
		/* in case you input is correct */ 
		if (check4 == 1)
			{
			break ;
			}
		}
	/* loop to input new first visit */
	while(1)
		{
		memset(newdata.firstVisit,0,sizeof(newdata.firstVisit)) ;
		printf("\n=Is this youre first time traveling to Thailand?\n") ;
		printf("=Y = Yes, N = No, U = Unknow\n") ;
		printf("=Please select : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%c",newdata.firstVisit) ;
		check5 = checkFirstVisit(newdata.firstVisit) ; /* check first visit that you input is correct (call checkFirstVisit function) */
		/* in case you input is correct */ 
		if (check5 == 1)
			{
			break ;
			}
		}
	/* loop to input new visa length */
	while(1)
		{
		printf("\n=Input new length of visa : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%d",&newdata.visaLength) ;
		check6 = checkVisa(newdata.visaLength,newdata.year) ; /* check visa length that you input is correct (call checkVisa function) */
		/* in case you input is correct */ 
		if (check6 == 1)
			{
			break ;
			}
		}
	/* fine the data that you want to edit and overwrite the new data */
	for(i=0; i<count; i++)
		{
		if(strcmp(chosenData.passport, info[i].passport) == 0)
			{
			sscanf(newdata.passport,"%s",info[i].passport) ;
			sscanf(newdata.date,"%s",info[i].date) ;
			sscanf(newdata.houseNumber,"%s",info[i].houseNumber) ;
			sscanf(newdata.road,"%s",info[i].road) ;
			sscanf(newdata.lane,"%s",info[i].lane) ;
			sscanf(newdata.postalCode,"%s",info[i].postalCode) ;
			sscanf(newdata.firstVisit,"%s",info[i].firstVisit) ;
			info[i].visaLength = newdata.visaLength ;
			sscanf(newdata.name,"%s",info[i].name) ;
			break;
			}
		}
	AddNewData(info,count) ; /* call AddNewData function */
	free(info) ; /* free the data */
 	}
/* this function about add new data in the file */
void AddNewData (DATA_T data[], int count) 
	{
	int i = 0 ;	/* use to count the loop */
	FILE* pIn = NULL ;
	pIn = fopen("Immigrationdatabase.txt","w") ;
	/* in case you can not open the file */
	if (pIn == NULL)
		{
		printf("Error to open the file\n") ;
		exit(0) ;
		}
	/* loop to add the new data in file */
	for (i = 0;i<count;i++)
		{
		fprintf(pIn,"%s ",data[i].passport) ;
	 	fprintf(pIn,"%s ",data[i].date) ;
	 	fprintf(pIn,"%s ",data[i].houseNumber) ;
	 	fprintf(pIn,"%s ",data[i].road) ;
	 	fprintf(pIn,"%s ",data[i].lane) ;
	 	fprintf(pIn,"%s ",data[i].postalCode) ;
	 	fprintf(pIn,"%s ",data[i].firstVisit) ;
	 	fprintf(pIn,"%d ",data[i].visaLength) ;
	 	fprintf(pIn,"%s\n",data[i].name) ;
		}
	printf("\n===========================================\n") ;
	printf("=========== Add data successfully =========\n") ;
	printf("===========================================\n\n") ;
	fclose(pIn) ; /* close the file */
	}

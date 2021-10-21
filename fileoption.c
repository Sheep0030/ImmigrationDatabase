/* this program is about show display option, find amount of data in the text file, 
 * display the data that you search.
 * created by Chotiya Pertpring (Fon) 62070503413 
 * Date 7 DEC 2019 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fileoption.h"
/* This function use to display the data when you select display data option */
void displayAllData()
	{
	char input[200] ; /* hold the data from the file */
	FILE* pIn = NULL ; 
	DISPLAY_T data[300] ; /* keep the data from the file */
	int i = 0 ; /* use to count the loop */
	int count = 1 ; /* use to check in file has data */
	pIn = fopen("Immigrationdatabase.txt","r") ; /* open the file */
	/* in case you can not open the file */
	if (pIn == NULL)
		{
		printf("Error to open the file\n") ;
		exit(0) ;
		}
	/* in case you can open the file */
	else 
		{
		printf("\n===========================================\n") ;
		printf("================= All data ================\n") ;
		printf("===========================================\n\n") ;
		/* loop to display all data in the file */
		while(fgets(input,sizeof(input),pIn) != NULL)
			{
			memset(data[i].name,0,sizeof(data[i].name));
			sscanf(input,"%s %s %s %s %s %s %s %d %s",data[i].passport,data[i].date,data[i].houseNumber,data[i].road,data[i].lane,data[i].postalCode,data[i].firstVisit,&data[i].visaLength,data[i].name) ;
			printf("=#%d#=\n",count) ;
			printf("\t==Passport : %s\n",data[i].passport) ;
			printf("\t==Date : %s\n",data[i].date) ;
		 	printf("\t==Name : %s\n",data[i].name) ;
		 	printf("\t==Address : %s %s %s %s\n",data[i].houseNumber,data[i].road,data[i].lane,data[i].postalCode) ;
		 	printf("\t==First visit : %s\n",data[i].firstVisit) ;
		 	printf("\t==Visa length in day : %d\n",data[i].visaLength) ; 
		 	printf("\n") ;
			count++ ;	
			}
		/* in case in file did not have data */
		if (count == 1)
			{
			printf("\n===========================================\n") ;
			printf("============= No data to display ==========\n") ;
			printf("===========================================\n\n") ;
			}
		}
	fclose(pIn) ; /* close the file */
	}
/* This function use to find amount of data in the file */
int howManyData()
	{
	char input[500] ; /* hold the data from the file */
	int count = 0 ; /* use to keep amount of data */
	FILE *pIn = NULL ;
	pIn = fopen("Immigrationdatabase.txt","r") ;
	/* in case you can not open the file */
	if (pIn == NULL) 
		{
		printf("Error to open the file\n") ;
		exit(1) ;
		}
	/* read the data from the file */
	while(fgets(input,sizeof(input),pIn) != NULL)
		{
		count++ ;
		}
	fclose(pIn) ; /* close the file */
	return count ; /* retrun value to function that call this function to use */
	}
/* This function use to display the data that you search */
void SearchDataDisplay(int position, int count, int b)
	{
	DISPLAY_T data[count] ; /* keep the data that you search */
	char input[300] ; /* hold the data from the file */
	FILE *pIn = NULL ;
	int i = 0 ; /* use to set the position of string */
	pIn = fopen("Immigrationdatabase.txt","r") ;
	/* in case you can not open the file */
	if (pIn == NULL)
		{
		printf("Error to open file\n") ;
		exit(5) ;
		}
	/* loop to keep the data from the file */
	while(fgets(input,sizeof(input),pIn) != NULL)
		{
		memset(data[i].name,0,sizeof(data[i].name));
		sscanf(input,"%s %s %s %s %s %s %s %d %s",data[i].passport,data[i].date,data[i].houseNumber,data[i].road,data[i].lane,data[i].postalCode,data[i].firstVisit,&data[i].visaLength,data[i].name) ;
		i++ ;
		}
	/* display the data that you search */
	printf("=#%d#=\n",b) ;
	printf("\t==Passport : %s\n",data[position].passport) ;
	printf("\t==Date : %s\n",data[position].date) ;
 	printf("\t==Name : %s\n",data[position].name) ;
 	printf("\t==Address : %s %s %s %s\n",data[position].houseNumber,data[position].road,data[position].lane,data[position].postalCode) ;
	printf("\t==First visit (Y = Yes, N = No, U = Unknow) : %s\n",data[position].firstVisit) ;
 	printf("\t==Visa length in day : %d\n",data[position].visaLength) ; 
 	printf("\n") ;
	}




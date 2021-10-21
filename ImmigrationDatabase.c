/* this program is about display all the option in this database
 * that you can choose.
 * created by Chotiya Pertpring (Fon) 62070503413 
 * Date 7 DEC 2019 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "option.h"
#include "fileoption.h"

int main(int argc, char *argv[])
	{
	char input[128] ; /* hold the data from the keybroad */
	int select = 0 ; /* keep the option that you select */
	while (1)
		{
		select = 0 ;
		/* display the option */
		printf("\n===========================================\n") ;
		printf("===== Welcome to Immigration Database =====\n") ;
		printf("===========================================\n\n") ;
		printf("\t1.Display the data\n") ;
		printf("\t2.Search and Edit the data\n") ;
		printf("\t3.Add the data\n") ;
		printf("\t4.Exit the programe\n\n") ;
		printf("What do you want to do? : ") ;
		fgets(input,sizeof(input),stdin) ;
		sscanf(input,"%d",&select) ;
		/* in case you select display option */
		if (select == 1)
			{
			displayAllData() ;
			}
		/* in case you select search and edit option */
		else if (select == 2)
			{
			searchData() ;
			}
		/* in case you select add data option */
		else if (select == 3)
			{
			addData() ;
			}
		/* in case you want to exit the program */
		else if (select == 4)
			{
			printf("\n===========================================\n") ;
			printf("============== G O O D B Y E  =============\n") ;
			printf("===========================================\n") ;
			exit(0) ;
			}
		/* in case you input number less than 1 and more than 4 */
		else if (select < 1 || select > 4)
			{
			printf("\nWorng input number\n\n") ; 
			}
		}	
	}
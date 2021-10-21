/*
 * fileoption.h
 * created by Chotiya Pertpring (Fon) 62070503413 
 * Date 7 DEC 2019 
*/
typedef struct 
	{
	char passport[20] ; 		/* keep passport */
	char date[15] ; 			/* keep date in form dd/mm/yyyy in Buddist year */
	char name[30] ; 			/* keep first name */
	char postalCode[10] ;		/* keep postal code */
	char houseNumber[10] ;		/* keep house number */
	char road[20] ;				/* keep name of road */
	char lane[20] ; 			/* keep name of lane */
	char firstVisit[2] ;		/* keep Y(Yes) N(No) and U(Unknow) */
	int visaLength ; 			/* keep the visa length day and the value must be 10-365 days */
	} DISPLAY_T ;

/* This function use to display the data when you select display data option */
void displayAllData() ;

/* This function use to find amount of data in the file */
int howManyData() ;

/* This function use to display the data that you search */
void SearchDataDisplay(int position, int count, int b) ;

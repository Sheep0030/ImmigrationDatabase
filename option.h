/*
 * option.h
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
	char road[30] ;				/* keep name of road */
	char lane[30] ; 			/* keep name of lane */
	char firstVisit[2] ;		/* keep Y(Yes) N(No) and U(Unknow) */
	int visaLength ; 			/* keep the visa length day and the value must be 10-365 days */
	int day1 ;					/* keep day[integer] that you input */
	int month ; 				/* keep month[integer] that you input */
	int year ;					/* keep year[integer] that you input */
	} DATA_T ;

/* this function is add data option */
void addData() ;

/* this function use to show the rule that you must follow when you input the data */
void rules() ; 

/* this function use to check the passport */
int checkPassport (char passport[]) ;

/* this function use to check the date */
int checkDateInput (char date[], int day, int month, int year) ;

/* this function use to check name that you input is valid */
int checkName (char name[]) ;

/* this function use to check address that you input */
int checkAddressBangkok (char houseNumber[], char road[], char lane[], char postalCode[]) ;

/* this function use to check the first visit that you input is correct */
int checkFirstVisit (char string[]) ;

/* this function use to check length of visa that you input is correct */
int checkVisa (int visa, int year) ;

/* this function use to keep the data that you add in the file */
void keepData(char *passport, char *date, char *name, char *houseNumber, char *road, char *lane,
			  char *postalCode, char *firstVisit, int visa) ;

/* this function use to display the search option and you can set the option that you want to do next */
void searchData() ;

/* this function is about you set to search by passport */
void searchByPassport() ;

/* this function is about you set to search by date */
void searchByDate() ;

/* this function use to search by passport */
void passportSearch(char passport[]) ;

/* this function is about you set to search by date */
void dateSearch(char date[]) ;

/* this function use to check the passport that you input is not same in the file */
int checkPassportRepeat(char string[]) ;

/* this function is about use to edit the data */
void editData(DATA_T sameData[], int count) ;

/* thsi function about ask you to add new data replace old data */
void DataEditfunction(DATA_T sameData[], int count) ;

/* this function about ask you to add new data (you choose to edit the data) */
void editNewData(DATA_T chosenData) ;

/* this function about add new data in the file */
void AddNewData (DATA_T data[], int count) ;
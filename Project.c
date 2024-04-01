#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
#define MAX_LINE_LENGTH 256

void CreateRecord();
void EditRecord();
int RemoveRecord();
void Diagnostics();
int PrescNBills();


void CreateRecord(){
	
	system("cls");
    printf("You will be re-directed to diagnosis function after patient records have been created.\n");
	puts("Create");
	struct patient{
		int ID;
		int Age;
		char Gender;
		char PatFirstName[100];
		char PatSecondName[100];
		char PhoneNumber[11];
		int Days, Month , Year;
	};
	struct patient Pat;
	int flag = 1;
	
	printf("Enter patient First Name: ");
    scanf("%s", &Pat.PatFirstName);
	printf("Enter patient Second Name: ");
	scanf("%s", &Pat.PatSecondName);
    printf("Enter ID: ");
    scanf("%d", &Pat.ID);
    printf("Enter patient Age: ");
    scanf("%d", &Pat.Age);
    printf("Enter patient Gender (M or F): ");
    scanf(" %c", &Pat.Gender);

    printf("Enter patient phone Number, Enter 11 0's if patient number not available': ");
    scanf(" %11s", Pat.PhoneNumber);
    while (flag != 0){
    	if (strlen(Pat.PhoneNumber) != 11){
    		printf("re-enter valid number: ");
		}
		else{
			flag = 0;
		}
	}
	flag = 1; 
	printf("Enter date of patient admit : \n");
	while (flag !=0){
		printf("Day: ");
		scanf("%d" , &Pat.Days);
		if (Pat.Days >= 1 && Pat.Days <=31){
			flag = 0;
		}
		else{
			printf("Re enter valid day in range\n");
		}
	}
	flag = 1;
	while (flag !=0){
		printf("Month: ");
		scanf("%d" , &Pat.Month);
		if (Pat.Month >= 1 && Pat.Month <= 12){
			flag = 0;
		}
		else{
			printf("Re enter Month in valid range\n");
		}
	}	
	printf("Enter year: ");
	scanf("%d" , &Pat.Year);
	
	char filename[100];
	printf("\n%d", Pat.ID);
    printf("\n%d", Pat.Age);
    printf("\n%s", Pat.PatFirstName);
    printf("\n%s", Pat.PatSecondName);
    printf("\n%c", Pat.Gender);
    printf("\n%s", Pat.PhoneNumber);
    printf("\n%d-%d-%d" , Pat.Days , Pat.Month , Pat.Year); 
    printf("\n");
    printf("\n");
    printf("\n");
	printf("\n");	
    strcpy(filename , Pat.PatFirstName);
    char FileID[100];
    sprintf(FileID , "%d" , Pat.ID);
    strcat(filename , FileID);
    strcat(filename,".txt");
    FILE *file = fopen(filename, "w"); 
    if (file == NULL) {
        printf("Error opening file.\n");

    } 
    fprintf(file, "ID: %d\n", Pat.ID);
    fprintf(file, "Age: %d\n", Pat.Age);
    fprintf(file, "First Name: %s\n", Pat.PatFirstName);
    fprintf(file, "Second Name: %s\n" , Pat.PatSecondName);
    fprintf(file, "Gender: %c\n", Pat.Gender);
    fprintf(file, "Phone Number: %s\n", Pat.PhoneNumber);
    fprintf(file, "Patient Admit Date: %d-%d-%d\n", Pat.Days, Pat.Month, Pat.Year);
    fprintf(file, "\n");
    fclose(file);	
    printf("Record successfully saved to %s\n", filename);
	FILE *file2 = fopen("RecordList.txt" , "a");
	if (file2 == NULL){
		printf("Error opening the file.\n");
	}
	fprintf(file , "\n" , NULL);
	fprintf(file2, "%s" , filename);
	fclose(file2);
	printf("Record name stored successfully to RecordList.txt");
	
	char Choice[2];
	
	printf("Do you want to continue to Diagnostic function Y/N?");
	scanf("%s" , &Choice);
	Choice[0] = tolower(Choice[0]);
	if (Choice[0] == 'y'){
		Diagnostics();
	}
	else if(Choice[0] == 'n'){
	}
	
    printf("\nEnter mode \nC for Create a record \nE for edit record \nR for removing record \nP for Prescription and billing \nQ for exiting the program\n \n: ");
        
}


void EditRecord(){
	system("cls");
	printf("You will be re-directed to diagnosis function after patient records have been created.\n");
	puts("Edit");
	FILE *file2;
	char record[100];
	file2 = fopen("RecordList.txt" , "r");
	if(file2 == NULL){
		perror("File does not exist");
	}
	printf("List of existing records: ");
	while(fgets(record , sizeof(record) , file2 ) !=NULL ){
		printf("%s " , record);
	}
	
	FILE *file;	
	char details[100];
	char recordname[100];
	printf("\nEnter name of patient to open record: ");
	scanf(" %s" , &recordname);
	
	file = fopen(recordname , "r");
	
	if (file == NULL){
		perror("File does not exist");
	}
	printf("Patient details: \n");
	
	while (fgets(details , sizeof(details), file) != NULL){
		printf("\n%s" , details);
	}
	fclose(file);
	printf("Enter new details:\n ");
	
	int ID, Age;
    char Gender;
    char PhoneNumber[11] , PatFirstName[100], PatSecondName[100];
    int Days, Month, Year;
	
	
	int flag = 1;
	printf("Enter first patient name : ");
    scanf("%s", &PatFirstName);
    
    printf("Enter patient second name: ");
    scanf("%s" , &PatSecondName);
	
    printf("Enter ID: ");
    scanf("%d", &ID);

    printf("Enter patient Age: ");
    scanf("%d", &Age);

    printf("Enter patient Gender (M or F): ");
    scanf(" %c", &Gender);

    printf("Enter patient phone Number, Enter 11 0's if patient number not available': ");
    scanf(" %11s", &PhoneNumber);
    
	while (flag != 0){
    	if (strlen(PhoneNumber) != 11){
    		printf("re-enter valid number: ");
		}
		else{
			flag = 0;
		}
	}
	flag = 1; 
	
	printf("Enter date of patient admit : \n");
	
	while (flag !=0){
		printf("Day: ");
		scanf("%d" , &Days);
		if (Days >= 1 && Days <=31){
			flag = 0;
		}
		else{
			printf("Re enter valid day in range\n");
		}
	}
	
	flag = 1;
	
	while (flag !=0){
		printf("Month: ");
		scanf("%d" , &Month);
		if (Month >= 1 && Month <= 12){
			flag = 0;
		}
		else{
			printf("Re enter Month in valid range\n");
		}
	}
	
	printf("Enter year: ");
	scanf("%d" , &Year);
	
	FILE *file3 = fopen(recordname , "w");
	if (file3 == NULL) {
        printf("Error opening file.\n");
    }
    
    fprintf(file3, "ID: %d\n", ID);
    fprintf(file3, "Age: %d\n", Age);
    fprintf(file3, "First Name: %s\n", PatFirstName);
    fprintf(file3, "Second Name: %s\n" , PatSecondName);
    fprintf(file3, "Gender: %c\n", Gender);
    fprintf(file3, "Phone Number: %s\n", PhoneNumber);
    fprintf(file3, "Patient Admit Date: %d-%d-%d\n", Days, Month, Year);
    fprintf(file3, "\n");

    fclose(file3);
	
	printf("New details: \n");
	printf("ID: %d\n", ID);
    printf("Age: %d\n", Age);
    printf("First name: %s\n", PatFirstName);
    printf("Second name: %s\n" , PatSecondName);
    printf("Gender: %c\n", Gender);
    printf("Phone Number: %s\n", PhoneNumber);
    printf("Patient Admit Date: %d-%d-%d\n", Days, Month, Year);
    printf("\n");
	
	char Choice[2];
	
	printf("Do you want to continue to Diagnostic function Y/N?");
	scanf("%s" , &Choice);
	Choice[0] = tolower(Choice[0]);
	if (Choice[0] == 'y'){
		Diagnostics();
	}
	else if(Choice[0] == 'n'){
	}
	
	printf("\nEnter mode \nC for Create a record \nE for edit record \nR for removing record \nP for Prescription and billing \nQ for exiting the program \n: ");
 }


int RemoveRecord(){
	system("cls");
	puts("Remove");
	char FileName[100];
	char record[100];
	FILE *file;
	file = fopen("RecordList.txt" , "r");
	if(file == NULL){
		perror("File does not exist");
	}
	printf("List of existing records: ");
	while(fgets(record , sizeof(record) , file ) !=NULL ){
		printf("\n%s " , record);
	}
	
	printf("\nEnter file name to remove: ");
   	scanf("%s" , &FileName);
        

	FILE *temp = fopen("Tempfile.txt" , "w");
	if (temp == NULL){
		printf("error in deletion process");
		fclose(file);
		return 1;
	}
	
	fseek(file , 0 , SEEK_SET);
	
	char fileline[MAX_LINE_LENGTH];
	while (fscanf(file , "%s" , fileline) != EOF){
		printf("....");
		if (strcmp(FileName, fileline) != 0) {
			fprintf(temp , "\n%s" ,fileline);
		}
    }
	
	
	fclose(file);
	fclose(temp);
	remove("RecordList.txt");
	rename("Tempfile.txt" , "RecordList.txt");
	
	FILE *file_to_delete = fopen(FileName, "r");
    if (file_to_delete == NULL){
        perror("File does not exist");
    }
    else {
        fclose(file_to_delete);
        if (remove(FileName) == 0) {
            printf("File '%s' deleted successfully.\n", FileName);
        } 
        else{
            perror("Error deleting file");
        }
    }
			
    printf("\nEnter mode \nC for Create a record \nE for edit record \nR for removing record \nP for Prescription and billing \nQ for exiting the program \n: ");
    
	return 0;
}


void Diagnostics(){
	system("cls");
	
	puts("Diagnostic assistance: \n");
	
	char record[100];
	
	FILE *file2;
	file2 = fopen("RecordList.txt" , "r");
	if(file2 == NULL){
		perror("File does not exist");
	}
	printf("List of existing records: ");
	while(fgets(record , sizeof(record) , file2 ) !=NULL ){
		printf("\n%s " , record);
	}
	fclose(file2);
		
	char Patrecord[100];
	printf("\nEnter patient record name for diagnostics: ");
	scanf("%s" , &Patrecord);
	
	FILE *file = fopen(Patrecord, "a");
	printf("Current directory: ");
	system("cd");
	
	if (file == NULL){
		perror("Error opening file");	
	}
	else{
		printf("File opened\n");
	}
		
	int temp;
	
	
	printf("Enter patient recorded temperature: ");
	scanf("%d" , &temp);
	
	int i, j;
    int stringCount = 0;
    char** SymptArray = NULL;
	
	while ((getchar()) != '\n');
	
    while (1) {
        stringCount++;
        SymptArray = (char**)realloc(SymptArray, stringCount * sizeof(char*));
        if (SymptArray == NULL) {
            printf("Error...");
            exit(1);
        }
		
        char symptom[50];
        printf("Enter a symptom (or type 'exit' to stop): ");
        fgets(symptom, 50, stdin);
		int k;
		
		while(symptom[k] != '\0'){
			k++;
		}
		
		for ( i = 0 ; i < k ; i++){
			symptom[i] = tolower(symptom[i]);
		}
		
        if (strcmp(symptom, "exit\n") == 0) {
            break;
        }

        SymptArray[stringCount - 1] = (char*)malloc((strlen(symptom) + 1) * sizeof(char));
        strcpy(SymptArray[stringCount - 1], symptom);
    }

    for (j = 0; j < stringCount - 1  ; j++) {
        printf("Symptom %d: %s\n", j + 1, SymptArray[j]);
    }
	    
	
	fprintf(file, "Patient Recorded temperature: %d", temp);
	fprintf(file , "\n" , NULL);
	
	int k;
	for (k = 0 ; k < stringCount - 1; k++){
		fprintf(file , "%s\n" , SymptArray[k]);
	}
	
	fclose(file);
    
    for (i = 0; i < stringCount - 1; i++){
    	free(SymptArray[i]);
    }
    free(SymptArray);
    
}


int PrescNBills(){
	
	system("cls");
	
	char details[100];
	char Medicines[10][2][100];
	FILE *rec;
	rec = fopen("RecordList.txt" , "r");
	while (fgets(details , sizeof(details) , rec)){
		printf("\n%s" , details);
	}
	fclose(rec);
	char Filename[100];
	
	printf("\nEnter file name to prescribe medicine: ");
	scanf("%s" , &Filename);
	FILE *file;
	file  = fopen(Filename , "r");
	if (file == NULL){
		perror("File not found");
		return 1;
	}
	rewind(rec);
	
	while (fgets(details , sizeof(details) , rec)){
		printf("\n%s" , details);
	}
	fclose(file);
	
	
	FILE *file2;
	file2 = fopen(Filename , "a");
	
	if (file2 == NULL){
		perror("Error opening file");
		return 1;
	}
	else{
		printf("File opened sucessfully");
	}
	
	fprintf(file2 , "\nMedicine Prescription: " , NULL);
	strcpy(Medicines[0][0] , "softin 10mg");
	strcpy(Medicines[0][1] , "95");
	strcpy(Medicines[1][0] , "rijiks");
	strcpy(Medicines[1][1] , "240");
	strcpy(Medicines[2][0] , "siroline 120ml");
	strcpy(Medicines[2][1] , "65");
	strcpy(Medicines[3][0] , "coferb 120ml");
	strcpy(Medicines[3][1] , "250");
	strcpy(Medicines[4][0] , "gaviniscon 120");
	strcpy(Medicines[4][1] , "120");
	strcpy(Medicines[5][0] , "panadol 500mg");
	strcpy(Medicines[5][1] , "640");
	strcpy(Medicines[6][0] , "azomax");
	strcpy(Medicines[6][1] , "625");
	strcpy(Medicines[7][0] , "tylenol 500mg 10ct");
	strcpy(Medicines[7][1] , "545");
	strcpy(Medicines[8][0] , "leozin 5mg");
	strcpy(Medicines[8][1] , "120");
	strcpy(Medicines[9][0] , "vicks 19g");
	strcpy(Medicines[9][1] , "55");
	int i;
	printf("\nMedicine available: ");
	for ( i = 0 ; i < 10 ; i++){
		printf("\n%s" , Medicines[i][0]);
	}	
	int flag = 0;
	int flag2 = 0;
	int j ;
	char Med[100];
	int price , total = 0;
	
	i = 0;
	
	while (flag == 0){		
		printf("\nEnter medicine, enter 'done' to exit process: ");
		gets(Med);
		flag2 = 0;
		if( i == 0){
			i++;
			continue;
		}
		if(strcmp(Med , "done") != 0){
			j = 0;
			while (flag2 == 0){
				if(strcmp(Med , Medicines[j][0]) == 0){
					flag2 = 1;
					price = atoi(Medicines[j][1]);
					total = total + price;
					fprintf(file2 , "\n%s : %d" ,Med , price);
				}
				j++;
			}
		}
		else{
			flag = 1;
		}
		i++;
	}
	
	printf("total is : %d" , total);
	fprintf(file2 , "\nTotal is : %d" , total);
	
	fclose(file2);
	printf("\nEnter mode \nC for Create a record \nE for edit record \nR for removing record \nD for diagnostic assistance \nP for Prescription and billing \nQ for exiting the program \n: ");
}

void main(){
	char Choice[2];
	char DrName[100];
	char compChar[2];
	printf("Enter your name: ");
	gets(DrName);
	printf("Welcome Dr %s" , DrName);
	
	printf("\nEnter mode \nC for Create a record \nE for edit record \nR for removing record \nP for Prescription and billing\nQ for exiting the program : ");
    fgets(Choice, sizeof(Choice), stdin);
   	while (Choice[0] != 'Q'){
   		Choice[0] = tolower(Choice[0]);
        switch (Choice[0]) {
            case 'c':
                CreateRecord();
                break;
            case 'e':
                EditRecord();
                break;
			case 'r':
				RemoveRecord();
				break;
            case 'p':
                PrescNBills();
                break;
        	}
    	fgets(Choice, sizeof(Choice), stdin);
    }   
}


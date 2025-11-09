#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct employee{
    char name[20]; 
    int id; 
    int salary; 
    int experience; 
};
int details(struct employee *p,int); 
int sorting(struct employee *k,int);
int highest_salary(struct employee *a,int);
int experience(struct employee *b,int);
int choice(struct employee *y,int); 
int main(){
    printf("         ~~~~~~=== WELCOME TO DELTA INDUSTRIES ===~~~~~~        \n");
    int n; 
    printf("ENTER THE NUMBER OF EMPLOYEES WORKING : "); 
    scanf("%i",&n); 
    printf("\n");
    struct employee x[n];
    printf("TOTAL EMPLOYEES ARE %i\n",n);
    printf("\n");
    printf("ENTER THE EMPLOYEE DETAILS \n");
    for(int i = 0 ; i < n ; i++){
        printf("\n");
        printf("EMPLOYEE : %i\n",i+1);
        printf(" enter the name of employee %i:",i+1); 
        scanf("%s",x[i].name);
        printf(" enter the id employee %i:",i+1); 
        scanf("%i",&x[i].id); 
        printf(" enter the salary employee %i:",i+1); 
        scanf("%i",&x[i].salary); 
        printf(" enter the experience of employee %i:",i+1); 
        scanf("%i",&x[i].experience);
    }
    printf("\n");
    choice(x,n);
    return 0;
}


/// main using function 
int choice(struct employee *y,int size){
    int n;
    printf(" 1(choice) for all employee details\n\n"); 
    printf(" 2(choice) for printing the employees by salary wise(ascending order)\n\n");
    printf(" 3(choice) for highest salary employee details\n\n"); 
    printf(" 4(choice) high experience employee\n\n");
    printf("\n");
    printf("ENTER YOUR CHOICE  (1/2/3/4) :"); 
    scanf("%i",&n); 
    printf("     ~~~~~~ THANK YOU FOR GIVING US DETAILS ~~~~~~");
    if(n == 1){
        details(y,size);
    }
    else if(n == 2){
        sorting(y,size);
    }
    else if(n == 3){
        highest_salary(y,size); 
    }
    else{
        experience(y,size);
    }
    return 0;

}


/// full details
int details(struct employee *p,int size){
    FILE *f; 
    f = fopen("data.txt","w"); 
    if (f == NULL){
        printf("file is not created\n");
        return 1;
    }
    fprintf(f,"  _______DETAILS OF THE EMPLOYEES______   \n");
    for(int i = 0 ; i < size ; i++){
        fprintf(f,"NAME : %s\n",(p+i)->name);
        fprintf(f,"ID : %i\n",(p+i)->id); 
        fprintf(f,"SALARY : %i\n",(p+i)->salary); 
        fprintf(f,"EXPERIENCE : %i\n\n\n",(p+i)->experience); 

    }
    fclose(f);
    return 0; 
}


/// sorting details
int sorting(struct employee *k,int size){
    FILE *f; 
    f = fopen("data.txt","w"); 
    if (f == NULL){
        printf("file is not created\n");
        return 1;
    }
    fprintf(f,"  _______**AFTER SORTED BY SALARY**_______   \n"); 
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size-1 ;j++){
            struct employee temp;
            if((k+j)->salary > (k+j+1)->salary){
                temp = *(k+j+1);
                *(k+j+1) = *(k+j); 
                *(k+j) = temp; 
            }
        }
    }
    for(int i = 0 ; i < size ; i++){
        fprintf(f,"NAME : %s\n",(k+i)->name);
        fprintf(f,"ID : %i\n",(k+i)->id); 
        fprintf(f,"SALARY : %i\n",(k+i)->salary); 
        fprintf(f,"EXPERIENCE : %i\n\n\n",(k+i)->experience); 
    }
    fclose(f);
    return 0;
}


/// highest salary 
int highest_salary(struct employee *a,int size){
    FILE *f; 
    f = fopen("data.txt","w"); 
    if (f == NULL){
        printf("file is not created\n");
        return 1;
    }
    fprintf(f," ______*** EMPLOYEE WITH HIGHEST SALARY ***______ :\n"); 
    int max = (a)->salary;
    int index = 0;
    for(int i = 0 ; i < size; i++){
        if(max < (a+i)->salary){
            max = (a+i)->salary;
            index = i;
        }
    }
    fprintf(f,"NAME : %s\n",(a+index)->name);
    fprintf(f,"ID : %i\n",(a+index)->id); 
    fprintf(f,"SALARY : %i\n",(a+index)->salary); 
    fprintf(f,"EXPERIENCE : %i\n\n\n",(a+index)->experience); 
    return 0;

}


///experience checking 
int experience(struct employee *b,int size){
    FILE *f; 
    f = fopen("data.txt","w"); 
    if (f == NULL){
        printf("file is not created\n");
        return 1;
    }
    fprintf(f,"  _____~~~ EMPLOYEE WITH HIGH EXPERIENCE ~~~_____ :\n"); 
    int max = (b)->experience;
    int index = 0;
    for(int i = 0 ; i < size; i++){
        if(max < (b+i)->experience){
            max = (b+i)->experience;
            index = i;
        }
    }
    fprintf(f,"NAME : %s\n",(b+index)->name);
    fprintf(f,"ID : %i\n",(b+index)->id); 
    fprintf(f,"SALARY : %i\n",(b+index)->salary); 
    fprintf(f,"EXPERIENCE : %i\n\n\n",(b+index)->experience); 
    printf("\n"); 
    printf("\n");
    return 0;
    
}
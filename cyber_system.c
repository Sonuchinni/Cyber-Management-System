#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>

void heading();
void main_heading();
void menu();
void user_menu();
void insert();
void display();
void search();
void delete();
void arrival_time();
void user_login();
void login_user();


void main()
{
    char name[30];
    int id;
    int ch;
    char username[20];
    char password[20];

    system("CLS");
    system("color 8F");
    heading();
    printf("\n\n\t\t\t\t\t1. Login as an admin");
    printf("\n\t\t\t\t\t2. Login as an user");
    printf("\n\t\t\t\t\t3. Exit");
    printf("\n\n\t\t\t\t\tEnter your choice (1/2) : ");
    scanf("%d",&ch);
    system("CLS");

    switch(ch)
    {
        case 1 :system("CLS");
                heading();
                printf("\n\n\t\t\t\t\t\t ||  ADMIN   LOGIN  ||\t\t\t\t");
                printf("\n\n\t\t\t\t\tEnter the username : ");
                scanf("%s",&username);
                printf("\n\t\t\t\t\tEnter the password : ");
                scanf("%s",&password);

                if(strcmp(username, "admin")==0)
                {
                    if(strcmp(password,"cyber123")==0)
                    {
                        system("CLS");
                        main_heading();
                        printf("\n\n\t\t\t\t\t\tWELCOME  ADMIN!!!   LOGIN SUCCESSFULL");
                        menu();
                    }
                    else
                    {
                        printf("\n\n\t\t\t\t\tIncorrect password. Failed to login ");
                    }
                }
                else
                {
                    printf("\n\n\t\t\t\t\tIncorrect username. Failed to login ");
                }
                break;

        case 2 :system("CLS");
                heading();
                int cho;
                printf("\n\n\t\t\t\t\t1. Sign in");
                printf("\n\t\t\t\t\t2. New user? Sign up");
                printf("\n\n\t\t\t\t\tEnter your choice (1/2) : ");
                scanf("%d",&cho);
                switch(cho)
                {
                    case 1 :printf("\n\n\t\t\t\t\t ||  USER   LOGIN  ||\t\t\t\t");
                            main_heading();
                            login_user();
                            break;

                    case 2 :system("CLS");
                            main_heading();
                            user_login();
                            break;

                    default : printf("INVALID CHOICE");
                            break;
                }

        case 3 : exit(0);
                break;
    }
}
    
void heading()
{
        printf("\n\t\t\t\t\t--------------------------------------------------------\t\t\t\t");
        printf("\n\t\t\t\t\t|          WELCOME TO CYBER MANAGEMENT SYSTEM          |\t\t\t\t");
        printf("\n\t\t\t\t\t--------------------------------------------------------\t\t\t\t");
}

void main_heading()
{
        printf("\n\t\t\t\t\t--------------------------------------------------------\t\t\t\t");
        printf("\n\t\t\t\t\t|                CYBER MANAGEMENT SYSTEM               |\t\t\t\t");
        printf("\n\t\t\t\t\t--------------------------------------------------------\t\t\t\t");
}

void menu()
{
        int choice;
        printf("\n\n\t\t\t\t\t\t|<----MENU---->|\t\t\t\t");
        printf("\n\n\t\t\t\t\t\t1.  Insert record");
        printf("\n\n\t\t\t\t\t\t2.  Display record");
        printf("\n\n\t\t\t\t\t\t3.  Search record");
        printf("\n\n\t\t\t\t\t\t4.  Delete record");
        printf("\n\n\t\t\t\t\t\t5.  Exit");
        printf("\n\n\t\t\t\t\t\tEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :system("CLS");
                    insert();
                    break;

            case 2 :system("CLS");
                    main_heading();
                    display();
                    printf("\n\n\t\t\t\t\t\tPress any key to continue");
                    fflush(stdin);
                    getchar();
                    menu();

            case 3 :system("CLS");
                    search();
                    printf("\n\n\t\t\t\t\t\tPress any key to continue");
                    fflush(stdin);
                    getchar();
                    menu();
                    break;

            case 4 :system("CLS");
                    delete();
                    break;

            case 5 :system("CLS");
                    exit(0);
                    break; 

            default : printf("INVALID CHOICE");           
        }
}

void user_menu()
{
    int choice;
    printf("\n\n\t\t\t\t\t\t |<----MENU---->|\t\t\t\t");
    printf("\n\n\t\t\t\t\t\t1.  View the record");
    printf("\n\n\t\t\t\t\t\t2.  Exit");
    printf("\n\n\t\t\t\t\t\tEnter your choice (1/2) : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 :system("CLS");
                search();
                break; 

        case 2 :system("CLS");
                exit(0);
                break; 
    }
}

void insert()
{
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);

    FILE *fp;
    char name[30];
    int id;
    char choice='y';
    system("CLS");
    fp = fopen("cyber.txt","ab+");

    if(fp==NULL)
    {
        printf("\n\n\t\t\t\t\t\tError opening file");
        return;
    }
    fflush(stdin);
    while(choice=='y')
    {
        main_heading;
        printf("\n\n\t\t\t\t\t\tENTER USER DATA ");
        printf("\n\n\t\t\t\t\t\tEnter user id : ");
        scanf("%d",&id);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tEnter name of the user : ");
        scanf("%s",&name);
        fflush(stdin);
        fprintf(fp,"%d %s\t",id,name);
        fprintf(fp,"%0.2d/%0.2d/%d %0.2d:%0.2d",current_time->tm_mday,current_time->tm_mon+1,current_time->tm_year+1900,current_time->tm_hour,current_time->tm_min);
        fprintf(fp,"\n");
        arrival_time();
        printf("\n\n\t\t\t\t\t\t USER RECORD INSERTED SUCCESSFULLY !!!");
        printf("\n\n\t\t\t\t\t\t Want to add another record ? (y/n) : ");
        scanf("%c",&choice);
        fflush(stdin);
        system("CLS");
        fflush(stdin);
    }
    fclose(fp);
    printf("\n\n\t\t\t\t\t\t       Press any key to continue ");
    getchar();
    menu();
}

void display()
{
    int duration,tothr;
    int totmin;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp;
    fp = fopen("cyber.txt","rb");

    if(fp==NULL)
    {
        printf("\n\n\t\t\t\t\t\tError opening file");
        return;
    }

    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    printf("\n\n\t\t\t\t\t\tUser details are as follows");
    printf("\n\n\t\t\tUser id\t\tName of the user\t\tDate\t\tTime\t\tDuration");

    while(fscanf(fp,"%d %s %0.2d/%0.2d/%d %0.2d:%0.2d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        printf("\n\n\t\t\t%d\t\t%s\t\t%0.2d/%0.2d/%d\t\t%0.2d:%0.2d",id,name,mday,mmon,myear,mhour,mmin);
        tothr = (((current_time->tm_hour*60)+(current_time->tm_min))-((mhour*60)+mmin));
        duration =tothr/60;
        totmin = tothr-(duration*60);
        printf("\t %dHr : %dMin",duration,totmin);
    }
    fclose(fp);
}

void search()
{
    system("CLS");
    main_heading;
    int my_id,flag=0;
    int duration,tothr;
    int totmin;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp;
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    fp = fopen("cyber.txt","rb");

    if(fp==NULL)
    {
        printf("\n\n\t\t\t\t\t\tError opening file");
        return;
    }

    printf("\n\n\t\t\t\t\t\tEnter user id to fetch information : ");
    scanf("%d",&my_id);
    while(fscanf(fp,"%d %s %0.2d/%0.2d/%d %0.2d:%0.2d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        if(my_id == id)
        {
            flag=1;
            printf("\n\n\t\t\t\t\t\tRECORD FOUND SUCCESSFULLY !!!");
            printf("\n\n\t\t\t\t\t\tUser id : %d",id);
            printf("\n\n\t\t\t\t\t\tName of the user : %s",name);
            printf("\n\n\t\t\t\t\t\tLogin date and time : %0.2d/%0.2d/%d   %0.2d:%0.2d",mday,mmon,myear,mhour,mmin);
            tothr = (((current_time->tm_hour*60)+(current_time->tm_min))-((mhour*60)+mmin));
            duration =tothr/60;
            totmin = tothr-(duration*60);
            printf("\t %dHr : %dMin",duration,totmin);

            if(tothr>300)
            {
                printf("\n\n\t\t\t\t\t\tALERT!!! MALICIOUS ACTIVITY");
            }
            break;
        }
    }
    fclose(fp);
    if(flag==0)
    {
        printf("\n\n\t\t\t\t\t\tRecord not found!!!");
        Sleep(10);
        main();
    }
}

void delete()
{
    system("CLS");
    main_heading;
    int my_id;
    int duration,tothr;
    int totmin;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp,*ft;
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    unsigned flag=0;
    fp = fopen("cyber.txt","rb");

    if(fp==NULL)
    {
        printf("\n\n\t\t\t\t\t\tError opening file");
        return;
    }
    printf("\n\n\t\t\t\t\t\t |------PREVIOUSLY ENTERED DATA------|\t\t\t\t");
    display();
    printf("\n\n\t\t\t\t\t\tEnter id of the user which you want to delete : ");
    scanf("%d",&my_id);

    ft = fopen("cyber.txt","wb");

    if(ft==NULL)
    {
        printf("\n\n\t\t\t\t\t\tError opening file");
        return;
    }

    while(fscanf(fp,"%d %s %0.2d/%0.2d/%d %0.2d:%0.2d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        if(my_id != id)
        {
            flag=1;
            fprintf(fp,"%d %s\t",id,name);
            fprintf(fp,"%0.2d/%0.2d/%d %0.2d:%0.2d",mday,mmon,myear,mhour,mmin);
            fprintf(fp,"\n");
        }
    }

    if(flag==0)
    {
        printf("\n\n\t\t\t\t\t\tNo such record found!!!");
    }
    fclose(fp);
    fclose(ft);
    remove("cyber.txt");
    rename("cyber1.txt","cyber.txt");
    printf("\n\n\t\t\t\t\t\tRecord Deleted Successfully!!!");
    printf("\n\n\t\t\t\t\t\t |------UPDATED RECORDS------|\t\t\t\t");
    display();
    printf("\n\n\t\t\t\t\t\t       Press any key to continue ");
    fflush(stdin);
    getchar();
    system("CLS");
    main_heading;
    menu();
}

void arrival_time()
{
    time_t rawtime;
    struct tm* timeinfo;
    struct tm* dateinfo;
    char buf[80];
    char buffer[80];
    FILE *fp;
    fp = fopen("cyber.txt","ab+");

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    dateinfo = localtime(&rawtime);

    strftime(buffer, 80, "%I:%M:%S",timeinfo);
    strftime(buf, 80, "%b %d, %Y",dateinfo);
    printf("\n\n\t\t\t\t\tARRIVAL TIME : %s",buffer);
    printf("\t\tDATE : %s",buf);
}

void user_login()
{
    char usern[20],pass[20];
    FILE *fp;
    fp = fopen("login.txt","ab+");
    printf("\n\t\t\t\t\tSIGN IN USER");
    printf("\n\t\t\t\t\tEnter user name : ");
    scanf("%s",&usern);
    printf("\n\t\t\t\t\tEnter password : ");
    scanf("%s",&pass);
    fprintf(fp,"%s %s",usern,pass);
    fprintf(fp,"\n");
    system("CLS");
    printf("\n\t\t\t\t\t\t\tSuccessfully signed in ");
    user_menu();
}

void login_user()
{
    char u_id[20],p[20];
    char usern[20],pass[20];
    FILE *fp;
    fp = fopen("login.txt","rb");
    printf("\nUser name : ");
    scanf("%s",u_id);

    while(fscanf(fp,"%s %s",&usern,&pass)!=EOF)
    {
        if(strcmp(u_id,usern)==0)
        {
            printf("Password : ");
            scanf("%s",&p);
            if(strcmp(p,pass)==0)
            {
                system("CLS");
                main_heading;
                printf("\n\t\t\t\t\tWELCOME USER !!!  LOGIN SUCCESSFUL");
                printf("\n\n");
                user_menu();
                printf("\n\t\t\t\t\tPress any key to continue");
                fflush(stdin);
                getchar();
                user_menu();
            }
            else
            {
                printf("\n\t\t\t\t\tIncorrect username or password");
                printf("\n\t\t\t\t\tTry again");
                login_user();
            }
        }
        printf("\nIncorrect username!!! Try again");
        user_login();
    }
}
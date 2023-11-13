#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st{
    int roll;
    char name[20];
    float marks;
    struct st *next;
}ST;

int number(int *, ST *, int);
void add_end(ST **);
void sort(ST *);
void modify(ST **);
void show(ST *, ST **);
int count(ST *);
void print(ST *);
void rev_link(ST **);
void delete(ST **);
void deleteall(ST **);
void save(ST *);

int main(){
    char ch;
    int flag = 0;
    ST *hptr = 0;
    while(1){
        print("---------------------------------\n");
        print("| *****STUDENT RECORD MENU***** |\n");
        print("---------------------------------\n");
        print("| a/A    : Add new record       |\n");
        print("| d/D    : Delete a record      |\n");
        print("| s/S    : Show the list        |\n");
        print("| m/M    : Modify a record      |\n");
        print("| v/V    : Save                 |\n");
        print("| e/E    : Exit                 |\n");
        print("| t/T    : Sort the list        |\n");
        print("| l/L    : Delete all records   |\n");
        print("| r/R    : Reverse the list     |\n");
        print("|                               |\n");
        print("| Enter your choice             |\n");
        print("---------------------------------\n");

        char ch;
        scanf(" %c",&ch);
label:  switch (ch)
        {
            case 'A':
            case 'a':   add_end(&hptr);
                        break;
            case 'D':
            case 'd':   delete(&hptr);
                        break;
            case 'S':
            case 's':   show(hptr, &hptr);
                        break;
            case 'M':
            case 'm':   modify(&hptr);
                        break;
            case 'V':
            case 'v':   save(hptr);
                        break;
            case 'E':
            case 'e':   print("\n");
                        puts("------------------------------");
                        puts("| Enter                      |");
                        puts("| s/S: Save and exit         |");
                        puts("| e/E: Exit without saving   |");
                        puts("------------------------------");
                        prints("\n");

                        scanf(" %c", &ch);
                        if((ch == 's') ||  (ch == 'S')){
                            ch = 'v';
                            if(flag == 0)
                            flag = 1;
                            goto label;
                        }
                        else if((ch == 'e') || (ch == 'E'))
                        return;
            case 'T':
            case 't':   sort(hptr);
                        break;
            case 'L':
            case 'l':   deleteall(&hptr);
                        break;
            case 'R':
            case 'r':   rev_link(&hptr);
                        break;
            default:    printf("Invalid Choice\n");
                        break;
        }
    }
}

void delete(ST **ptr){
    ST *temp = *ptr, *prv, *f;
    char ch;
    int count = 0;

lbl:printf("\n");
    printf("|---------------------------|\n");
    printf("| r/R : delete by roll      |\n");
    printf("| n/N : delete by name      |\n");
    printf("|                           |\n");
    printf("| Enter the choice:         |\n");
    printf("|---------------------------|\n");
    printf("\n");

    scanf(" %c",&ch);
    switch(ch){
        case 'R':
        case 'r':   
rl:                 printf("Enter the roll you want to delete\n");
                    int roll = 0;
                    scanf("%d", &roll);

                    if(*ptr == 0){
                        printf("Empty linked list, nothing to delete\n");
                        return;
                    }

                    while(temp != 0){
                        if(temp->roll == roll)
                        count++;
                    }

                    if(count > 1){
                        printf("More than 1 record is founf\n");
                        goto nm;
                    }
                    else{
                        temp = *ptr;
                        while(temp != 0){
                            if(temp->roll == roll){
                                if(temp == *ptr)
                                *ptr = temo->next;
                                else
                                prv->next = temp->next;

                                free(temp);
                                temp = Null;
                                return;
                            }
                            else{
                                prv = temp;
                                temp = temp->next;
                            }
                        }
                    }
                    break;
        case 'N':
        case 'n':   
nm:                 printf("Enter the name you want to delete\n");
                    char nam[20];
                    scanf("%s",nam);

                    temp = *ptr;
                    int flag = 0, c = 0;
                    while(temo != 0){
                        if((strcmp(temp->name, nam)) == 0){
                            if(c == 0)
                            f = temp;

                            c++;
                            printf("%d %s %f\n", temp->roll, temp->name, temp->marks);
                        }
                        prv = temp;
                        temp = temp->next;
                    }

                    if(c > 1){
                        printf("More than 1 record are found\n");
                        goto rl;
                    }
                    else if(c == 1){
                        flag = 1;
                        if(*ptr == 0){
                            printf("Empty linked list, nothing to delete\n");
                            return;
                        }

                        while(temp != 0){
                            if(strstr(temp->name,nam)){
                                if(temp == *ptr)
                                *ptr = temp->next;
                                else
                                prv->next = temp->next;

                                free(temp);
                                temp = NULL;
                                return;
                            }
                            else{
                                prv = temp;
                                temp = temp->next;
                            }
                        }
                    }
                    else{
                        printf("Data not found\n");
                    }

                    if(flag == 1)
                    printf("Data deleted successfully\n");
                    break;
        default:    printf("Invalid choice..\n");
                    printf("Choose valid option..\n");
                    goto lbl;
                    break;        
    }
}

void modify(ST **ptr){
    if(*ptr == 0){
        printf("No data is linked yet\n");
        return;
    }

    ST *temp = *ptr, *prv, *found;
    int n = 0, flag = 0, c = 0;
    float f;
    char ch, name[20];

opt:printf("\n");
    printf("---------------------------------------------\n");
    printf("| Enter which record you want to modify:    |\n");
    printf("| r/R: Roll                                 |\n");
    printf("| n/N: Name                                 |\n");
    printf("| p/P: Percentage                           |\n");
    printf("---------------------------------------------\n");
    printf("\n");

    scanf(" %c", &ch);

    switch(ch){
        case 'r':
        case 'R':
rol:                printf("Enter the roll\n");
                    scanf("%d",&n);
                    
                    temp = *ptr;
                    flag = 0;

                    while(temp != 0){
                        if(temp->roll == n){
                            printf("Enter the new name and marks\n");
                            scanf(" %s%f",temp->name, &temp->marks);

                            flag = 1;
                            break;
                        }
                        else{
                            prv = temp;
                            temp = temp->next;
                        }
                    }
                    if(flag == 1)
                    printf("Data modified successfully\n");
                    else
                    printf("Data not found\n");
                    break;
        case 'n':
        case 'N':   printf("Enter the name to search the record\n");
                    scanf(" %s",name);
                    temp = *ptr;
                    flag = 0;

                    while(temp != 0){
                        if((strcmp(temp->name,name)) == 0){
                            if(c == 0)
                            found = temp;

                            c++;
                            printf("%d %s %f\n", temp->roll, temp->name, temp->marks);
                        }
                        prv = temp;
                        temp = temp->next;
                    }

                    if(c > 1){
                        printf("More than one record's are found\n");
                        goto rol;
                    }
                    else if(c == 1){
                        printf("Enter the new name and marks\n");
                        scanf(" %s%f", found->name, &found->marks);
                        flag = 1;
                    }
                    else 
                    printf("Data not found\n");

                    if(flag == 1)
                    printf("Data modified successfully\n");

                    break;
        case 'p':
        case 'P':   printf("ENter the marks\n");
                    scanf("%f", &f);

                    temp = *ptr;
                    flag = 0;

                    while(temp != 0){
                        if(temp->marks == f){
                            if(c == 0)
                            found = temp;
                            
                            c++;
                            printf("%d %s %f\n", temp->roll, temp->name, temp->marks);
                        }
                        prv = temp;
                        temp = temp->next;
                    }

                    if(c > 1){
                        printf("More than one record are found\n");
                        goto rol;
                    }
                    else if(c == 1){
                        printf("Enter the new name and marks\n");
                        scanf(" %s%f", found->name, &found->marks);
                        flag = 1;
                    }
                    else
                    printf("Data not found\n");

                    if(flag == 1)
                    printf("Data modified successfully\n");
                    break;

        default:    printf("Invalid option..\n");
                    printf("Choose valid option..\n");
                    goto opt;
                    break;            
    }
}

void add_end(ST **ptr){
    static int i = 1;
    if(!(*ptr == 0)){
        int c = count(*ptr), ab[c];
        i = number(ab, *ptr, c);
    }
    ST *temp;
    temp = (ST *)malloc(sizeof(ST));
    temp->roll = i;

    printf("Enter the name & marks\n");
    scanf(" %s%f", temp->name, &temp->marks);

    if(*ptr == 0){
        temp->next = *ptr;
        *ptr = temp;
    }
    else{
        ST *last = *ptr;

        while(last->next != 0)
        last = last->next;

        temp->next = last->next;
        last->next = temp;
    }
}

int number(int *p, ST *P, int c)
{
    int i = 0, j = 0, t = 1;
    for(i = 0; i < c; i++){
        p[i] = p->roll;
        P = P->next;
    } 
    for(i = 1; i <= c; i++){
        for(j = 0; j < c; j++){
            if(p[j] == t)
            t++;
        }
    }
    return t;
}
void sort(ST *ptr){
    int i = 0, j = 0;
    ST *temp;
    ST *last = NULL;

    if(ptr == NULL)
    return;

    do{
        i = 0;
        temp = ptr;
        while(temp->next != last){
            if(temp->roll > temp->next->roll){
                int t = temp->roll;
                temp->roll = temp->next->roll;
                temp->next->roll = t;
                i = 1;
            }
            temp = temp->next;
        }
        last = temp;
    }while(i);
}

int count(ST *ptr){
    int c = 0;
    while(ptr != 0){
        ptr = ptr->next;
        c++;
    }
    return c;
}

void show(ST *ptr, ST **p)
{
    if(*p == 0){
        FILE *fp = fopen("hello.txt","r");
        if(fp == NULL){
            printf("File doesn't exist\n");
            return;
        }

        int x = 0;
        char ch[20], c;
        float f;

        while(fscanf(fp,"%d%s%f",&x,ch,&f) != -1){
            static int a = 1;
            ST *temp = (ST *)malloc(sizeof(ST));

            temp->roll = x;

            strcpy(temp->name, ch);
            temp->marks = f;

            if(*p == 0){
                temp->next = *p;
                *p = temp;
            }
            else{
                ST *last = *p;

                while(last->next != 0)
                last = last->next;

                temp->next = last->next;
                last->next = temp;
            }
        }
    }
    print(*p);
}

void print(ST *ptr){
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("|  Roll No  |         Name          |   Marks   |\n");
    printf("|-----------|-----------------------|-----------|\n");
    while(ptr != 0){
        printf("|     %d    |          %s           |    %f     |\n", ptr->roll, ptr->name, ptr->marks);
        ptr = ptr->next;
    }
    printf("|-----------|-----------------------|-----------|\n");
    printf("\n");
}

void rev_link(ST **ptr){
    int i = 0, C = count(*ptr);
    ST **p = (ST **)malloc(c * sizeof(ST *));
    ST *temp;

    temp = *ptr;
    for(i = 0; i < c; i++){
        p[i] = temp;
        temp = temp->next;
    }

    p[0] -> next = 0;

    for(i = 1; i < c; i++)
    p[i]->next = p[i-1];

    *ptr = p[c-1];
}

void deleteall(ST **ptr){
    ST *temp;
    while(*ptr != 0){
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }
}

void save(ST *ptr){
    File *fp = fopen("hello.txt","w");
    while(ptr != 0){
        fprintf(fp,"%d %s %f\n", ptr->roll, ptr->name, ptr->marks);
        ptr = ptr->next;
    }
}
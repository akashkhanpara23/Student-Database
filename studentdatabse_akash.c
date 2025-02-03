#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct st
{
    int roll;
    char name[20];
    float marks;
    struct st *next;
}ST;

int number (int *, ST *, int );
void add_end (ST **);
void sort(ST *);
void modify(ST **);
void show(ST *,ST **);
int count(ST *);
void print(ST *);
void rev_link(ST **);
void delete(ST **);
void deleteall(ST **);
void save(ST *);

int main()
{
    char ch; 
    int flag=0; 
    ST *hptr=0; 
    
    while(1)
    {    
        printf("-----------------------------\n");
        printf("****STUDENT RECORD MENU**** |\n");
        printf("-----------------------------\n");
        printf("| a/A : Add new record      |\n");
        printf("| d/D : delete a record     |\n");
        printf("| s/S : show the list       |\n");
        printf("| m/M : modify a record     |\n");
        printf("| v/V : save                |\n");
        printf("| e/E : exit                |\n");
        printf("| t/T : sort the list       |\n");
        printf("| l/L : delete all records  |\n");
        printf("| r/R : reverse the list    |\n");
        printf("|                           |\n");
        printf("| Enter your choice         |\n");
        printf("-----------------------------\n");
        
        char ch;
        scanf(" %c",&ch);

label:  switch(ch){
        
            case 'A':
            case 'a': add_end(&hptr);
            break;

            case 'D':
            case 'd': delete(&hptr);
            break;
        
            case 'S':
            case 's': show (hptr,&hptr);
            break;
        
            case 'M':
            case 'm': modify(&hptr); 
            break;

            case 'V':
            case 'v': save(hptr); 
            break;

            case 'E':
            case 'e':
                printf("\n");
                puts("---------------------------------");
                puts("| Enter                         |");
                puts("| s/S: Save and exit            |");
                puts("| e/E: Exit without Saving      |");
                puts("---------------------------------");
                printf("\n");

                scanf(" %c",&ch);

                if((ch == 's') || (ch == 's'))
                {
                    ch='v';
                    if(flag==0)
                    flag=1;
                    goto label;
                }    
                else if((ch == 'e') || (ch == 'E')) 
                exit(0);//return;

            case 'T':
            case 't': sort(hptr);
            break;
        
            case 'L': 
            case 'l': deleteall(&hptr);
            break;

            case 'R':
            case 'r': rev_link(&hptr);
            break;

            default:printf("Invalid choice\n");
            break;
        }
    }
}
void delete(ST **ptr) //Function call delete(&hptr, roll); 
{
    ST *temp = *ptr, *prv, *f;
    char ch;    
    int count;

lbl:    printf("\n");
        printf("|-----------------------|\n");
        printf("| r/R: delete by roll   |\n");
        printf("| n/N: delete by name   |\n");
        printf("|                       |\n"); 
        printf("| Enter the choice:     |\n"); 
        printf("|-----------------------|\n");
        printf("\n");

        scanf(" %c", &ch);
        
        switch(ch)
        {
            case 'R':
rl:         case 'r':printf("Enter the roll you want to delete\n");
                int roll; 
                scanf("%d",&roll);

                if(*ptr == 0)
                {
                    printf("Empty linked list, nothing to delete\n");
                    return;
                }
                while(temp != 0)
                {
                    if(temp->roll == roll)
                    count++;
                }
                if(count>1){
                    printf("More than 1 record is found\n");
                    goto nm;
                }  
                else{
                    temp=*ptr;
                    while(temp != 0)
                    {
                        if(temp->roll == roll)
                        {
                            if(temp == *ptr)
                            *ptr = temp->next;
                            else
                            prv->next = temp->next;

                            free(temp);
                            temp = NULL;
                            return;
                        }
                        else
                        {
                            prv = temp;
                            temp = temp->next;
                        }
                    }
                }
                break;

            case 'N':
nm:         case 'n':printf("Enter the name you want to delete\n");
                char nam[20];
                scanf(" %s",nam);

                temp=*ptr;
                int flag=0,c=0;
                while(temp != 0)
                {
                    if((strcmp(temp->name, nam)) == 0)
                    {
                        if(c==0)
                        f=temp;
                        c++;

                        printf("%d %s %f\n", temp->roll, temp->name, temp->marks);
                    }
                    prv = temp;
                    temp = temp->next;
                }
                if(c>1){
                    printf("More than 1 record are found\n");
                    goto rl;
                }
                else if(c==1){
                    flag=1;
                    if(*ptr == 0){
                        printf("Empty linked list, nothing to delete\n");
                        return;
                    }
                    while(temp != 0){
                        if(strstr(temp->name, nam)){
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
                else
                printf("Data not found\n");

                if(flag==1) 
                printf("Data deleted Successfully\n"); 
                break;

            default:printf("Invalid choice..\n"); 
                    printf("Choose valid option..\n");
                    goto lbl; 
                    break;
        }
}
void modify(ST **ptr)
{
    if(*ptr == 0){
        printf("No data is linked yet\n");
        return;
    }
    
    ST *temp = *ptr, *prv, *found;
    int n, flag,c=0;
    float f;
    char ch,name [20];

opt:    printf("\n");
        printf("---------------------------------------------\n");
        printf("| Enter which record you want to modify:    |\n");
        printf("| r/R: Roll                                 |\n");
        printf("| n/N: Name                                 |\n");
        printf("| p/P: Percentage                           |\n");
        printf("----------------------------------------- ---\n");
        printf("\n");
        scanf(" %c", &ch);
        switch (ch)
        {
            case 'r':
rol:        case 'R': printf("Enter the roll\n");
                    scanf("%d", &n);

                    temp = *ptr;
                    flag=0;
                    if(temp != 0){
                        if(temp->roll == n){
                            printf("Enter the New Name and Marks\n"); 
                            scanf(" %s%f", temp->name, &temp->marks);
                            flag=1;
                            break;
                        }
                        else{
                            prv = temp;
                            temp = temp->next; 
                        }
                    }
                    if(flag==1)
                    printf("Data modified Successfully\n");
                    else
                    printf("Data not found\n");
                    break;

            case 'n':
            case 'N':printf("Enter the Name to search the record\n");
                scanf(" %s", name);
                temp=*ptr;
                flag=0;
                while(temp != 0){
                    if((strcmp(temp->name, name)) == 0){
                        if(c==0)
                        found=temp;
                        
                        c++;
                        printf("%d %s %f\n", temp->roll, temp->name, temp->marks);
                    }    
                        prv = temp;
                        temp = temp->next;
                }
                if(c>1){
                    printf("More than 1 record's are found\n"); 
                    goto rol;
                }
                else if(c==1){
                    printf("Enter the New Name and Mark\n");
                    scanf(" %s%f", found->name, &found->marks);
                    flag=1;
                }
                else
                printf("Data not found\n");

                if(flag==1)
                printf("Data modified Successfully\n");
                break;

            case 'p':
            case 'P': printf("Enter the Mark\n"); 
                scanf("%f",&f); 
                temp=*ptr;
                flag=0;
                while(temp != 0){
                    if(temp->marks == f){
                        if(c==0)
                        found=temp;
                        
                        c++;
                        printf("%d %s %f\n", temp->roll, temp->name, temp->marks);
                    }
                    prv = temp;
                    temp = temp->next;
                }
                if(c>1){
                    printf("More than 1 record's are found..."); 
                    goto rol;
                }
                else if(c==1){
                    printf("Enter the New Name and Mark\n");
                    scanf(" %s%f",found->name, &found->marks);
                    flag=1;
                }
                else
                printf("Data not found\n");

                if(flag==1)
                printf("Data modified Successfully\n");
                break;
        
            default: printf("Invalid option..\n"); 
                printf("Choose valid option..\n"); 
                goto opt; 
                break;
        }
}

void add_end(ST **ptr)
{
    static int i=1;
    if(!(*ptr == 0))
    {
        int c=count(*ptr), ab[c];
        i=number (ab, *ptr,c);
    } 
    ST *temp;
    temp = (ST *)malloc(sizeof (ST)); 
    printf("Enter the name & marks\n"); 
    temp->roll=i;
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
    int i,j,t=1;
    for(i=0;i<c; i++)
    {
        p[i]=P->roll;
        P=P->next;
    }
    for (i=1;i<=c;i++)
    {
        for(j=0;j<c;j++) 
        if(p[j]==t) 
        t++;
    } 
    return t;
}
void sort(ST *ptr)
{
    int i,j;
    ST *temp;
    ST *last=NULL;

    if(ptr==NULL)
    return;

    do{
        i=0;
        temp=ptr;
        
        while(temp->next!=last){
            if(temp->roll > temp->next->roll){
                int t=temp->roll;
                temp->roll=temp->next->roll;
                temp->next->roll=t;
                i=1;
            }
            temp=temp->next;
        }
        last=temp;
    }while(i);
}
int count(ST *ptr)
{
    int c=0;
    while(ptr !=0){
        ptr=ptr->next;
        c++;
    }
    return c;
}
void show(ST *ptr,ST **p)
{
    if(*p==0)
    {
        FILE *fp=fopen("databaseRecord.txt","r");
        if(fp==NULL){
            printf("File doesn't exist\n");
            return;
        }
        int x;
        char ch[20],c;
        float f; 
        while(fscanf(fp, "%d %s %f",&x,ch,&f)!=-1)
        {
            static int a=1;
            ST *temp = (ST *)malloc(sizeof(ST));
            
            temp->roll=x;
            
            strcpy(temp->name,ch);
            temp->marks=f; 
            
            if(*p == 0){
            temp->next = *p;
            *p = temp;
            }
            else{
                ST *last = *p;
                
                while(last->next = 0) 
                last = last->next;

                temp->next = last->next;
                last->next = temp;
            }
        }
    } 
    print(*p);
}
void print(ST *ptr)
{
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("| %-8s | %-20s | %-10s |\n", "Roll No", "Name", "Marks"); // Header
    printf("|----------|----------------------|-------------|\n");
    while (ptr != 0)
    {
        char formattedName[21]; // 20 characters + 1 for null terminator
        snprintf(formattedName, sizeof(formattedName), "%.20s", ptr->name);
        printf("| %-8d | %-20s | %-10.2f |\n", ptr->roll, formattedName, ptr->marks); 
        ptr = ptr->next;
    }
    printf("--------------------------------------------------\n");
    printf("\n");
} 
void rev_link(ST **ptr)
{
    /*
    int i, c=count(*ptr);
    ST **p = (ST **)malloc(c*sizeof(ST *));
    ST *temp;
    temp=*ptr;
    for (i=0;i<c; i++){
        p[i]=temp;
        temp-temp->next;
    }
    p[0]->next=0;
    for (i=1;i<c;i++) 
    p[i]->next=p[i-1];

    *ptr=p[c-1];
    */
    ST* prev = NULL;
    ST* current = *ptr;
    ST* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    *ptr = prev;
} 
void deleteall(ST **ptr)
{
    ST *temp;
    while(*ptr != 0){
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }
}

void save(ST *ptr)
{
    FILE *fp=fopen("databaseRecord.txt","w");
    while(ptr!=0){
        fprintf(fp,"%d %s %f \n",ptr->roll,ptr->name,ptr->marks);
        ptr=ptr->next;
    }
}

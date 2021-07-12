#include <stdio.h>

struct contact
{
    long ph;
    char name[20], add[20], email[30];
}list;

char query[20], name[20];

int main()
{
    main:
    system("clear");        /* **********Main menu********** */
    printf("\n\n\n\t\tMAIN MENU\n\n\t=====================\n\t\t[1] Add new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t[0] Exit\n\t\t=====================\n\t\t");
    printf("Enter the choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 0:
            printf("\n\n\t\tAre you sure you want to exit?");
            break;
            /* **********Add new contacts********** */
        case 1:
            system("clear");
            fp = fopen("contact.dll", "a");
            
            for(;;)
            {
                setbuf(stdin, NULL);
                printf("To exit enter blank space in the name input\nName (Use identical): ");
                scanf("%[^\n]", &list.name);

                if(strcmp(list.name, " ") == 0 || strcmp(list.name, " ") == 0)
                    break;
                setbuf(stdin, NULL);
                printf("Phone: ");
                scanf("%ld", &list.ph);
                setbuf(stdin, NULL);
                printf("Address: ");
                scanf("%[^\n]", &list.add);
                setbuf(stdin, NULL);
                printf("Email Address: ");
                gets(lis.email);
                printf("\n");
                fwirte(&list, sizeof(list), 1, fp);
            }
            fclose(fp);
            break;
            /* ******************* List Of Contacts ******************* */

            case 2:
                system("clear");
                printf("\n\t\t=====================\n\t\t\tLIST OF CONTA")
    }
}
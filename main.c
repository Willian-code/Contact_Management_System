#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact
{
    long ph;
    char name[20], add[20], email[30];
}list;

char query[20], name[20];

FILE *fp, *ft;

int main()
{
    int i, n, ch, l, found;
    main:
    system("clear");        /* **********Main menu********** */
    printf("\n\t **** Welcome to Contact Management System ****");
    printf("\n\n\n\t\tMAIN MENU\n\n\t\t===================================\n\t\t[1] Add new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t===================================\n\t\t");
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
                fgets(list.name, 20, stdin);

                if(strcmp(list.name, " ") == 0 || strcmp(list.name, " ") == 0)
                    break;
                setbuf(stdin, NULL);
                printf("Phone: ");
                scanf("%ld", &list.ph);
                setbuf(stdin, NULL);
                printf("Address: ");
                fgets(list.add, 20, stdin);
                setbuf(stdin, NULL);
                printf("Email Address: ");
                fgets(list.email, 30, stdin);
                fwrite(&list, sizeof(list), 1, fp);
            }
            fclose(fp);
            break;
            /* ******************* List Of Contacts ******************* */

            case 2:
                system("clear");
                printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\n\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n================================\n\n");

                for(i = 97; i <= 122; i++)
                {
                    fp = fopen("contact.dll", "r");
                    setbuf(stdin, NULL);
                    found = 0;

                    while(fread(&list, sizeof(list), 1, fp) == 1)
                    {
                        if(list.name[0] == i || list.name[0] == i-32)
                        {
                            printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n", list.name, list.ph, list.add, list.email);
                            found++;
                        }
                    }
                    if(found != 0)
                    {
                        printf("=========================================================== [%c]-(%d)\n\n", i-32, found);
                        getchar();
                    }
                    fclose(fp);
                }
                break;
                /* **************************search contacts*************************** */
            case 3:
                system("clear");

                do
                {
                    found = 0;
                    printf("\n\n\t..::CONTACT SEARCH\n\t==========================\n\t..::Name of contact to search: ");
                    setbuf(stdin, NULL);
                    fgets(query, 20, stdin);
                    l = strlen(query);
                    fp = fopen("contact.dll", "r");
                    system("clear");
                    printf("\n\n..::Search result for '%s' \n==================================\n", query);

                    while(fread(&list, sizeof(list), 1, fp) == 1)
                    {
                        for(i = 0; i <= l; i++)
                            name[i] = list.name[i];
                        name[l] = '\0';

                        if(strcmp(name, query) == 0)
                        {
                            printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n", list.name, list.ph, list.add, list.email);
                            found++;
                            
                            if(found % 4 == 0)
                            {
                                printf("..::Press any key to continue...");
                                getchar();
                            }
                        }
                    }
                    if(found == 0)
                        printf("\n..::No match found!");
                    else
                        printf("\n..::%d match(s) found!", found);
                    fclose(fp);

                    printf("\n..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
                    scanf("%d", &ch);
                }
                while(ch == 1);
                break;
                /* ***********************edit contacts**************************** */
            case 4:
                system("clear");
                fp = fopen("contact.dll", "r");
                ft = fopen("temp.dat", "w");
                setbuf(stdin, NULL);
                printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit: ");
                scanf("%[^\n]", name);

                while(fread(&list, sizeof(list), 1, fp) == 1)
                {
                    if(strcmp(name, list.name) != 0)
                        fwrite(&list, sizeof(list), 1, ft);
                }
                setbuf(stdin, NULL);

                printf("\n\n..::Editing '%s' \n\n", name);
                printf("..::Name(Use identical): ");
                fgets(list.name, 20, stdin);
                setbuf(stdin, NULL);
                printf("..::Phone: ");
                scanf("%ld", &list.ph);
                setbuf(stdin, NULL);
                printf("..::address: ");
                fgets(list.add, 20, stdin);
                setbuf(stdin, NULL);
                printf("..::email address: ");
                fgets(list.email, 30, stdin);
                fwrite(&list, sizeof(list), 1, ft);
                fclose(fp);
                fclose(ft);
                remove("contact.dll");
                rename("temp.dat", "contact.dll");
                break;
                /* **********************delete contacts**************************** */
            case 5:
                system("clear");
                setbuf(stdin, NULL);
                printf("\n\n\t..::DELETE A CONTACT\n\t=============================\n\t..::Enter the name of contact to delete: ");
                fgets(name, 20, stdin);
                fp = fopen("contact.dll", "r");
                ft = fopen("temp.dat", "w");

                while(fread(&list, sizeof(list), 1, fp) != 0)
                {
                    if(strcmp(name, list.name) != 0)
                        fwrite(&list, sizeof(list), 1, ft);
                }
                fclose(fp);
                fclose(ft);
                remove("contact.dll");
                rename("temp.dat", "contact.dll");
                break;
            
            default:
                printf("Invalid choice");
                break;
    }
    printf("\n\n\n..::Enter the choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            goto main;
        
        case 0:
            break;
        
        default:
            printf("Invalid choice");
            break;
    }

    return(0);
}

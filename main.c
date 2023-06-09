#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "story.h"
#include "encryption.h"
#include "users.h"

#define MAX_USERNAME_LENGTH 30

int main(){
    char* user = malloc(MAX_USERNAME_LENGTH * sizeof(char));
	
	do {
		printf("Who is using this diary?\n");
		scanf("%s", user);
	} while (strlen(user) >= MAX_USERNAME_LENGTH);
    
    char* filename = login(user);
    char password[100];

    FILE* fdata = fopen(filename, "rb+");

    if(fdata == NULL){
        printf("Error. File can't open");
        return -1;
    }
    
    fseek(fdata, 0, SEEK_END);
    int file_size = ftell(fdata);
    rewind(fdata);

    printf("Enter password: ");
    scanf("%s", password);

    rewind(fdata);
    decrypt_file(fdata, &file_size, password);
    rewind(fdata);

    fclose(fdata);

    int choice;
    do{
        printf("Hello, sir/madam! This is the menu..\n");
        printf("1. Add a new story\n");
        printf("2. Display all stories\n");
        printf("3. Find a story by title\n");
        printf("4. Find a story by date\n");
        printf("5. Exit\n");

        printf("Enter your choice (1 - 5): ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                add_new_story(filename);
                break;

            case 2:
                display_stories(filename);
                break;

            case 3:
                display_story_by_title(filename);
                break;
            
            case 4:
                display_story_by_date(filename);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("\n");
    } while (choice != 5);

    fdata = fopen(filename, "rb+");

    fseek(fdata, 0, SEEK_END);
    file_size = ftell(fdata);

    rewind(fdata);
    encrypt_file(fdata, &file_size, password);
    rewind(fdata);

    return 0;
}

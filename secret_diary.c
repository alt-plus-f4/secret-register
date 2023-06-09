#include <stdio.h>

#include "story.h"

int main(){
    int choice;
    
    do{
        printf("Hello, sir/madam! This is the menu..\n");
        printf("1. Add a new story\n");
        printf("2. Display all stories\n");
        printf("3. Read a story by title\n");
        printf("4. Read a story by date\n");
        printf("5. Exit\n");

        printf("Enter your choice (1 - 5): ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                add_new_story();
                break;

            case 2:
                display_stories();
                break;

            case 3:
                display_story_by_title();
                break;
            
            case 4:
                display_story_by_date();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
        
        printf("\n");
    } while (choice != 5);
    
    return 0;
}

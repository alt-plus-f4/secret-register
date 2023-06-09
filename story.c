#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 30
#define MAX_STORY_LENGTH 1024
#define STORIES_PER_PAGE 10
#define MAX_LINE_LEN 1024

#include "story.h"

int is_valid_date(const char *date_str){
    int year, month, day;

    if (sscanf(date_str, "%d-%d-%d", &year, &month, &day) != 3)
        return 0;

    if (year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
        return 0;
    
    return 1;
}

void add_new_story(const char* filename){
    Story new_story;
    
    do{
        printf("Enter the date (YYYY-MM-DD): ");
        scanf("%10s", new_story.date);
        getchar();
    } while(!is_valid_date(new_story.date));

    printf("Enter the title(MAX %d characters): ", MAX_TITLE_LENGTH);
    scanf("%30[^\n]", new_story.title);
    getchar();
    
    printf("Write the story:\n");
    scanf(" %[^\n]", new_story.story);
    getchar();

    FILE *file = fopen(filename, "a");
    
    if (file != NULL) {
        fprintf(file, "%s|%s|%s\n", new_story.date, new_story.title, new_story.story);
        fclose(file);
        printf("Story successfully added.\n");
    } 

    else
        printf("Failed to open the file.\n");
}

void display_stories(const char* filename){
    FILE *file = fopen(filename, "r");

    if (file != NULL) {
        char line[MAX_LINE_LEN];
        int story_count = 1;
        int page = 1;

        printf("\n----- Page %d -----\n\n", page);
        
        while (fgets(line, sizeof(line), file) != NULL) {
            char *date = strtok(line, "|");
            char *title = strtok(NULL, "|");
            
            printf("\nDate: %s\nTitle: %s\n\n", date, title);
            
            story_count++;
            
            if (story_count == STORIES_PER_PAGE) {
                story_count = 1;
                page++;

                printf("Press ANY key to continue...");
                getchar();
                printf("\n----- Page %d -----\n\n", page);
            }
        }
        fclose(file);
    } 
    else
        printf("Failed to open the file.\n");
}

void display_story_by_date(const char* filename){
    char date[11];
    printf("Enter the date of the story: ");
    scanf("%10s", date);
    getchar();

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char line[MAX_LINE_LEN];
        
        while (fgets(line, sizeof(line), file) != NULL) {
            char *story_date = strtok(line, "|");
            char *story_title = strtok(NULL, "|");
            char *story_text = strtok(NULL, "|");
            
            if (strcmp(story_date, date) == 0 ) {
                printf("\nDate: %s\nTitle: %s\n\n%s\n", story_date, story_title, story_text);
                fclose(file);
                return;
            }
        }
        fclose(file);
        printf("Story not found.\n");
    } 
    else
        printf("Failed to open the file.\n");
}

void display_story_by_title(const char* filename){
    char title[MAX_TITLE_LENGTH + 1];
    printf("Enter the title of the story: ");
    scanf("%30[^\n]", title);
    getchar();

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char line[MAX_LINE_LEN];
        
        while (fgets(line, sizeof(line), file) != NULL) {
            char *story_date = strtok(line, "|");
            char *story_title = strtok(NULL, "|");
            char *story_text = strtok(NULL, "|");
            
            if (strcmp(story_title, title) == 0 ) {
                printf("\nDate: %s\nTitle: %s\n\n%s\n", story_date, story_title, story_text);
                fclose(file);
                return;
            }
        }
        fclose(file);
        printf("Story not found.\n");
    } 
    else
        printf("Failed to open the file.\n");

}
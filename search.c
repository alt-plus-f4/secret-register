// #include <stdio.h>
// #include <string.h>

void searchByTitle(char* searchTitle) {
    int i;
    for (i = 0; i < diary->count; i++) {
        Story* story = &(diary->stories[i]);
        if (strcmp(story->title, searchTitle) == 0) {
            printStory(story);
        }
    }
}

void searchByDate(char* searchDate) {
    int i;
    for (i = 0; i < diary->count; i++) {
        Story* story = &(diary->stories[i]);
        if (strcmp(story->date, searchDate) == 0) {
            printStory(story);
        }
    }
}

    // printf("Въведете заглавие за търсене: ");
    // char searchTitle[MAX_TITLE_LENGTH + 1];
    // scanf(" %[^\n]s", searchTitle);
    // searchByTitle(&diary, searchTitle);
    // break;

    // printf("Въведете дата за търсене: ");
    // char searchDate[20];
    // scanf("%s", searchDate);
    // searchByDate(&diary, searchDate);
    // break;

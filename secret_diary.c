#include <stdio.h>
#include <stdlib.h>

void writeToDiary() {
    FILE *fptr;
    fptr = fopen("diary.txt", "a");

    if (fptr == NULL) {
        printf("Error opening the file!\n");
        exit(1);
    }

    char text[0xFFFF];
    printf("Write in your diary: ");

    fgets(text, sizeof(text), stdin);
    fprintf(fptr, "%s", text);
    fclose(fptr);

}

void readDiary() {
    FILE *fptr;
    fptr = fopen("diary.txt", "r");

    if (fptr == NULL) {
        printf("Error opening the file!\n");
        exit(1);
    }

    char c;
    printf("Contents of the diary:\n");
    while ((c = fgetc(fptr)) != EOF) {
        putchar(c);
    }
    fclose(fptr);
}

int main() {
    int option;
    printf("Hello, sir/madam!\n");
    printf("If you want to write a story press 1.\n");
    printf("If you want to read a story press 2.\n");

    do{
       printf("Option: ");
       scanf("%d",&option);
    }
    while(option > 2 || option < 1);

    if(option == 1){
        fflush(stdin);
        writeToDiary();
    }

    if(option == 2){
        readDiary();
    }

    return 0;
}
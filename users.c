#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 30

void create_new_user(const char* user){
	FILE* file = fopen("users.txt", "r");

	file = fopen("users.txt", "a");
	
	if (file == NULL) {
		printf("Failed to open file for writing.\n");
		return;
	}

	fprintf(file, "%s\n", user);
	fclose(file);

	char filename[MAX_USERNAME_LENGTH + 4];
	strcpy(filename, user);
	strcat(filename, ".txt");
	file = fopen(filename, "w");
	
	fclose(file);
}

char* login(const char* user){
	FILE* file = fopen("users.txt", "r");
	size_t user_exists = 0;
	
	if (file != NULL) {
		char line[MAX_USERNAME_LENGTH];

		while (fgets(line, sizeof(line), file)) {
			line[strcspn(line, "\n")] = '\0';

			if (strcmp(user, line) == 0)
				user_exists = 1;
		}
		
		fclose(file);
	}

	if (!user_exists)
		create_new_user(user);
	
	char* filename = malloc((MAX_USERNAME_LENGTH + 4) * sizeof(char));

	strcpy(filename, user);
	strcat(filename, ".txt");

	return filename;
}
#define MAX_TITLE_LENGTH 30
#define MAX_STORY_LENGTH 1024

typedef struct{
    char date[11];
    char title[MAX_TITLE_LENGTH + 1];
    char story[MAX_STORY_LENGTH];
} Story;

int is_valid_date(const char *date_str);
void add_new_story(const char* filename);
void display_stories(const char* filename);
void display_story_by_date(const char* filename);
void display_story_by_title(const char* filename);
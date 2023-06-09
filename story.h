#define MAX_TITLE_LENGTH 30
#define MAX_STORY_LENGTH 1024

typedef struct{
    char date[11];
    char title[MAX_TITLE_LENGTH + 1];
    char story[MAX_STORY_LENGTH];
} Story;

int is_valid_date(const char *date_str);
void add_new_story();
void display_stories();
void display_story_by_date();
void display_story_by_title();
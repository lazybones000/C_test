#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LEN 20

struct Student {
    char name[NAME_LEN];
    float scores[5];
    float avg;
};

float avgScores(const float scores[], int n) {
    int i;
    float sum = 0;
    for (i = 0; i < n; i++) { 
        sum += scores[i];
    }
    return sum / n;
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0, i = 0, j = 0;

    printf("Enter number of students (max 10): ");
    if (scanf("%d", &count) != 1 || count < 1 || count > MAX_STUDENTS) {
        fprintf(stderr, "Invalid count.\n");
        return 1;
    }

    for (i = 0; i < count; i++) {
        printf("Enter name: ");
        if (scanf("%19s", students[i].name) != 1) {
            fprintf(stderr, "Invalid name input.\n");
            return 1;
        }

        printf("Enter 5 scores for %s:\n", students[i].name);
        for (j = 0; j < 5; j++) {
            if (scanf("%f", &students[i].scores[j]) != 1) {
                fprintf(stderr, "Invalid score input.\n");
                return 1;
            }
            if (students[i].scores[j] < 0 || students[i].scores[j] > 100) {
                fprintf(stderr, "Invalid score range.\n");
                return 1;
            }
        }

        students[i].avg = avgScores(students[i].scores, 5);
    }

    printf("\n=== Student Average Scores ===\n");
    for (i = 0; i < count; i++)
        printf("%s : %.2f\n", students[i].name, students[i].avg);

    return 0;

}

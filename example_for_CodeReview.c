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
    char tempName[NAME_LEN];

    printf("Enter number of students (max 10): ");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("Enter name: ");
        scanf("%s", tempName); 
        strcpy(students[i].name, tempName);

        printf("Enter 5 scores for %s:\n", students[i].name);
        for (j = 0; j < 5; j++) {
            scanf("%f", &students[i].scores[j]);
        }

        students[i].avg = avgScores(students[i].scores, 5);
    }

    printf("\n=== Student Average Scores ===\n");
    for (i = 0; i < count; i++)
        printf("%s : %.2f\n", students[i].name, students[i].avg);

    return 0;

}

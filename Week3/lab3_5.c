#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int id;
};

struct student (*GetStudent(int *room))[10];

int main() {
    struct student(*children)[10];
    int group;
    children = GetStudent(&group);
    return 0;
}

struct student (*GetStudent(int *room))[10] {
    printf("Enter number of rooms: ");
    scanf("%d", room);

    struct student(*students)[10] = malloc((*room) * sizeof(struct student[10]));

    for (int i = 0; i < *room; i++) {
        printf("Room %d\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d\n", j + 1);
            printf("ID: ");
            scanf("%d", &students[i][j].id);
            printf("Name: ");
            scanf("%s", students[i][j].name);
        }
    }
    return students;
}
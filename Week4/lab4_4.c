#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
	char name[20];
	int age;
	char sex;
	float gpa;
	struct studentNode *next;
};

void SaveNode(struct studentNode *child, char n[], int a, char s, float g);
void GoNext1(struct studentNode **walk);

int main() {
	struct studentNode *start, *now1;
	
	start = (struct studentNode*)malloc(sizeof(struct studentNode));
	SaveNode(start, "one", 6, 'M', 3.11);
	
	start->next = (struct studentNode*)malloc(sizeof(struct studentNode));
	SaveNode(start->next, "two", 8, 'F', 3.22);
	
	start->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
	SaveNode(start->next->next, "three", 10, 'M', 3.33);

	start->next->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
	SaveNode(start->next->next->next, "four", 12, 'F', 3.44);
	start->next->next->next->next = NULL;

	now1 = start;

	GoNext1(&now1);
	printf("%s ", now1->name);

	// The 'start' pointer is now lost, so freeing the list is complex.
	// For simplicity, it is omitted.
	
	return 0;
}

void SaveNode(struct studentNode *child, char n[], int a, char s, float g) {
	strcpy(child->name, n);
	child->age = a;
	child->sex = s;
	child->gpa = g;
}

void GoNext1(struct studentNode **walk) {
    // Check if there is a next node to move to
    if ((*walk) != NULL && (*walk)->next != NULL) {
        // Advance the original pointer (now1 in main) to the next node
        *walk = (*walk)->next;
        
        // Display the name from the new node that the pointer now points to
        printf("%s ", (*walk)->name);
    }
}
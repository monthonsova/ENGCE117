#include <stdio.h>

struct student {
	char name[20];
	int age;
	char sex;
	float gpa;
};

void upgrade(struct student *std);

int main() {
	struct student aboy;
	aboy.sex = 'M';
	aboy.gpa = 3.00;
	
	upgrade(&aboy);
	
	printf("%.2f", aboy.gpa);
	return 0;
}

void upgrade(struct student *std) {
	if (std->sex == 'M') {
		std->gpa = std->gpa * 1.1;
	} else if (std->sex == 'F') {
		std->gpa = std->gpa * 1.2;
	}
}

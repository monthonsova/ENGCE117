#include <stdio.h>

struct student {
	char name[20];
	int age;
	char sex;
	float gpa;
};

struct student upgrade(struct student std);

int main() {
	struct student aboy;
	aboy.sex = 'M';
	aboy.gpa = 3.00;
	
	aboy = upgrade(aboy);
	
	printf("%.2f", aboy.gpa);
	return 0;
}

struct student upgrade(struct student std) {
	if (std.sex == 'M') {
		std.gpa = std.gpa * 1.1;
	} else if (std.sex == 'F') {
		std.gpa = std.gpa * 1.2;
	}
	return std;
}

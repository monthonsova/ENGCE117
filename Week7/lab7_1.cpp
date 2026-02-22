#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    char sex;
    float gpa;
    Student* next;

    Student(const string& n, int a, char s, float g)
        : name(n), age(a), sex(s), gpa(g), next(nullptr) {}
};

class LinkedList {
protected:
    Student* head;
    Student* current;

public:
    LinkedList() : head(nullptr), current(nullptr) {}

    virtual ~LinkedList() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
        current = nullptr;
    }

    void insertFront(const string& name, int age, char sex, float gpa) {
        Student* newNode = new Student(name, age, sex, gpa);
        newNode->next = head;
        head = newNode;
        current = head;
    }

    void goNext() {
        if (current != nullptr)
            current = current->next;
    }

    void deleteCurrent() {
        if (head == nullptr || current == nullptr)
            return;

        if (current == head) {
            head = head->next;
            delete current;
            current = head;
            return;
        }

        Student* prev = head;
        while (prev->next != current)
            prev = prev->next;

        prev->next = current->next;
        delete current;
        current = prev->next;
    }

    virtual void show() const {
        if (current != nullptr) {
            cout << current->name << " "
                 << current->age << " "
                 << current->sex << " "
                 << current->gpa << endl;
        }
    }
};

class NameList : public LinkedList {
public:
    void goFirst() {
        current = head;
    }

    void show() const override {
        Student* temp = head;
        bool first = true;

        while (temp != nullptr) {
            if (!first)
                cout << " ";
            cout << temp->name;
            first = false;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList listA;
    NameList listB;
    LinkedList* listC;

    listA.insertFront("one", 1, 'A', 1.1f);
    listA.insertFront("two", 2, 'B', 2.2f);
    listA.insertFront("three", 3, 'C', 3.3f);

    listA.goNext();
    listA.show();

    listB.insertFront("four", 4, 'D', 4.4f);
    listB.insertFront("five", 5, 'E', 5.5f);
    listB.insertFront("six", 6, 'F', 6.6f);

    listB.goNext();
    listB.deleteCurrent();
    listB.show();

    listC = &listA;
    listC->goNext();
    listC->show();

    listC = &listB;
    listC->show();

    return 0;
}
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class LinkedList {
protected:
    struct Node {
        string name;
        int age;
        char sex;
        float gpa;
        unique_ptr<Node> next;

        Node(const string& n, int a, char s, float g)
            : name(n), age(a), sex(s), gpa(g), next(nullptr) {}
    };

    unique_ptr<Node> head;
    Node* current = nullptr;

public:
    LinkedList() = default;
    virtual ~LinkedList() = default;

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    LinkedList(LinkedList&&) noexcept = default;
    LinkedList& operator=(LinkedList&&) noexcept = default;

    void insertFront(const string& name, int age, char sex, float gpa) {
        auto newNode = make_unique<Node>(name, age, sex, gpa);
        newNode->next = move(head);
        head = move(newNode);
        current = head.get();
    }

    void goNext() {
        if (current) {
            current = current->next.get();
        }
    }

    void deleteCurrent() {
        if (!head || !current) return;

        if (current == head.get()) {
            head = move(head->next);
            current = head.get();
        } else {
            Node* prev = head.get();
            while (prev && prev->next.get() != current) {
                prev = prev->next.get();
            }
            if (prev) {
                prev->next = move(current->next);
                current = prev->next.get();
            }
        }
    }

    virtual void show() const {
        if (current) {
            cout << current->name << " " << current->age << " " 
                 << current->sex << " " << current->gpa << endl;
        }
    }
};

class NameList : public LinkedList {
public:
    void goFirst() {
        current = head.get();
    }

    void show() const override {
        if (!head) return;
        
        Node* temp = head.get();
        while (temp) {
            cout << temp->name << (temp->next ? " " : "");
            temp = temp->next.get();
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
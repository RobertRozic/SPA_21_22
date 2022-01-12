#include <iostream>

using namespace std;

struct Person {
  string name;
  int age;

  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }

  Person* next;
};

struct queue {
  Person* front;
  Person* rear;


  bool isEmpty() {
    return this->front == NULL;
  }

  void enqueue(Person* new_element) {
    if (this->isEmpty()) {
      this->front = new_element;
      this->rear = this->front;
      return;
    }
    this->rear->next = new_element;
    this->rear = new_element;
    this->rear->next = NULL;
  }

  void dequeue() {
    if (this->isEmpty())
      return;

    Person* temp = this->front;
    this->front = this->front->next;

    delete temp;
  }

  Person* getFront() {
    return this->front;
  }

  void print() {
    if (this->isEmpty()) {
      cout << "Red je prazan.";
      return;
    }

    cout << "----------------------------------------" << endl;

    Person* iterator = this->front;
    cout << iterator->name << endl;

    while (iterator->next != NULL) {
      iterator = iterator->next;
      cout << iterator->name << endl;
    }

    cout << "----------------------------------------" << endl;

  }
};


int main() {
  queue* osobe = new queue();

  Person* o1 = new Person("Ivan", 23);
  Person* o2 = new Person("Ana", 22);
  Person* o3 = new Person("Marko", 19);

  osobe->enqueue(o1);
  osobe->enqueue(o2);
  osobe->enqueue(o3);
  osobe->print();

  Person* trenutna = osobe->getFront();
  cout << "Trenutno na redu: " << trenutna->name << endl;

  osobe->dequeue();

  osobe->print();
}

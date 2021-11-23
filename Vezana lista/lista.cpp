#include <stdio.h>
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

struct lista {
  Person* first;
  
  lista() {
      // Prazan konstruktor
  }
  
  // Ispis liste
  void print() {
    int counter = 0;
    
    Person *iterator = this->first;

    do {
        cout << counter << "|" << iterator->name  << ' ' << iterator->age << endl;
        iterator = iterator->next;
        counter++;
    } while (iterator != NULL);
  }
  
  // Velicina liste
  int size() {
    int counter = 0;
    
    Person *iterator = this->first;
    
    if (iterator == NULL)
        return counter;
        
    do {
        counter++;
        iterator = iterator->next;
    } while (iterator != NULL);
    
    return counter;
  }
  
  
  // Provjera je li lista prazna
  bool isEmpty() {
      if (first == NULL)
        return true;
        
      return this->size() == 0;
  }
  
  // Dohvacanje zadnjeg elementa
  Person* last() {
      Person *iterator = this->first;
      
      while (iterator->next != NULL) {
          iterator = iterator->next;
      }
      
      return iterator;
  }
  
  void add_to_start(Person* novi) {
      // Novi pokazuje na stari prvi
      novi->next = this->first;
      // Novi postaje prvi
      this->first = novi;
  }
  
  void add_to_end(Person* novi) {
      // Dohvatimo zadnji element (koji pokazuje na NULL)
      Person *zadnji = this->last();
      // Taj element sada pokazuje na novi element
      zadnji->next = novi;
      // Novi zadnji element pokazuje na NULL
      novi->next = NULL;
  }
};

int main()
{
    lista *persons = new lista;
    
    Person *p1 = new Person("Ivan", 20);
    Person *p2 = new Person("Marija", 21);
    Person *p3 = new Person("Marko", 24);
    Person *p4 = new Person("Ana", 19);
    
    
    bool jeLiPrazna = persons->isEmpty();
    
    persons->add_to_start(p1);
    persons->add_to_start(p2);
    persons->add_to_end(p3);
    
    //jeLiPrazna = persons->isEmpty();
    //cout << "Prazna: " << jeLiPrazna << endl;
    
    // Ispis liste
    persons->print();
    
    int velicina = persons->size();
    
    cout << "Velicina liste:" << velicina << endl;
    
    // Zadnji element
    cout << "Zadnji: " << persons->last()->name << endl;
    /*Person *first = new Person("Ivan", 20);
    Person *p2 = new Person("Marija", 21);
    Person *p3 = new Person("Marko", 24);
    Person *p4 = new Person("Ana", 19);
    
    // Ivan -> Marija -> Marko
    first->next = p2;
    p2->next = p3;
    p3->next = p4;
    
    // Ispis
    Person *iterator = first;
    
    cout << iterator->name  << ' ' << iterator->age << endl;
    
    while (iterator->next != NULL) {
        iterator = iterator->next;
        cout << iterator->name  << ' ' << iterator->age << endl;
    }*/

    return 0;
}


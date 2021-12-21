#include <stdio.h>
#include <iostream>

using namespace std;

struct Book {
  // Podaci o knjizi
  string name;
  int year;

  Book(string name, int year) {
    this->name = name;
    this->year = year;
  }

  // Pokazivac na sljedecu knjigu u stogu
  Book* next;
};

struct stack {
    
    Book* first;
    
    stack(){};
    
    bool isEmpty() {
        return this->first == NULL;
    }
    
    Book* top() {
      Book* iterator = this->first;  
      
      while (iterator->next != NULL) {
        iterator = iterator->next;
      }

      return iterator;
    }

    void push(Book* element) {
        // Ako je stog prazan
        if (this->isEmpty()) {
            // Postavi element na prvo mjesto, pocetak
            this->first = element;
            return;
        }
        
        // Dohvati vrh stoga i postavi pokazivac na novi
        this->top()->next = element;
    }
    
    
  Book* pop() {
    Book* last = this->top();
    Book* iterator = this->first;

    /*if (last == iterator) {
      this->first = NULL;
      return;
    }*/

    while(iterator->next != last) {
      iterator = iterator->next;
    }

    iterator->next = NULL;
    
    return last;
  }
};


int main()
{
    Book *k1 = new Book("knjiga1", 2001);
    Book *k2 = new Book("knjiga2", 2000);
    Book *k3 = new Book("knjiga3", 2000);
    stack *s = new stack();
    
    s->push(k1);
    s->push(k2);
    s->push(k3);
    
    cout << "Na vrhu prije" << s->top()->name << endl;
    cout << s->pop()->name << endl;
    cout << "Na vrhu poslije" << s->top()->name << endl;
    
    return 0;
}

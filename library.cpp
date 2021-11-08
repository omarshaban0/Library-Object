//
// Created by Omar on 10/10/2021.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library


#include "library.h"
#include <iostream>

// constructor with default name
Library::Library(const string &Name) {
  this -> libName = Name;
  numberOfBooks = 0;
}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library
bool Library::isInLibrary(const string &BookName) const {
  int index = findBook(BookName);
  if(index == -1){
    return false;
  }
  return true;
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName) {
  if(findBook(BookName) == -1){
    books[numberOfBooks] = BookName;
    numberOfBooks++;
    return true;
  }else{
    return false;
  }
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName) {
  if(findBook(BookName) == -1){
    return false;
  }else{
    books[findBook(BookName)] = books[numberOfBooks-1];
    numberOfBooks--;
    return true;
  }
}

// list all books
void Library::listAllBooks() const {
  for(int i = 0; i < numberOfBooks-1;i++){
    cout << books[i] << endl;
  }
}
//helper class iterates through array to find if Book exists in it
int Library::findBook(const string &BookName) const{
  for(int i(0); i < numberOfBooks; i++){
    if(books[i] == BookName){
      return i;
    }
  }
  return -1;
}

ostream &operator<<(ostream &Out, const Library &Lib) {
  Out << Lib.listAllBooks() << endl;
  return Out;
}
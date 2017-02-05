#include <list>
using namespace std;

int main() {
    list<int> listOfNumbers;
    listOfNumbers.push_back(5);
    listOfNumbers.push_back(6);

    //Inserting elements at front in list
    listOfNumbers.push_front(2);
    //Inserting elements in between the list using
    // insert(pos,elem) member function. Let's iterate to
    // 3rd position
    auto it = listOfNumbers.begin();
    it++;
    it++;
    // Iterator 'it' is at 3rd position.
    //It allocates a new node and copy the passed element to it and then inserts that node before iterator position iterator_position
    //and returns the position of the newly added element.
    listOfNumbers.insert(it, 4);
    it = listOfNumbers.begin();
    it++;
    it++;
    // Iterator 'it' is at 3rd position. Now erase this element.
    listOfNumbers.erase(it);

}

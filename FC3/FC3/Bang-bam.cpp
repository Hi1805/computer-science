#include <iostream>
#include <list>
using namespace std;

class Hashing {
    private:
        int BUCKET;
        list<int> *sc;
    public:
        Hashing(int N);
        void insertKey(int key);
        void deleteKey(int key);
        int hashFunction(int okey);
        void printHashTable();
};

Hashing::Hashing(int N){
    this->BUCKET = N;
    sc = new list<int>[BUCKET];
}

int Hashing::hashFunction(int okey){
    return (okey % BUCKET);
}

void Hashing::insertKey(int key){
    int nkey = hashFunction(key);
    sc[nkey].push_back(key);
}

void Hashing::deleteKey(int key){
    int nkey = hashFunction(key);
    list<int>::iterator i;
    for (i = sc[nkey].begin(); i != sc[nkey].end(); i++){
        if(*i == key) {
            sc[nkey].erase(i);
        }
    }
}

void Hashing::printHashTable(){
    for(int i = 0; i < BUCKET; i++){
        cout << i ;
        list<int>::iterator j;
        for(j = sc[i].begin(); j != sc[i].end(); j++){
            cout << "-->" << *j ;
        }
        cout << endl;
    }
}

int main(){
    
    Hashing h(7);
    
    int Obj[] = {3,12, 4, 9, 10, 7};
    int obj_size = sizeof(Obj)/sizeof(Obj[0]);
    for(int i = 0; i < obj_size; i++){
        h.insertKey(Obj[i]);
    }
    h.printHashTable();
    return 0;
}

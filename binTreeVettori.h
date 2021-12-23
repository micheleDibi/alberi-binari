#ifndef BINTREEVECTTOR_H
#define BINTREEV_H

#include <iostream>
#include "binTree.h"

using namespace std;

template <class T>
class vectorBinTree : public binTree<T, int> {
    static const int NIL = -1;

public:
    typedef typename binTree<T, int>::valueType valueType;
    typedef typename binTree<T, int>::nodo nodo;

    struct cella {
        nodo genitore;
        nodo fSinistro;
        nodo fDestro;
        valueType valore;
    };

    vectorBinTree();
    vectorBinTree(int);
    ~vectorBinTree();

    void create();
    bool isEmpty() const;

    nodo _root() const;
    nodo parent(nodo) const;
    nodo sx(nodo) const;
    nodo dx(nodo) const;
    bool isSXempty(nodo) const;
    bool isDXempty(nodo) const;

    void deleteNode(nodo);

    valueType read(nodo) const;
    void write(nodo, valueType);

    void insRoot();
    void insSX(nodo);
    void insDX(nodo);
    void insSX(nodo, valueType);
    void insDX(nodo, valueType);

    void previsita(nodo) const;
    void simmetrica(nodo) const;
    void postvisita(nodo) const;

private:
    int dim;
    cella *space;
    int nNodi;
    nodo root;
    nodo free;
};

template <class T>
vectorBinTree<T>::vectorBinTree() {
    dim = 100;
    space = new cella[dim];
    this->create();
}

template <class T>
vectorBinTree<T>::vectorBinTree(int dimensione) {
    dim = dimensione;
    space = new cella[dim];
    this->create();
}

template <class T>
vectorBinTree<T>::~vectorBinTree() {
    deleteNode(root);
    delete[] space;
}

template <class T>
void vectorBinTree<T>::create() {
    free = 0;
    nNodi = 0;

    root = NIL;
    for(int i = 0; i < dim; i++) {
        space[i].fSinistro = (i + 1) % dim;
    }
}

template <class T>
bool vectorBinTree<T>::isEmpty() const {
    return nNodi == 0;
}

template <class T>
typename vectorBinTree<T>::nodo vectorBinTree<T>::_root() const {
    return root;
}

template <class T>
typename vectorBinTree<T>::nodo vectorBinTree<T>::parent(vectorBinTree<T>::nodo n) const {
    if (n != root) {
        return space[n].genitore;
    }
}

template <class T>
typename vectorBinTree<T>::nodo vectorBinTree<T>::sx(vectorBinTree<T>::nodo n) const {
    if(!isSXempty(n)) {
        return space[n].fSinistro;
    }
}

template <class T>
typename vectorBinTree<T>::nodo vectorBinTree<T>::dx(vectorBinTree<T>::nodo n) const {
    if(!isDXempty(n)) {
        return space[n].fDestro;
    }
}

template <class T>
bool vectorBinTree<T>::isSXempty(vectorBinTree<T>::nodo n) const {
    return space[n].fSinistro == NIL;
}

template <class T>
bool vectorBinTree<T>::isDXempty(vectorBinTree<T>::nodo n) const {
    return space[n].fDestro == NIL;
}

template <class T>
void vectorBinTree<T>::deleteNode(vectorBinTree<T>::nodo n) {

    if(!isEmpty()) {

        if(!isSXempty(n)) {
            deleteNode(space[n].fSinistro);
        }

        if(!isDXempty(n)) {
            deleteNode(space[n].fDestro);
        }

        if(n != root) {

            nodo supp = parent(n);
            if(space[supp].fSinistro == n) {
                space[supp].fSinistro = NIL;
            } else if(space[supp].fDestro == n) {
                space[supp].fDestro = NIL;
            }

        } else root = NIL;

        nNodi--;
        space[n].fSinistro = free;
        free = n;

    }
}

template <class T>
typename vectorBinTree<T>::valueType vectorBinTree<T>::read(vectorBinTree<T>::nodo n) const {
    if(n < nNodi && n != NIL) {
        return space[n].valore;
    }
}

template <class T>
void vectorBinTree<T>::write(vectorBinTree<T>::nodo n, vectorBinTree<T>::valueType elem) {
    if(n < nNodi && n != NIL) {
        space[n].valore = elem;
    }
}

template <class T>
void vectorBinTree<T>::insRoot() {

    if(root == NIL) {
        root = free;
        free = space[free].fSinistro;

        space[root].fSinistro = NIL;
        space[root].fDestro = NIL;
        nNodi++;
    }

}

template <class T>
void vectorBinTree<T>::insSX(vectorBinTree<T>::nodo n) {

    nodo supp = free;
    free = space[free].fSinistro;

    space[n].fSinistro = supp;

    space[supp].fSinistro = NIL;
    space[supp].fDestro = NIL;
    space[supp].genitore = n;

}

template <class T>
void vectorBinTree<T>::insSX(vectorBinTree<T>::nodo n, vectorBinTree<T>::valueType elem) {

    nodo supp = free;
    free = space[free].fSinistro;

    space[n].fSinistro = supp;

    space[supp].valore = elem;
    space[supp].fSinistro = NIL;
    space[supp].fDestro = NIL;
    space[supp].genitore = n;

    nNodi++;
}

template <class T>
void vectorBinTree<T>::insDX(vectorBinTree<T>::nodo n) {

    nodo supp = free;
    free = space[free].fSinistro;

    space[n].fDestro = supp;

    space[supp].fSinistro = NIL;
    space[supp].fDestro = NIL;
    space[supp].genitore = n;

    nNodi++;
}

template <class T>
void vectorBinTree<T>::insDX(vectorBinTree<T>::nodo n, vectorBinTree<T>::valueType elem) {

    nodo supp = free;
    free = space[free].fSinistro;

    space[n].fDestro = supp;

    space[supp].valore = elem;
    space[supp].fSinistro = NIL;
    space[supp].fDestro = NIL;
    space[supp].genitore = n;

    nNodi++;
}

template <class T>
void vectorBinTree<T>::postvisita(vectorBinTree<T>::nodo n) const {

    if(n != NIL) {
        if(!isSXempty(n)) {
            postvisita(space[n].fSinistro);
        }

        if(!isDXempty(n)) {
            postvisita(space[n].fDestro);
        }

        cout << read(n) << ", ";

    }
}

template <class T>
void vectorBinTree<T>::previsita(vectorBinTree<T>::nodo n) const {

    if(n != NIL) {
        cout << read(n) << ", ";

        if(!isSXempty(n)) {
            postvisita(space[n].fSinistro);
        }

        if(!isDXempty(n)) {
            postvisita(space[n].fDestro);
        }
    }
}

template <class T>
void vectorBinTree<T>::simmetrica(vectorBinTree<T>::nodo n) const {

    if(n != NIL) {

        if(!isSXempty(n)) {
            postvisita(space[n].fSinistro);
        }

        cout << read(n) << ", ";

        if(!isDXempty(n)) {
            postvisita(space[n].fDestro);
        }
    }
}

#endif // BINTREEVECTOR_H

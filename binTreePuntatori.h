#ifndef BINTREEPUNTATORI_H
#define BINTREEPUNTATORI_H

#include "binTree.h"
#include <iostream>

using namespace std;

template <class T>
class linkedBinTree;

template <class T>
class node {
    friend class linkedBinTree<T>;
private:
    node<T>* sinistro;
    node<T>* destro;
    node<T>* genitore;
    T valore;
};

template <class T>
class linkedBinTree : public binTree<T, node<T>*> {
public:

    typedef typename binTree<T, node<T>*>::valueType valueType;
    typedef node<T>* nodo;

    linkedBinTree();
    ~linkedBinTree();

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
    node<T>* root;
};

template <class T>
linkedBinTree<T>::linkedBinTree() {
    this->create();
}

template <class T>
linkedBinTree<T>::~linkedBinTree() {
    deleteNode(root);
}

template <class T>
void linkedBinTree<T>::create() {
    root = nullptr;
}

template <class T>
bool linkedBinTree<T>::isEmpty() const {
    return (root == nullptr);
}

template <class T>
typename linkedBinTree<T>::nodo linkedBinTree<T>::_root() const {
    return root;
}

template <class T>
typename linkedBinTree<T>::nodo linkedBinTree<T>::parent(linkedBinTree<T>::nodo nd) const {
    if(nd != root) {
        return nd->genitore;
    }
}

template <class T>
typename linkedBinTree<T>::nodo linkedBinTree<T>::sx(linkedBinTree<T>::nodo nd) const {
    if(!isSXempty(nd)) {
        return nd->sinistro;
    }
}

template <class T>
typename linkedBinTree<T>::nodo linkedBinTree<T>::dx(linkedBinTree<T>::nodo nd) const {
    if(!isDXempty(nd)) {
        return nd->destro;
    }
}

template <class T>
bool linkedBinTree<T>::isSXempty(linkedBinTree<T>::nodo nd) const {
    return (nd->sinistro == nullptr);
}

template <class T>
bool linkedBinTree<T>::isDXempty(linkedBinTree<T>::nodo nd) const {
    return (nd->destro == nullptr);
}

template <class T>
void linkedBinTree<T>::deleteNode(linkedBinTree<T>::nodo nd) {

    if(!isSXempty(nd)) {
        deleteNode(nd->sinistro);
    }

    if(!isDXempty(nd)) {
        deleteNode(nd->destro);
    }

    if(nd != root) {
        if(nd == nd->genitore->sinistro) {
            nd->genitore->sinistro = nullptr;
        } else if (nd == nd->genitore->destro) {
            nd->genitore->destro = nullptr;
        }
    }

    delete nd;
}

template <class T>
typename linkedBinTree<T>::valueType linkedBinTree<T>::read(linkedBinTree<T>::nodo nd) const {

    if(nd != nullptr) {
        return nd->valore;
    }
}

template <class T>
void linkedBinTree<T>::write(linkedBinTree<T>::nodo nd, linkedBinTree<T>::valueType el) {
    if(nd != nullptr) {
        nd->valore = el;
    }
}

template <class T>
void linkedBinTree<T>::insRoot() {
    if(root == nullptr) {
        root = new node<T>;
    }
}
template <class T>
void linkedBinTree<T>::insSX(linkedBinTree<T>::nodo nd) {
    if(!isEmpty() && isSXempty(nd) == true) {
        node<T>* supp = new node<T>;

        nd->sinistro = supp;
        supp->genitore = nd;
    }
}

template <class T>
void linkedBinTree<T>::insDX(linkedBinTree<T>::nodo nd) {
    if(!isEmpty() && isDXempty(nd) == true) {
        node<T>* supp = new node<T>;

        nd->destro = supp;
        supp->genitore = nd;
    }
}

template <class T>
void linkedBinTree<T>::insSX(linkedBinTree<T>::nodo nd, linkedBinTree<T>::valueType el) {
    if(!isEmpty() && isSXempty(nd) == true) {
        node<T>* supp = new node<T>;
        supp->valore = el;

        nd->sinistro = supp;
        supp->genitore = nd;
    }
}

template <class T>
void linkedBinTree<T>::insDX(linkedBinTree<T>::nodo nd, linkedBinTree<T>::valueType el) {
    if(!isEmpty() && isDXempty(nd) == true) {
        node<T>* supp = new node<T>;
        supp->valore = el;

        nd->destro = supp;
        supp->genitore = nd;
    }
}

template <class T>
void linkedBinTree<T>::previsita(linkedBinTree<T>::nodo nd) const {

    if(!isEmpty()) {
        cout << nd->valore << ", ";

        if(isSXempty(nd)) {
            previsita(nd->sinistro);
        }

        if(isDXempty(nd)) {
            previsita(nd->destro);
        }
    }
}

template <class T>
void linkedBinTree<T>::simmetrica(linkedBinTree<T>::nodo nd) const {
    if(!isEmpty()) {
        if(isSXempty(nd)) {
            previsita(nd->sinistro);
        }

        cout << nd->valore << ", ";

        if(isDXempty(nd)) {
            previsita(nd->destro);
        }
    }
}

template <class T>
void linkedBinTree<T>::postvisita(linkedBinTree<T>::nodo nd) const {
    if(!isEmpty()) {
        if(isSXempty(nd)) {
            previsita(nd->sinistro);
        }

        if(isDXempty(nd)) {
            previsita(nd->destro);
        }

        cout << nd->valore << ", ";
    }
}

#endif // BINTREEPUNTATORI_H

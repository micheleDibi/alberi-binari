#ifndef BINTREE_H
#define BINTREE_H

template <class T, class N>
class binTree {
  static const int NIL = -1;

  public:
    typedef T valueType;
    typedef N nodo;

    virtual void create() = 0;
    virtual bool isEmpty() const =  0;

    virtual nodo _root() const = 0;
    virtual nodo parent(nodo) const =  0;
    virtual nodo sx(nodo) const = 0;
    virtual nodo dx(nodo) const = 0;
    virtual bool isSXempty(nodo) const = 0;
    virtual bool isDXempty(nodo) const = 0;

    virtual void deleteNode(nodo) = 0;

    virtual valueType read(nodo) const = 0;
    virtual void write(nodo, valueType) = 0;

    virtual void insRoot() = 0;
    virtual void insSX(nodo) = 0;
    virtual void insDX(nodo) = 0;
    virtual void insSX(nodo, valueType) = 0;
    virtual void insDX(nodo, valueType) = 0;

    virtual void previsita(nodo) const = 0;
    virtual void simmetrica(nodo) const = 0;
    virtual void postvisita(nodo) const = 0;

};

#endif

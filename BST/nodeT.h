#ifndef NODET_H
#define NODET_H

class nodeT {
  private:
    int data;
    nodeT *left, *right;
  public:
    nodeT(int);
    int getData() {return data;}
    nodeT* Left() {return left;}
    nodeT* Right() {return right;}
    void setLeft(nodeT* _left) {left = _left;}
    void setRight(nodeT* _right) {right = _right;}
};

nodeT::nodeT(int dato) {
  data = dato;
  left = right = nullptr;
}

#endif
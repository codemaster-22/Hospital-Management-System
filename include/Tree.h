#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Tree;
class Node{
    public:
    int data;
    int doctor;
    Node* left;
    Node* right;
    Node* parent;
    Tree* paitent;
    Node(int l,int k,Node* par):data(l),doctor(k),left(NULL),right(NULL),parent(par),paitent(NULL){}
};
class Tree{
    public:
    Node* root;
    int size,limit;
    Node* insert(int n,int p);
    Node* insert1(int n,int p,Node* ptr);
    Node* search(int p,int q,int k);
    Node* search2(int p,int q,int k,Node *ptr);
    int remove(int n,int p,int k);
    void remove(Node* ptr);
    void printpreorder();
    void printpreorder(Node* ptr);
    void printinorder();
    void printinorder(Node* ptr);
    Tree():root(NULL),size(0),limit(0){}
};

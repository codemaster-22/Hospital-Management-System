#include "../include/Tree.h"

Node::Node(int l,int k,Node* par){
    data= l;
    doctor=k;
    left=NULL;
    right=NULL;
    parent=par;
    paitent=NULL;
}


Node* Tree::insert(int n,int p=0){
    if(!root){
        root=new Node(n,p,root);
        root->paitent=new Tree;
        size++;
        return root;
    }
    return insert1(n,p,root);
}         // used for insertion in both trees
Node* Tree::insert1(int n,int p,Node* ptr){
    if(ptr->data==n){
        return NULL;
    }
    if(ptr->data>n){
        if(!ptr->left){
            ptr->left=new Node(n,p,ptr);
            ptr->left->paitent=new Tree;
            size++;
            return ptr->left;
        }
        else
           return insert1(n,p,ptr->left);
    }
    else{
      if(!ptr->right){
          ptr->right=new Node(n,p,ptr);
          ptr->right->paitent=new Tree;
          size++;
          return ptr->right;
      }
        else
          return insert1(n,p,ptr->right);
    }
    return NULL;
}
Node* Tree::search2(int p,int q,int k,Node* rr){
    if(!rr)
      return NULL;
    if(rr->data==q){
      if(k==0)
           return rr;
      if(rr->paitent->size<limit){
       rr->paitent->insert(p);
         return rr;
      }
     return NULL;
    }
    if(rr->data<q)
        return search2(p,q,k,rr->right);
    if(rr->data>q)
        return search2(p,q,k,rr->left);
    return NULL;
}
Node* Tree::search(int p,int q,int k=1){
     return search2(p,q,k,root);
}
int Tree::remove(int n,int p,int k=1){
    Node* temp1;
    temp1=search(n,n,0);
    if(!temp1){
        cout<<-1<<endl;
        return 0;
    }
    if(k==0){
     temp1->paitent->remove(p,p);
        return 0;
    }
    else{
        int j=temp1->doctor;
        remove(temp1);
        return j;
    }
} // used for deletion
void Tree::remove(Node* ptr){
  Node* temp=NULL;
  if(ptr && ptr->left){
      temp=ptr->left;
      Node *s=NULL;
      while(temp->right){
          temp=temp->right;
      }
      Node *p=temp->parent;      
      if(temp->left)
      {     s=temp->left;
          s->parent=p;}
      if(p->left==temp)
          p->left=s;
      else
          p->right=s;
  }
  else if(ptr && ptr->right){
      temp=ptr->right;
      Node *s=NULL;
      while(temp->left){
          temp=temp->left;
      }
      Node *p=temp->parent;
      if(temp->right)
      {   s=temp->right;
          s->parent=p;}
      if(p->left==temp)
          p->left=s;
      else
          p->right=s;
  }
  else{
      if(ptr && ptr->parent)
      {Node *p=ptr->parent;
          if(p->left==ptr)
              p->left=NULL;
          else
              p->right=NULL;}
      else
          root=NULL;
      size--;
      return; 
  }
    ptr->data=temp->data;
    ptr->doctor=temp->doctor;
    size--;
}
void Tree::printpreorder(){
    printpreorder(root);
    if(root)
        cout<<endl;
}
void Tree::printpreorder(Node* ptr){
    if(!ptr)
        return;
    cout<<ptr->data<<" ";
    printpreorder(ptr->left);
    printpreorder(ptr->right);
}
void Tree::printinorder(){
    printinorder(root);
    if(root)
        cout<<endl;
}
void Tree::printinorder(Node* ptr){
    if(!ptr)
        return;
    printinorder(ptr->left);
    cout<<ptr->data<<" ";
    printinorder(ptr->right);
}

#include "../include/Tree.h"
int main() {
    int n,p;
    cin>>n>>p;
    Tree D;
    Tree P;
    D.limit=p;
    while(n--){
        int q;
        cin>>q;
        Node* ptr;
        switch(q){
            case 1: int p;
                    cin>>p;
                    if(!D.insert(p))
                        cout<<-1<<endl;
                    break;
            case 2: int a,b;
                    cin>>a>>b;
                    if(P.search(a,a,0)){
                        cout<<-1<<endl;
                    }
                    else if(D.search(a,b)){
                          P.insert(a,b);
                    }
                    else
                        cout<<-1<<endl;
                    break;
            case 3: int y;
                    cin>>y;
                    int j;
                    j=P.remove(y,y); 
                    if(j!=0)
                         D.remove(j,y,0);
                    break;
            case 4: int f;
                    cin>>f;
                    ptr=D.search(f,f,0);
                    if(ptr){
                        ptr->paitent->printinorder();
                    }
                    break;
            case 5: int m;
                    cin>>m;
                    ptr=P.search(m,m,0);
                    if(ptr)
                        cout<<ptr->doctor<<endl;
                    break;
            case 6: D.printpreorder();
                     break;
            case 7: P.printpreorder();
                     break;
        }
    }
    return 0;
}

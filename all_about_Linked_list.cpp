#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* Next;
};
void Display(Node*);
void Insert_beg(Node**);
void Insert_mid(Node**,int);
void Insert_end(Node**);
int size_liste(Node*);
void Delete_beg(Node**);
void Delete_midd(Node**,int,int);
void Delete_last(Node**);
void reverse_List(Node**);
void Insert_beg(Node**,int);
void Insert_mid(Node**,int,int);
void Insert_end(Node**,int);
int Position(Node*,int);
void Insert_pos(Node**,int,int);
void list_tri(Node**);
int main(){
    int choise,pos;
    char retour;
    Node* Liste = nullptr;
    do{
        cout <<"\t\t1 Display        \t\t\t2 insert in begining \n\t\t3 insert in middle \t\t\t4 insert at end "
        <<"\n\t\t5 delete in begining\t\t\t6 delete in midlle \n\t\t7 delete at end \t\t\t8 inverse \n\t\t9 trier La liste "
        <<"\t\t\t10 ajouter un element dans une liste trier\n\t\t11 exit"<<endl;
        do{
            cout <<"--> Your choise : ";cin>> choise;
        }while(choise<1 || choise>11);
        switch(choise){
            case 1:Display(Liste);break;
            case 2: Insert_beg(&Liste);break;
            case 3:
                do {
                    cout<<"Enter position : ";cin>>pos;
                }while(pos<1 || pos>size_liste(Liste)+1);
                Insert_mid(&Liste,pos);break;
            case 4:Insert_end(&Liste);break;
            case 5:Delete_beg(&Liste);break;
            case 6: do{
                        cout<<"Enter position : ";cin>>pos;
                    }while(pos<1 || pos>size_liste(Liste));
                    Delete_midd(&Liste,pos,size_liste(Liste));
                    break;
            case 7:Delete_last(&Liste);break;
            case 8:reverse_List(&Liste);break;
            case 9: list_tri(&Liste);break;
            case 10: int data;
                    cout<<"--->Enter une valeur pour ajouter : ";cin>>data;
                    pos = Position(Liste,data);
                    Insert_pos(&Liste,pos,data);
                    break;
            default : break;
        }
        cout<<"Menu principale[y/n]? ";cin >>retour;
    }while(retour == 'y' || retour == 'Y');
    system("pause");
    return 0;

}
int size_liste(Node* L){
    int count = 1;
    if(L == nullptr){
        return 0;
    }else{
        while(L != nullptr){
            L = L->Next;
            count++;
        }
        return count;
    }
}
void Display(Node* L){
    if(L == nullptr){
        cout <<"aucune element dans la liste"<<endl;
    }else{
        int i = 1;
        while(L != nullptr){
            cout<<"Element "<<i<<" : "<<L->data<<endl;
            L = L->Next;
            i++;
        }
    }
}
void Insert_beg(Node** L){
    Node* nov = new Node;
    cout<<"\t\t---> Entrer une valeur : ";cin>>nov->data;
    if(*L == nullptr){
        nov->Next = nullptr;
        *L = nov;
        return;
    }else{
        nov->Next = *L;
        *L = nov;
        return;
    }
}
void Insert_mid(Node**L,int pos){
    if(pos == 1){
        Insert_beg(&(*L));
    }else{
        if(pos == size_liste(*L)+1){
            Insert_end(&(*L));
        }else{
            Node* nov;
            nov = new Node;
            cout<<"\t\t---> Entrer une valeur : ";cin>>nov->data;
            Node* Next = *L;
            Node* prev;
            int i = 1;
            while(i<pos && Next != nullptr){
                prev = Next;
                Next = Next->Next;
                i++;
            }
            prev->Next = nov;
            nov->Next = Next;
        }
    }
    return;
}
void Insert_end(Node** L){
    if(*L == nullptr){
        Insert_beg(&(*L));
    }else{
        Node* Last = *L;
        Node* nov;
        nov = new Node;
        cout<<"\t\t---> Entrer une valeur : ";cin>>nov->data;
        nov->Next = nullptr;
        while(Last->Next != nullptr){
            Last = Last->Next;
        }
        Last->Next = nov;
    }
}
void Delete_beg(Node** L){
    if(*L == nullptr){
        return;
    }else{
        Node* help = *L;
        *L = help->Next;
        delete help;
        return;
    }
}
void Delete_midd(Node** L,int pos,int Size){
    if(*L == nullptr || pos == 0){
        return;
    }
    if(pos == 1){
        Delete_beg(&(*L));
    }else{
        Node* start = *L;
        if(pos == Size){
            Delete_last(&(*L));
        }else{
            Node* prev;
            for(int i = 1;i<pos;i++){
                prev = start;
                start = start->Next;
            }
            prev->Next = start->Next;
            delete start;
        }
    }
    return;
}
void Delete_last(Node** L){
    if(*L == nullptr){
        return;
    }else{
        Node* Last = *L;
        Node* prev;
        while(Last->Next != nullptr){
            prev = Last;
            Last = Last->Next;
        }
        prev->Next = nullptr;
        delete Last;
        return;
    }
}
void reverse_List(Node** N){
    Node*Help = *N;
    Node* A = nullptr;
    Node* B = nullptr;
    if(*N == nullptr || Help->Next == nullptr){
        return;
    }else{
        while(Help != nullptr){
            B = Help->Next;
            Help->Next = A;
            A = Help;
            Help = B;
        }
        *N = A;
        return;
    }
}
void Insert_beg(Node** L,int data){
    Node* nov = new Node;
    nov->data = data;
    if(*L == nullptr){
        nov->Next = nullptr;
        *L = nov;
        return;
    }else{
        nov->Next = *L;
        *L = nov;
        return;
    }
}
void list_tri(Node** Head){
    Node* start = *Head;
    Node*A = nullptr,*B = nullptr;
    while(start->Next != nullptr){
        A = start;
        B = start->Next;
        while(B != nullptr){
            if(A->data > B->data){
                int aide = A->data;
                A->data = B->data;
                B->data = aide;
            }
            B = B->Next;
        }
        start = start->Next;
    }  
    return;
}
void Insert_pos(Node**L,int pos,int data){
    if(pos == 1){
        Insert_beg(&(*L),data);
    }else{
        if(pos == size_liste(*L)+1){
            Insert_end(&(*L),data);
        }else{
            Node* nov;
            nov = new Node;
            nov->data = data;
            Node* Next = *L;
            Node* prev;
            int i = 1;
            while(i<pos && Next != nullptr){
                prev = Next;
                Next = Next->Next;
                i++;
            }
            prev->Next = nov;
            nov->Next = Next;
        }
    }
    return;
}
void Insert_end(Node** L,int data){
    if(*L == nullptr){
        Insert_beg(&(*L),data);
    }else{
        Node* Last = *L;
        Node* nov;
        nov = new Node;
        nov->data = data;
        nov->Next = nullptr;
        while(Last->Next != nullptr){
            Last = Last->Next;
        }
        Last->Next = nov;
    }
}
int Position(Node *N,int x){
    Node * courant;
    courant=N;
    int pos=1;
    while ((courant!=NULL)&&(courant->data <x))
    {
        courant =courant->Next;
        pos++;
    
    }
    return pos;    
}
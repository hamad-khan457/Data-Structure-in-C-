#include<iostream>
using namespace std;
struct node{
    int data;
    node * next;
    node(int value){
        data = value;
        next = NULL;
    }
};

node * first = NULL;
node * last = NULL;
 void insertAtfirst(int value){
    node * n = new node(value);
    if(first == last == NULL){
        first = last = n;
    }
    else{
        n->next = first;
        first = n;
    }
 }
 void insertAtend(int value){
    node * n = new node(value);
    if(first == last == NULL){
        first = last = n;
    }
    else{
        last->next = n;
        last = n;
    }
 }
 void insertAfterkey(int value,int key){
    if(first==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    else if(last->data == key){
        insertAtend(value);
        return;
    }
    else{
        node * temp = first;
        while(temp != NULL && temp->data != key){
            temp = temp->next;
        }
        if(temp != NULL){
            node* n = new node(value);
             n->next = temp->next;
             temp->next = n;   
        }
        else{
            cout<<"key not fond"<<endl;
        }
    }
 }
 void insertbeforkey(int value,int key){
    if(first==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    else if(first->data == key){
        insertAtfirst(value);
        return;
    }
    else{
        node * temp = first;
        while(temp->next != NULL && temp->next->data != key){
            temp = temp->next;
        }
        if(temp != NULL){
            node* n = new node(value);
             n->next = temp->next;
             temp->next = n;   
        }
        else{
            cout<<"key not fond"<<endl;
        }
    }
 }
    void deletefromstart(){
        if(first == NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        node * todel = first;
        first = first->next;
        delete(todel);
    }
    void deletefromlast(){
        if(first == NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        node * temp = first;
        node * previous;
        while(temp->next != NULL){
            previous = temp;
            temp = temp->next;
        }
        delete(temp);
        if(previous != NULL){
            previous->next = NULL;
            last = previous;
        }
        else{
            first = last = NULL;
        }
    }

        void deletebeforspecific(int key){
            if(first == NULL){
            cout<<"list is empty"<<endl;
            return;
            }
            if(first->data == key){
                deletefromstart();
            }
            else{
                node * temp = first;
                while(temp->next != NULL && temp->next->next != NULL && temp->next->next->data != key){
                    temp = temp->next;
                }
                if(temp != NULL){
                    
                     node * todel = temp->next;
                    temp->next = temp->next->next;                   
                    delete(todel);
                }
            }
        }
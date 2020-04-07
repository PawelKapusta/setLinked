//
// Created by sony on 04.03.2020.
//

#ifndef ZESTAW1B_SETLINKED_H
#define ZESTAW1B_SETLINKED_H
#define SIZE 300000

#include <iostream>
using namespace std;

template <class T>
class SetLinked{

public:
    struct Node{
       T x;
       Node * next = nullptr;

    };
    Node * head;
    Node * tail;
    int sizeSet=0;
    SetLinked(){
        head = nullptr;
        tail= nullptr;
    }
    void insert(T x){
        Node *newNode = new Node;
        newNode->x = x;
        newNode->next = nullptr;
        Node * currentNode = head;
        while(currentNode  != nullptr){
            if (newNode -> x == currentNode -> x){
                cout << "This element already exist in this set!" << endl;
                return;
            } else{
                currentNode = currentNode -> next;
            }
        }if(sizeSet == 0){
            head=newNode;
            tail=newNode;
        } else if(sizeSet == SIZE){
            cout << "Set is FULL! " << endl;
            return;
        } else if( head -> x >= newNode -> x){
                newNode -> next = head;
                head = newNode;
        }else {
            Node * current = head;
            while(current -> next != nullptr && current -> next -> x < newNode -> x){
                current = current-> next;
            }
            newNode -> next = current -> next;
            current -> next = newNode;
        }
        sizeSet++;
    }
    void remove(T x){
        if(sizeSet == 0){
            cout<<"Set is empty" << endl;
            return;
        }
        if(head->x == x){
                Node * temp = head -> next;
                delete(head);
                sizeSet--;
                head = temp;
                if(sizeSet == 0){
                    return;
                }
            } else {
                Node *tmp = head;
                while(tmp!= nullptr && tmp -> next -> x != x){
                    tmp = tmp->next;
                }
                Node* toBeforeRemove = tmp;
                Node * toRemove = tmp -> next;
                tmp -> next = tmp -> next -> next;
                delete(toRemove);
                sizeSet--;
            }
    }
    void printSet(){
        if (sizeSet == 0) {
            cout <<"Empty Set" << endl;
            return;
        }
        else {
            Node * tmp=head;
            while (tmp != nullptr) {
                cout << tmp->x << " ";
                tmp=tmp->next;
            }
        }
        cout << endl;
    }

    void size(){
        cout <<"Size: " << sizeSet << endl;
    }
    static SetLinked mergeTwoSets(const SetLinked& a, const SetLinked& b) {
        SetLinked<T> c;
        auto currentA = a.head;
        auto currentC = c.head;
        while(currentA != nullptr)
        {
               c.insert(currentA ->x);
               currentA = currentA -> next;
        }
        auto currentB = b.head;

        while (currentB != nullptr ) {
            c.insert(currentB -> x);
            currentB = currentB -> next;
        }

        return c;
    }
    static SetLinked productOfTwoSets(const SetLinked& a, const SetLinked& b) {
        SetLinked<T> c;

        for  (Node * currentA = a.head;  currentA != nullptr ; currentA = currentA -> next) {
            for (Node * currentB = b.head; currentB != nullptr ; currentB = currentB -> next) {
                if(currentA -> x == currentB -> x){
                    c.insert(currentA -> x);
                }
            }
        }

        return c;
    }
    static SetLinked differencesBetweenTwoSets(const SetLinked& a, const SetLinked& b){
        SetLinked<T> c;
        for  (Node * currentA = a.head;  currentA != nullptr ; currentA = currentA -> next) {
            c.insert(currentA -> x);
        }
        Node * currentB = b.head;
        while(currentB != nullptr){
            if (c.isExistInThisSet(currentB -> x)){
                c.remove(currentB -> x);
            }
            currentB = currentB -> next;
        }
        return c;
    }
    bool areTheSame(const SetLinked& a , const SetLinked& b){
        Node * currentA = a.head;
        Node * currentB = b.head;
        while(currentA != nullptr && currentB != nullptr){
            if (currentA -> x != currentB -> x){
                return false;
            }
            currentA = currentA -> next;
            currentB = currentB -> next;
        }
        return true;
    }
    bool isExistInThisSet(T x){
        Node * tmp = head;
        while(tmp != nullptr){
            if(tmp->x == x){
                return true;
            }
            tmp = tmp-> next;
        }
        return false;
    }

};
#endif //ZESTAW1B_SETLINKED_H

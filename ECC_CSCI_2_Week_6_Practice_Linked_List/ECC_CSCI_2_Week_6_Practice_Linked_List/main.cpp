/*
 Program Name: main.cpp
 Programmer: Moris Gomez
 Date: Sunday 03/20/2024
 Version Control: 5.0
 About: Week 6, CSCI 2, PRACTICE.
 Description:
 Create a linked list with 4 Nodes using a class and not a structure.
 create 1) a delete function and 2) display function.
*/

#include <iostream>
using namespace std;

class Node
{
public: //to change data, next of a Node directly outside class.
    int data;
    Node* next;
public:
    //default constructor:
    Node()
    {
        data = 0;
        next = NULL;
    }
};//end Node class.

class LinkedList
{
public:
    Node *head; //creates head pointer, but cannot change value outside class if set to private.
public:
    //default constructor:
    LinkedList()
    {
        head = NULL; //head points NULL bc no Node yet.
    }
    
    //member functions:
//FUNCTION #1: to delete a Node:
    void deleteNode(int num)
    {
        Node *current = head; //hold current Node.
        Node *temp = head; //hold temporary Node when traversing.
        Node *x; //for pointer that will be deleted.
        if(head != NULL) //there is a list.
        {
            while(current->data != num) //as long as no matching value...
            {
                temp = current; //keep traversing.
                current = current->next; //keep traversing.
            } //end while loop bc num = a value...
            if(current->data == num) //found matching Node...
            {
                if(current == head) //if matching Node is the head Node.
                {
                    x = current;
                    head = current->next; //point head to 2nd Node.
                    delete x; //delete pointer x. does this delete the node too??
                } //end nested, nested if in while loop.
                else if(current->next == NULL) // matching Node is the tail.
                {
                    x = current; //make x point to current pointing to tail.
                    temp->next = NULL; //make new tail next point to NULL.
                    delete x; //delete pointer.
                } //end nested, nested else if in while loop.
                else //matching Node is b/w head and tail.
                {
                    x = current;
                    current = current->next; //previous Node needs point to Node after current Node.
                    temp->next = current;
                    delete x; //delete x pointer.
                } //end nested, nested else.
            } //end nested if.
        } //end outer if.
        else
        {
            cout << "!!!!there is no list. please make one!!!!" << endl;
        } //end outer else.
    } //end deleteNode function.
//FUNCTION #2: to display Linked List:
    void display()
    {
        //to traverse list w no edits, inly need a current pointer.
        Node *current = head;
        int counter = 1;
        while(current != NULL)
        {
            cout << "this is Node " << counter << " with address of: " << current << endl; //for 1st Node.
            cout << "Node " << counter << " has 'data' value of: " << current->data << endl; //for 1st Node.
            cout << "Node " << counter << " has 'next' value of: " << current->next << endl; //for 1st Node.
            cout << "----------------" << endl;
            current = current->next;
            counter = counter + 1;
            } //end while loop.
        } //end display function.
};//end LinkedList class.

int main()
{
    //create list w no Nodes:
    LinkedList listOne;
    cout << listOne.head << endl; //NULL.
    
    //create 4 nodes & set data values:
    Node *node1 = new Node;
    node1->data = 3;
    Node *node2 = new Node;
    node2->data = 6;
    Node *node3 = new Node;
    node3->data = 9;
    Node *node4 = new Node;
    node4->data = 12;
    
    //assign head pointer from listOne to 1st Node:
    listOne.head = node1;
    //link node1 to 2nd:
    node1->next = node2;
    //link node2 to 3rd:
    node2->next = node3;
    //link node3 to 4th:
    node3->next = node4;
    //link node4 to NULL:
    node4->next = NULL; //also each Node has default next of NULL.
    
    //display list:
    listOne.display();
    
    //delete first Node:
    listOne.deleteNode(3);
    listOne.display();
    return 0;
}

/*
 NOTE:
 1)
 The deleteNode function in this program only deletes Nodes we know for sure are in
 the Linked List. If we try to delete a Node that does not exist, the program
 breaks because there is no logic for that path. The logic for this path can be
 added in the while loop as: while(current->data != m && current != NULL). If we
 reach current == NULL, this means we are at the end of list w/o a matching Node.
 2)
 A function that will traverse a list and make a change will always need a temp and
 a current pointer. The temp is used to properly stitch the previous Node w/ the
 following Node after a change. Current simply holds the Node being looked at.
 */

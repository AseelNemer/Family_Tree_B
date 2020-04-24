#ifndef FAMILYTREE_H
#define FAMILYTREE_H
#include<stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;

namespace family{
class node
{
public:
    string data;
    node *father;
    node *mother;
    int tag;
    int hight;
    
    node(string name)
  {
    this->data = name;
    this->father = NULL;
    this->mother = NULL;
    this->hight=0;
    this->tag=0;
 };
  
};



class Tree {

    public:

    node* root;
    int size;

    Tree(string name)
    {
        this->root = new node(name);
        this->size=0;
    };
    ~ Tree()
    {
        delete(root);   
    }
    
    Tree& addFather(string , string); // Tells the tree that the father of name is fname.
    Tree& addMother(string, string);// Tells the tree that the mother of name is mname.
    
    void find_node(node *root, node** temp ,const string child);
    void display();  // displays the tree in a human-friendly format.
    
    string relation(string);  // prints the relationship between this name and the root
    string find(string); // tells us whats the name of the bpersons who has this relation with the root
    
    void  display(node *n);

    node* findName(int level,node *root,node **temp,int tag );
    void remove(string name); // remove this person and all the others under him
    void deleteSubTree(node *node);
   // void deletenode(node* node);  


//void _deletenode(node* node);
//void deletenode(node** temp);





    };
}
#endif
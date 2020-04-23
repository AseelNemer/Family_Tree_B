#include <iostream>
#include <string.h>
#include "FamilyTree.hpp"
#include <string>
#include <stdio.h>
#include <exception>
#include <bits/stdc++.h>
#pragma once




using namespace std;
using namespace family;

 

 Tree& Tree::addFather( string child, string father) 
 {
     
    if(this->root==NULL)
    {
        out_of_range{"The Family tree is Empty!"};
        return  *this;
    }
    node *temp;
    find_node(this->root,&temp ,child);
    if(temp==NULL)
    {
        out_of_range{"cannot find this child!"};
        return *this;
    }
    else
    {
        temp->father=new node("father");
        this->size++;
        temp->father->hight=temp->hight+1;
        temp->father->tag=0;

    }
    return *this;
    

 }
 
Tree& Tree::addMother( string child, string mother)
 {
    if(this->root==NULL)
    {
        out_of_range{"The Family tree is Empty!"};
        return *this;
    }
    node *temp;
    find_node(this->root,&temp ,child);
    if(temp==NULL)
    {
        out_of_range{"cannot find this child!"};
            return *this;
    }
    else
    {
        temp->mother=new node("mother");
        this->size++;
        temp->mother->hight=temp->hight+1;
        temp->mother->tag=1;
    }
       return *this;

 }
void Tree::find_node(node *root, node** temp ,const string child) {

    if(root == NULL) *temp=NULL;
    if(root->data == child)
    {
      *temp = root  ;
    }
    else
    {
        Tree::find_node(root->father, temp ,child );
        Tree::find_node(root->mother, temp ,child );
    }
}

 //tells us whats the name of the persons who has this relation with the root

 string Tree::find(string name)
 {
    int l =name.length(),i=0;
    
    if(name.compare("mother")==0||name.compare("Mother")==0)
    {
        return this->root->mother->data;
    }
    if(name.compare("father")==0||name.compare("Father")==0)
    {
        return this->root->father->data;
    }
    if(name.compare("grandmother")==0||name.compare("Grandmother")==0)
    {
        return this->root->mother->mother->data;
    }
    if(name.compare("grandfather")==0||name.compare("Grandfather")==0)
    {
        return this->root->father->father->data;
    }

     int level = 3;
        string s = name;
        while ((s != "grandmother" ) && (s != "grandfather"))
        {
            s = s.substr(6,(s.length()-6));
            level++;
        }
        string findname=findName(this->root,s, level);
        if (findname == "")
        {
            throw runtime_error("No such a " + name);
        }
        return findname;
        

 }

string Tree :: findName(node * T,string name, int level)
{
    
    string findname;
     if (T == NULL)
    {
        return "";
    }
    
   if(T->father == NULL && T->mother == NULL)
   {
       return "";
   }

   if(level == 2 )
   {
       if (name == "grandmother")
       {
           findname = T->mother->data;
       }
       else
       {
           findname = T->father->data;
       }       
       return findname;
   }
    findName(T->father,name, level-1);

    if(level > 0)
    {
        return findname;
    }

    findName(T->mother,name, level-1);

    return findname;
}
string Tree::relation(string name)
 {
    string relate = " ";
   return relation1(name, relate, this->root);
    //cout<<relate<<endl;
    node *temp=nullptr;
    find_node(this->root, &temp , name);
    if(temp==NULL)
    {
        return "unrelated" ;
    }
    
    string tempname=temp->data;

    if(tempname.compare(this->root->data)==0 && temp->hight==0)
    {
        return "me .";
    }
    if(temp->hight==1 && tempname.compare(this->root->mother->data)==0)
    {
        return "mother";
    }
    if(temp->hight==1 && tempname.compare(this->root->father->data)==0)
    {
        return "father";
    }
     if(temp->hight==2 && (tempname.compare(this->root->father->father->data)==0 ||tempname.compare(this->root->mother->father->data)==0))
    {
        return "grandfather";
    }
     if(temp->hight==2 && (tempname.compare(this->root->father->mother->data)==0 ||tempname.compare(this->root->mother->mother->data)==0))
    {
        return "grandmother";
    }
    if(temp->hight>2)
    {
        string ans="";
        int h=temp->hight;
        while(h!=2)
        {
            ans=ans+"great-";
            h--;
        }
        if(temp->tag==1)
            ans+="grandmother";
        if(temp->tag==0)
            ans+="grandfather";
        
    }
    
 }
 
 void Tree::display()
 {
    node* ptr = root;

    if(ptr==NULL)
        return;

    while(ptr!=NULL)
    {
        
        

    }
 }

void Tree::remove(string name)
{
    node *temp=find(this *root,temp,name)
    if(temp!=NULL)
    {
        deleteSubTree(temp);
    }
    else 
        cout << "the tree is empty" << endl;
}
void Tree::deleteSubTree(node *root)
{

    if (root != NULL)
    {
        deleteSubTree(root->getFather());
        deleteSubTree(root->getMother());
        delete root;
    }
}

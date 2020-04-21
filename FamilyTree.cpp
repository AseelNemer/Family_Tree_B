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

 string Tree::find(string a)
 {
    int l =a.length(),i=0;
    node *root=*this->root;
    if(a.compare("mother"==0)||a.compare("Mother"))
    {
        return root->mother->data;
    }
    if(a.compare("father"==0)||a.compare("Father"))
    {
        return root->father->data;
    }
    if(a.compare("grandmother"==0)||a.compare("Grandmother"))
    {
        return root->mother->mother->data;
    }
    if(a.compare("grandfather"==0)||a.compare("Grandfather"))
    {
        return root->father->father->data;
    }
     while((relat.length() > 6) && (relat.substr(0,6).compare("great-") == 0)){
        relat=relat.substr(6);
        depth++;
    }





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
        cout<< ptr->data <<endl;
        display(ptr->left);
        ptr = ptr->right;
    }
 }

 void Tree::remove(string rname){
    ptr = node(rname);
    node* temp =ptr;

    if(ptr==NULL)
        return;

    while(ptr!=NULL)
    {
        remove(ptr->left);
        temp = ptr;
        ptr = ptr->right;
        delete temp;
    }

    start = NULL;
  }
 }


 void Tree::remove(node* subRoot){
  if(subRoot==nullptr){
    return;
  }
  deleteNode(subRoot->father);
  deleteNode(subRoot->mother);
  delete subRoot;
 }
}

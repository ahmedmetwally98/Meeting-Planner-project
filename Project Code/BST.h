/*
 * BST.h
 *
 *  Created on: May 7, 2020
 *      Author: student
 */

#ifndef BST_H_
#define BST_H_

#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<assert.h>
using namespace std;

class BST
{
private:

  struct node;
  typedef node* link;
  struct node
  {
    string title;
    int day_key1;
    int hour_key2;
    link leftptr;
    link rightptr;
  };
link root;
int size;
bool addLeafPrivate(string t, int d, int h, link ptr);
void findNodeprivate(string nodeT, int d, int h, link ptr, string cmdType);
void printPrivate(link ptr);
void deleteleafPrivate(int d, int hr, link ptr);
void removeMatchprivate(link ptr1, link ptr2, string nodeDirection);
void removeRootNode();
void findSmallestInRightSubtree(link ptr1, int & d, int & hr, string & str);
link creatLeaf(const string t, const int d, const int h);

public:
  BST();
  void insertLeaf(const string t, const int d, const int h);
  int treeSize();
  bool isEmpty();
  void find_modifyNode(string nodeTitle, int d, int hr, string command); //this function used to get string (title) for a given day and hour
  void deleteLeaf(const int d, const int hr);//delete meeting given its day and hour
  void printTree();
};


#endif /* BST_H_ */

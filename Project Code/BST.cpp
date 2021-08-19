/*
 * BST.cpp
 *
 *  Created on: May 7, 2020
 *      Author: student
 */


#include"BST.h"

extern ofstream outputFile;

BST::BST()
{
  root = NULL;
  size = 0;
}
/**************************************function #1**********************************************/

BST::link BST::creatLeaf(string t, int d, int h)
{/*adding a leaf and return its address.
  this function is made to simplify addLeafPrivate function*/
  link addedNode = new node;
  assert(addedNode);
  addedNode->title = t;
  addedNode->day_key1 = d;
  addedNode->hour_key2 = h;
  addedNode->leftptr = NULL;
  addedNode->rightptr = NULL;
  size++;
  return addedNode;
}
/**************************************function #2**********************************************/

int BST::treeSize()
{
  return size;
}
/**************************************function #3**********************************************/

bool BST::isEmpty()
{
  if(size == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
/**************************************function #4**********************************************/

void BST::insertLeaf(string t, int d, int h)
{//here this function is worry about data which is going to be inserted
  addLeafPrivate(t, d, h, root);
}
/**************************************function #5**********************************************/

bool BST::addLeafPrivate(string t, int d_key1, int h_key2, link ptr)
{//here this function is worry about searching for the right place to add this newNode
  if(isEmpty())
  {//tree is Empty
    root = creatLeaf(t, d_key1, h_key2);
    return true;
  }
  else
  {//tree is not Empty
	  if(d_key1 < ptr->day_key1)
	  {//case 1: go left
		  if(ptr->leftptr != NULL)
      	  {//make sure that left ptr is pointing to something not NULL
			  addLeafPrivate(t, d_key1, h_key2, ptr->leftptr);
      	  }
		  else
		  {//now the left ptr is pointing to NULL so, here we will add our node
			  ptr->leftptr = creatLeaf(t, d_key1, h_key2);
			  return true;
		  }
	  }
    else
    {
    	if(d_key1 > ptr->day_key1)
    	{//case 2: go right
    		if(ptr->rightptr != NULL)
    		{//make sure that right ptr is pointing to something not NULL
    			addLeafPrivate(t, d_key1, h_key2, ptr->rightptr);
    		}
    		else
    		{//now the right ptr is pointing to NULL so, here we will add our node
    			ptr->rightptr = creatLeaf(t, d_key1, h_key2);
    			return true;
    		}
    	}
      else
      {
    	  if(d_key1 == ptr->day_key1 && h_key2 < ptr->hour_key2)
    	  {//case 3: go left
    		  if(ptr->leftptr != NULL)
    		  {//make sure that left ptr is pointing to something not NULL
    			  addLeafPrivate(t, d_key1, h_key2, ptr->leftptr);
    		  }
    		  else
    		  {
    			  ptr->leftptr = creatLeaf(t, d_key1, h_key2);
    			  return true;
    		  }
    	  }
        else
        {
        	if(d_key1 == ptr->day_key1 && h_key2 > ptr->hour_key2)
        	{//case 4: go right
        		if(ptr->rightptr != NULL)
        		{//make sure that right ptr is pointing to something not NULL
        			addLeafPrivate(t, d_key1, h_key2, ptr->rightptr);
        		}
        		else
        		{//now the right ptr is pointing to NULL so, here we will add our node
        			ptr->rightptr = creatLeaf(t, d_key1, h_key2);
        			return true;
        		}
        	}
          else
          {
        	  cout<<"Conflict "<<d_key1<<" "<<h_key2 << endl;
        	  outputFile << "Conflict " << d_key1 << " " << h_key2 << endl;
        	  return false;
          }
        }
      }
    }
  }
  return true;
}
/**************************************function #6**********************************************/

void BST::find_modifyNode(string nodeTitle, const int d, const int hr, string command)
{
    findNodeprivate(nodeTitle, d, hr, root, command);
}
/**************************************function #7**********************************************/

void BST::findNodeprivate(string nodeT, int d, int hr, link ptr, string cmdType)
{
	if(isEmpty())
	{
		outputFile << "Empty " << d << " " << hr <<endl;
		cout<< "Empty " << d << " " << hr <<endl;
	}
	else if(d < ptr->day_key1)
	{
		if(ptr->leftptr != NULL)
		{
			findNodeprivate(nodeT, d, hr, ptr->leftptr, cmdType);
		}
		else
		{
			outputFile << "Empty " << d << " " << hr <<endl;
			cout<< "Empty " << d << " " << hr <<endl;
		}
	}
	else if(d > ptr->day_key1)
	{
		if(ptr->rightptr != NULL)
		{
			findNodeprivate(nodeT, d, hr, ptr->rightptr, cmdType);
		}
		else
		{
			outputFile << "Empty " << d << " " << hr <<endl;
			cout<< "Empty " << d << " " << hr <<endl;
		}
	}
	else if(d == ptr->day_key1 && hr < ptr->hour_key2)
	{
		if(ptr->leftptr != NULL)
		{
			findNodeprivate(nodeT, d, hr, ptr->leftptr, cmdType);
		}
		else
		{
			outputFile << "Empty " << d << " " << hr <<endl;
			cout<< "Empty " << d << " " << hr <<endl;
		}
	}
	else if(d == ptr->day_key1 && hr > ptr->hour_key2)
	{
		if(ptr->rightptr != NULL)
		{
			findNodeprivate(nodeT, d, hr, ptr->rightptr, cmdType);
		}
		else
		{
			outputFile << "Empty " << d << " " << hr <<endl;
			cout<< "Empty " << d << " " << hr <<endl;
		}
	}
	else
	{
		if(cmdType == "Find")
		{
			cout<< ptr->title <<endl;
			outputFile << ptr->title << endl;
		}
		else if(cmdType == "MOD")
		{
			ptr->title = nodeT;
		}
	}
}
/**************************************function #8**********************************************/

void BST::printTree()
{
	printPrivate(root);
}
/**************************************function #9**********************************************/

void BST::printPrivate(link ptr)
{
	if(!isEmpty())
	{
		//go left
		if(ptr->leftptr != NULL)
		{
			printPrivate(ptr->leftptr);
		}
		//process on the node (printing its contain)
		cout << ptr->title <<" "<< ptr->day_key1<< " " << ptr->hour_key2 << endl;
		outputFile << ptr->title <<" "<< ptr->day_key1<< " " << ptr->hour_key2 << endl;
		//go right
		if(ptr->rightptr != NULL)
		{
			printPrivate(ptr->rightptr);
		}
	}
	else
	{//case of tree (planner) is empty
		cout << "Empty Planner"<<endl;
		outputFile <<"Empty Planner"<<endl;
	}

}
/**************************************function #10*********************************************/

void BST::deleteLeaf(const int day, const int hour)
{
	deleteleafPrivate(day, hour, root);
}

void BST::deleteleafPrivate(const int d, const int hr, link ptr)
{
	//check if the planner tree is empty or not
	if(isEmpty())
	{
		cout << "Empty " << d <<" "<<hr<<endl;
		outputFile << "Empty " << d << " " << hr <<endl;
		return;
	}
	/*
	 * flow is to get the location where the next node is the required node to be deleted
	 * so,  if the meant node is go to be in right then we call the removeMatch with string variable right
	 * and, if the meant node is go to be in left then we call the removeMatch with string variable left
	 * and, if the meant node is go to be the (root node) then we call the removeRootNode function which will delete the root node
	 * */
	else
	{
		if(d > ptr->day_key1 && ptr->rightptr!=NULL)
		{
			if((ptr->rightptr->day_key1 == d) && (ptr->rightptr->hour_key2 == hr))
			{
				removeMatchprivate(ptr, ptr->rightptr, "right");
			}
			else
			{
				deleteleafPrivate(d, hr, ptr->rightptr);
			}
		}
		else
		{
			if(d < ptr->day_key1 && ptr->leftptr!=NULL)
			{
				if((ptr->leftptr->day_key1 == d) && (ptr->leftptr->hour_key2 == hr))
				{
					removeMatchprivate(ptr, ptr->leftptr, "left");
				}
				else
				{
					deleteleafPrivate(d, hr, ptr->leftptr);
				}
			}
			else
			{
				if((d == ptr->day_key1 && hr > ptr->hour_key2) && (ptr->rightptr!=NULL))
				{
					if(ptr->rightptr->hour_key2 == hr)
					{
						removeMatchprivate(ptr, ptr->rightptr, "right");
					}
					else
					{
						deleteleafPrivate(d, hr, ptr->rightptr);
					}
				}
				else
				{
					if((d == ptr->day_key1 && hr < ptr->hour_key2) && (ptr->leftptr!=NULL))
					{
						if(ptr->leftptr->hour_key2 == hr)
						{
							removeMatchprivate(ptr, ptr->leftptr, "left");
						}
						else
						{
							deleteleafPrivate(d, hr, ptr->leftptr);
						}
					}
					else
					{
						if(d == ptr->day_key1 && hr == ptr->hour_key2)
						{//matching is happen with the root node so, we go to delete this root node
							removeRootNode();
						}
						else
						{
							cout << "Empty " << d << " " << hr<<endl;
							outputFile << "Empty " << d << " " << hr<<endl;
						}
					}
				}
			}
		}
	}
}
/**************************************function #11*********************************************/

/*this function is called only when matched node is found*/
void BST::removeMatchprivate(link ptr1, link matchptr, string nodeDirection)
{
	if(!isEmpty())
	{//this condition should be true always but we made it for safety
		link deletenode;
		deletenode = matchptr;
		int key1, key2;
		string strTitle;
		//case A: for the matched node has no children
		if(matchptr->leftptr == NULL && matchptr->rightptr == NULL)
		{
			deletenode = matchptr;
			if(nodeDirection == "right")
			{
				ptr1->rightptr = NULL;
				delete deletenode;
				size = size - 1;
			}
			else
			{
				ptr1->leftptr = NULL;
				delete deletenode;
				size = size - 1;
			}
		}
		else
		{ //case B: for matched node has only on child whether was on left or right
			if(matchptr->leftptr == NULL && matchptr->rightptr != NULL)
			{//case b1: child of deleted node was on right
				if(nodeDirection == "right")
				{
					ptr1->rightptr = matchptr->rightptr;
					matchptr->rightptr = NULL;
					delete deletenode;
					size = size - 1;
				}
				else if(nodeDirection == "left")
				{
					ptr1->leftptr = matchptr->rightptr;
					matchptr->rightptr = NULL;
					delete deletenode;
					size = size - 1;
				}
			}
			else if(matchptr->leftptr != NULL && matchptr->rightptr == NULL)
			{//case b2: child of deleted node was on left
				if(nodeDirection == "right")
				{
					ptr1->rightptr = matchptr->leftptr;
					matchptr->leftptr = NULL;
					delete deletenode;
					size = size - 1;
				}
				else if(nodeDirection == "left")
				{
					ptr1->leftptr = matchptr->leftptr;
					matchptr->leftptr = NULL;
					delete deletenode;
					size = size - 1;
				}
			}
			//case C: if the deleted node has two children
			else if(matchptr->leftptr != NULL && matchptr->rightptr != NULL)
			{/*in this case:
			 * we go to find the smallest node in the right subtree then,
			 * overwriting its containing into the matched node which we want to delete
			 * then delete this smallest node
			 */
				findSmallestInRightSubtree(matchptr->rightptr, key1, key2, strTitle);
				deleteleafPrivate(key1, key2, matchptr);
				matchptr->day_key1 = key1;
				matchptr->hour_key2 = key2;
				matchptr->title = strTitle;
			}
		}
	}
}
/**************************************function #12**********************************************/

void BST::removeRootNode()
{
	if(!isEmpty())
	{
		link delnode;
		delnode = root;
		int key1, key2;
		string strTitle;
		//case 1: for root has no children
		if((root->leftptr == NULL) && (root->rightptr == NULL))
		{
			delete delnode;
			size = size - 1;
		}
		else
		{//case 2: for root has only one child
			if((root->leftptr != NULL) && (root->rightptr == NULL))
			{//child on left
				root = root->leftptr;
				delnode->leftptr = NULL;//to completely disconnecting the root from the tree
				delete delnode;
				size = size - 1;
			}
			else
			{
				if((root->leftptr == NULL) && (root->rightptr != NULL))
				{//child on right
					root = root->rightptr;
					delnode->rightptr = NULL;//to completely disconnecting the root from the tree
					delete delnode;
					size = size - 1;
				}
				else
				{//case 3: for root has 2 children
					if(root->leftptr != NULL && root->rightptr != NULL)
					{
						findSmallestInRightSubtree(root->rightptr, key1, key2, strTitle);
						deleteleafPrivate(key1, key2, root);
						root->day_key1 = key1;
						root->hour_key2 = key2;
						root->title = strTitle;
					}
				}
			}
		}
	}
}


/**************************************function #13**********************************************/

void BST::findSmallestInRightSubtree(link ptr2node, int &key1, int &key2, string &strtitle)
{
	if(ptr2node->leftptr != NULL)
	{
		findSmallestInRightSubtree(ptr2node->leftptr,key1, key2, strtitle);
	}
	else
	{
		//copying content of smallest node, to be then added to the deleted node
		if (ptr2node->leftptr == NULL)
		{

			key1 = ptr2node->day_key1;
			key2 = ptr2node->hour_key2;
			strtitle = ptr2node->title;
		}
	}
}


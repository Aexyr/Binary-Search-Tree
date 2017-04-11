#include "BST.h"

BST::BST() : root(nullptr) {}

//void BST::insert(int insertItem)
//{
//	Node  *newNode = new Node;
//	newNode->data = insertItem;
//	newNode->llink = nullptr;
//	newNode->rlink = nullptr;
//	insert(root, newNode);
//}

//void BST::insert( Node* &p, Node *newNode)
//{
//	if (p == nullptr)
//		p = newNode;
//	else if (p->data == newNode->data)
//		cerr << "No duplicates are allowed." << endl;
//	else if (p->data > newNode->data)
//		insert(p->llink, newNode);
//	else
//		insert(p->rlink, newNode);
//}

void BST::inorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		inorderTraversal(root);
	}
}

void BST::morrisInorderTrav() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		Node* current = root;
		Node* previous;
		while (current != nullptr)
		{
			if (current->llink == nullptr)
			{
				cout << current->data << " ";
				current = current->rlink;
			}
			else
			{
				previous = current->llink;
				while (previous->rlink != nullptr && previous->rlink != current)
				{
					previous = previous->rlink;
				}

				if (previous->rlink == nullptr)
				{
					previous->rlink = current;
					current = current->llink;
				}
				else
				{
					previous->rlink = nullptr;
					cout << current->data << " ";
					current = current->rlink;
				}
			}
		}
	}
}

void BST::inorderTraversal(const Node *p) const
{
	if (p != nullptr)
	{
		inorderTraversal(p->llink);
		cout << p->data << " ";
		inorderTraversal(p->rlink);
	}
}

void  BST::destroyTree(Node* &p)
{
	if (p != nullptr)
	{
		destroyTree(p->llink);
		destroyTree(p->rlink);
		delete p;
		p = nullptr;
	}
}

void  BST::destroyTree()
{
	destroyTree(root);
}

BST::~BST()
{
	destroyTree(root);
}


/***************************************************************

	Implement your functions below this line.

***************************************************************/

// Definition function insert (non-recursive) 
void BST::insert(int item)
{
	if (root != nullptr)
	{
		Node* temp = root;
		bool isDone = false;
		do {
			if (item == temp->data)
			{
				cout << "The item to insert is already in the list – duplicates are not allowed." << endl;
				isDone = true;
			}
			else if (item < temp->data)
			{
				if (temp->llink == nullptr)
				{
					temp->llink = new Node;
					temp->llink->data = item;
					isDone = true;
				}
				else
				{
					temp = temp->llink;
				}
			}
			else
			{
				if (temp->rlink == nullptr)
				{
					temp->rlink = new Node;
					temp->rlink->data = item;
					isDone = true;
				}
				else
				{
					temp = temp->rlink;
				}
			}
		} while (!isDone);
	}
	else
	{
		root = new Node;
		root->data = item;
	}
}

// Definition function totalNodes
int BST::totalNodes() const
{
	if (root == nullptr)
	{
		return 0;
	}
	
	return totalNodes(root);
}

// Definition function totalNodes (recursive)
int BST::totalNodes(const Node * p) const
{
	return (p != nullptr)? (1 + totalNodes(p->llink) + totalNodes(p->rlink)) : 0;
}

// Definition overloaded function preorderTraversal
void BST::preorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		preorderTraversal(root);
	}
}

void BST::morrisPreorderTrav() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		Node* current = root; 
		Node* previous;
		while (current != nullptr)
		{
			if (current->llink == nullptr)
			{
				cout << current->data << " ";
				current = current->rlink;
			}
			else
			{
				previous = current->llink;
				while (previous->rlink != nullptr && previous->rlink != current)
				{
					previous = previous->rlink;
				}

				if (previous->rlink == nullptr)
				{
					cout << current->data << " ";
					previous->rlink = current;
					current = current->llink;
				}
				else
				{
					previous->rlink = nullptr;
					current = current->rlink;
				}
			}
		}
	}
}

// Definition overloaded function preorderTraversal (recursive)
void BST::preorderTraversal(const Node * p) const
{
	if (p != nullptr)
	{
		cout << p->data << " ";
		preorderTraversal(p->llink);
		preorderTraversal(p->rlink);
	}
}

// Definition overloaded function postorderTraversal
void BST::postorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		postorderTraversal(root);
	}
}

void BST::morrisPostorderTrav() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		int level = 0;
		Node* current = root;
		Node* parent = new Node;
		Node* previous;
		while (current != nullptr)
		{
			if (current->llink == nullptr)
			{
				cout << current->data << " ";
				current = current->rlink;
			}
			else
			{
				previous = current->llink;
				while (previous->rlink != nullptr && previous->rlink != current)
				{
					previous = previous->rlink;
				}

				if (previous->rlink == nullptr)
				{
					previous->rlink = current;
					current = current->llink;
				}
				else
				{
					//if parent->data != current->rlink->data
					++level;
					previous->rlink = nullptr;
					current = current->rlink;
				}
			}
		}
	}
}

// Definition overloaded function postorderTraversal (recursive)
void BST::postorderTraversal(const Node * p) const
{
	if (p != nullptr)
	{
		postorderTraversal(p->llink);
		postorderTraversal(p->rlink);
		cout << p->data << " ";
	}
}

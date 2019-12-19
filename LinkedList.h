#include "stdafx.h"

using namespace std;

template <class T>
class LinkedList
{
	struct Node {
		T data;
		Node* next;
	};

	Node* m_head;
	Node* m_currentNode;
	Node* m_prevNode;
	int m_listSize;

	bool IsEmpty() const
	{
		if (m_listSize == 0)
		{
			return true;
		}
		else
			return false;
	}

public:
	LinkedList() //Constructor
	{
		m_head = NULL;
		m_currentNode = NULL;
		m_prevNode = NULL;
		m_listSize = 0;
	}

	void StartNodes() //Initialise Current and Previous nodes
	{
		m_currentNode = m_head;
		m_prevNode = m_currentNode;
	}

	Node* InitNewNode(T new_data) //Initialise a new node
	{
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->data = new_data;
		return new_node;
	}

	void AddHeadNode(Node* new_node)
	{
		new_node->next = m_head;
		m_head = new_node;
		StartNodes();
		m_listSize++;
	}

	void AddAtEnd(T new_data) //Add a Node at the end
	{
		Node* new_node = InitNewNode(new_data);
		new_node->next = NULL;

		if (m_head != NULL)
		{
			StartNodes();
			while (m_currentNode->next != NULL)
			{
				m_prevNode = m_currentNode;
				m_currentNode = m_currentNode->next;
			}
			m_currentNode->next = new_node;
		}
		else
		{
			m_head = new_node;
		}
		m_listSize++;
	}

	void AddAtStart(T new_data) //Add a new node at the beginning
	{
		Node* new_node = InitNewNode(new_data);
		AddHeadNode(new_node);
	}

	void DeleteHead() //Delete Head Node Function
	{
		m_head = m_head->next;
		cout << "\nNode Deleted" << endl;
		m_listSize--;
	}

	void DeleteAtStart() //Delete Head Node
	{
		if (IsEmpty())
		{
			cout << "\nList is already Empty" << endl;
		}
		else
		{
			DeleteHead();
		}
	}

	void DeleteAtEnd() //Delete Last Node
	{
		if (IsEmpty())
		{
			cout << "\nList is already Empty" << endl;
		}
		else
		{
			StartNodes();
			while (m_currentNode->next != NULL)
			{
				m_prevNode = m_currentNode;
				m_currentNode = m_currentNode->next;
			}
			m_prevNode->next = NULL;
			cout << "\nNode Deleted" << endl;
			m_listSize--;
		}
	}

	void DeleteAtPos(int position) //Delete Node at Position
	{
		int count;

		count = 1;

		if (IsEmpty())
		{
			cout << "\nList is already Empty" << endl;
		}
		else if(position > m_listSize)
		{
			cout << "\nPosition size larger then List" << endl;
			cout << "ListSize: " << m_listSize << endl;
		}
		else if (position == 1)
		{
			DeleteHead();
		}
		else
		{
			StartNodes();
			while (count != position)
			{
				m_prevNode = m_currentNode;
				m_currentNode = m_currentNode->next;
				count++;
			}
			m_prevNode->next = m_currentNode->next;
			m_listSize--;
		}
	}

	void DeleteByNumber(T new_data) //delete Node by Data
	{

		if (IsEmpty())
		{
			cout << "\nList is already Empty" << endl;
		}
		else
		{
			if (m_head->data == new_data)
			{
				DeleteHead();
			}
			else
			{
				StartNodes();
				while (m_currentNode->data != new_data)
				{
					m_prevNode = m_currentNode;
					m_currentNode = m_currentNode->next;
					if (m_currentNode->next == NULL && m_currentNode->data != new_data)
					{
						cout << "\nData Does not exist in this Linked-List" << endl;
						return;
					}
				}
				m_prevNode->next = m_currentNode->next;
			}
		}
	}

	void AddAtPosition(T new_data, int position) //Add a new node at a user defined position
	{
		int count = 1;

		Node* new_node = InitNewNode(new_data);

		if (m_listSize == 0 || position == 0)
		{
			AddHeadNode(new_node);
		}
		else if (position > m_listSize)
		{
			cout << "\nPosition value larger than list size. ";
			cout << "List Size: " << m_listSize << endl;
		}
		else if (position == 1)
		{
			AddHeadNode(new_node);
		}
		else
		{
			StartNodes();
			while (count != position)
			{
				m_prevNode = m_currentNode;
				m_currentNode = m_currentNode->next;
				count++;
			}
			new_node->next = m_currentNode;
			m_prevNode->next = new_node;
			m_listSize++;
		}
	}

	void AddBeforeElement(T new_data, int position) //Add a new node before a user defined node
	{
		int count = 1;

		Node* new_node = InitNewNode(new_data);

		if (m_listSize == 0 || position == 0 || position == 1)
		{
			AddHeadNode(new_node);
		}
		else if (position > m_listSize)
		{
			cout << "Position value larger then list size. ";
			cout << "List Size: " << m_listSize << endl;
		}
		else
		{
			StartNodes();
			while (count != position)
			{
				m_prevNode = m_currentNode;
				m_currentNode = m_currentNode->next;
				count++;
			}
			new_node->next = m_prevNode->next;
			m_prevNode->next = new_node;
			m_listSize++;
		}
	}

	void AddAfterElement(T new_data, int position) //Add a new node aftre a user defined node
	{
		int count = 1;

		Node* new_node = InitNewNode(new_data);

		if (position > m_listSize)
		{
			cout << "Position value larger then list size. ";
			cout << "List Size: " << m_listSize << endl;
		}
		else if (m_listSize == 0 || position == 0)
		{
			AddHeadNode(new_node);
		}
		else
		{
			StartNodes();
			while (count != position)
			{
				m_prevNode = m_currentNode;
				m_currentNode = m_currentNode->next;
				count++;
			}
			new_node->next = m_currentNode->next;
			m_currentNode->next = new_node;
			m_listSize++;
		}
	}

	void SearchByPosition(int position) //Search data at a Positon
	{
		int count = 1;

		if (m_listSize == 0 || position == 0)
		{
			cout << "\nList is empty" << endl;
		}
		else if (position > m_listSize)
		{
			cout << "\nPosition value larger than list size. ";
			cout << "List Size: " << m_listSize << endl;
		}
		else if (position == 1)
		{
			cout <<"\n"<< m_head->data<<endl;
		}
		else
		{
			StartNodes();
			while (count != position)
			{
				m_prevNode = m_currentNode;
				m_currentNode = m_currentNode->next;
				count++;
			}
			cout << "\n" << m_currentNode->data << endl;
		}
	}

	void SearchByData(T new_data) //Search a Node by it's Data
	{
		int count = 0;
		if (m_listSize == 0)
		{
			cout << "\nList is empty" << endl;
		}
		else
		{
			StartNodes();
			while (m_currentNode->data != new_data)
			{
				m_currentNode = m_currentNode->next;
				if (m_currentNode->next == NULL && m_currentNode->data != new_data)
				{
					cout << "\nData Does not exist in this Linked-List" << endl;
					return;
				}
				count++;
			}
			cout << "\n" << m_currentNode->data << endl;
			cout << "Position: " << count;
		}
	}

	void DisplayCount() const //Display number of nodes of linked list
	{
		cout << "List Size : " << m_listSize << endl;
	}

	void DisplayLL() const //Display elements of the linked list
	{
		Node* ptr;

		if (m_listSize == 0)
		{
			cout << "\nList Empty" << endl;
			return;
		}
		ptr = m_head;
		while (ptr != NULL)
		{
			cout << ptr->data << "\t";
			ptr = ptr->next;
		}
	}

	void LinkedListMenu() //Linked-List Menu UI
	{
		int LLChoice, position;
		//system("cls");
		bool quit;
		T element;

		quit = false;
	
		while (quit == false)
		{
			cout << "\nWelcome to Linked-List" << endl;
			cout << "1. Add Element "<<endl;
			cout << "2. Delete Element" << endl;
			cout << "3. Search Position" << endl;
			cout << "4. Search by Data" << endl;
			cout << "5. Display List Size" << endl;
			cout << "6. Display List" << endl;
			cout << "7. Exit" << endl;
			cout << "Your Choice: ";
			cin >> LLChoice;
			//system("cls");
	
			switch (LLChoice)
			{
			case 1:
				cout << "Where do you want to add the element? " << endl;
				cout << "1. At Start" << endl;
				cout << "2. At End" << endl;
				cout << "3. At Position" << endl;
				cout << "4. Before Element" << endl;
				cout << "5. After Element" << endl;
				cout << "Your Choice: ";
				cin >> LLChoice;
				switch(LLChoice)
				{
				case 1:
					cout << "Enter Data: ";
					cin >> element;
					AddAtStart(element);
					break;
				case 2:
					cout << "Enter Data: ";
					cin >> element;
					AddAtEnd(element);
					break;
				case 3:
					cout << "Enter Data: ";
					cin >> element;
					cout << "\nEnter Position";
					cin >> position;
					AddAtPosition(element, position);
					break;
				case 4:
					cout << "Enter Data: ";
					cin >> element;
					cout << "\nEnter Position: ";
					cin >> position;
					AddBeforeElement(element, position);
					break;
				case 5:
					cout << "Enter Data: ";
					cin >> element;
					cout << "\nEnter Position: ";
					cin >> position;
					AddAfterElement(element, position);
					break;
				default:
					cout << "\n Wrong Choice" << endl;
					break;
				}
				break;
			case 2:
				cout << "What element do you want to delete? " << endl;
				cout << "1. At Start" << endl;
				cout << "2. At End" << endl;
				cout << "3. At Position" << endl;
				cout << "4. At Data" << endl;
				cout << "Your Choice: ";
				cin >> LLChoice;
				switch (LLChoice)
				{
				case 1:
					DeleteAtStart();
					break;
				case 2:
					DeleteAtEnd();
					break;
				case 3:
					cout << "\nEnter Position";
					cin >> position;
					DeleteAtPos(position);
					break;
				case 4:
					cout << "Enter Data: ";
					cin >> element;
					DeleteByNumber(element);
					break;
				default:
					cout << "\n Wrong Choice" << endl;
					break;
				}
				break;
			case 3:
				cout << "\nEnter Position";
				cin >> position;
				SearchByPosition(position);
				break;
			case 4:
				cout << "Enter Data: ";
				cin >> element;
				SearchByData(element);
				break;
			case 5:
				DisplayCount();
				break;
			case 6:
				DisplayLL();
				break;
			case 7:
				quit = true;
				break;
			default:
				cout << "\nWrong Choice";
				break;
			}
		}
	}

	~LinkedList() //Destructor 
	{
	}
};
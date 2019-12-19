#include "stdafx.h"

using namespace std;

template <typename T>
class Stack
{
	T m_arrayData[10];
	int  m_top;
	int m_arrLen;
	//static const int m_capacity = 10;

	bool IsEmpty() const //Check if stack is empty and return a bool value as an answer
	{
		if (m_top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:

	Stack() //Constructor
	{
		m_top = -1;
		m_arrLen = sizeof(m_arrayData) / sizeof(m_arrayData[0]);
		for (int i = 0; i < m_arrLen; i++)
		{
			m_arrayData[i] = 0;
		}
	}

	void Push(T element) //Push element in stack
	{
		if (IsEmpty())
		{
			m_top = 0;
		}
		else if (m_top == m_arrLen - 1)
		{
			cout << "\nStack is Full" << endl;
			return;
		}
		else
		{
			m_top = m_top + 1;
		}
		m_arrayData[m_top] = element;
	}

	void Pop() //Pop element from stack
	{
		if (IsEmpty())
		{
			cout << "\nStack is Empty" << endl;
		}
		else
		{
			cout << "\nElement Popped" << endl;
			m_top = m_top - 1;
		}
	}

	void DisplayStack() const //Display Stack
	{
		if (m_top == -1)
		{
			cout << "\nStack is Empty" << endl;
		}
		else
		{
			for (int i = 0; i <= m_top; i++)
			{
				cout << m_arrayData[i] << "\t";
			}
			cout << "Front: " << m_top << endl;
		}
	}

	void StackMenu() //Stack Menu UI
	{
		T element;
		int StChoice;
		bool quit;

		quit = false;
		//system("cls");
		while (quit == false)
		{
			cout << "\nWelcome to Stack DS" << endl;
			cout << "1. Push" << endl;
			cout << "2. Pop " << endl;
			cout << "3. Display Stack" << endl;
			cout << "4. Exit" << endl;
			cout << "Your Choice: ";
			cin >> StChoice;
			//system("cls");

			switch (StChoice)
			{
			case 1:
				cout << "\nEnter element to Add:";
				cin >> element;
				Push(element);
				break;
			case 2:
				Pop();
				break;
			case 3:
				DisplayStack();
				break;
			case 4:
				quit = true;
				break;
			default:
				cout << "\nWrong Choice. Choose from the options given above";
				break;
			}
		}
	}

	~Stack() //Destructor
	{
	}
};


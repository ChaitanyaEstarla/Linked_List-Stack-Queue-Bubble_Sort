#include "stdafx.h"

using namespace std;

template <class T>
class Queue
{
	//static const int m_capacity = 10;
	T m_queueArray[10];
	int m_front, m_rear;
	int m_arrLen;

	bool IsEmpty() const //Function to check if Queue is empty
	{
		if ((m_front == -1 && m_rear == -1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsFull() const //Function to check if queue is Full
	{
		if ((m_rear + 1) % m_arrLen == m_front)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Queue() //Constructor
	{
		m_front = -1;
		m_rear = -1;
		m_arrLen = sizeof(m_queueArray) / sizeof(m_queueArray[0]);
		for (int i = 0; i < m_arrLen; i++)
		{
			m_queueArray[i] = 0;
		}
	}	

	void Enqueue(T element) //User can add element in Queue
	{
		if (IsFull())
		{
			cout << "\nQueue is Full" << endl;
		}

		else if (IsEmpty())
		{
			m_front = 0;
			m_rear = 0;
		}

		else
		{
			m_rear = (m_rear + 1) % m_arrLen;
		}
		m_queueArray[m_rear] = element;
	}

	void Dequeue() //User can delete element in Queue
	{
		if (IsEmpty())
		{
			cout << "\nQueue is already Empty" << endl;
		}
		else if (m_front == m_rear)
		{
			m_front = -1;
			m_rear = -1;
		}
		else
		{
			m_front = (m_front + 1) % m_arrLen;
		}
	}

	void DisplayQueue() const //Display Function
	{
		if (IsEmpty())
		{
			cout << "\nQueue is Empty";
			cout << "Front: " << m_front << "\t" << "Rear: " << m_rear << endl;
		}
		else
		{
			int i;
			i = m_front;
			while (i != m_rear)
			{
				cout << m_queueArray[i] << "\t";
				i = (i + 1) % m_arrLen;
			}
			cout << m_queueArray[i] << "\t";
			cout << "Front: " << m_front << "\t" << "Rear: " << m_rear << endl;
		}
	}

	void QueueMenu() //Queue Menu UI
	{
		bool quit;
		int QChoice;
		T element;

		quit = false;
		//system("cls");
		while (quit == false)
		{
			cout << "\nWelcome to Queue DS" << endl;
			cout << "1. Enqueue" << endl;
			cout << "2. Dequeue" << endl;
			cout << "3. Display Queue" << endl;
			cout << "4. Exit" << endl;
			cout << "Your Choice: ";
			cin >> QChoice;
			//system("cls");
	
			switch (QChoice)
			{
			case 1:
				cout << "\nEnter element to Add: ";
				cin >> element;
				Enqueue(element);
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				DisplayQueue();
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

	~Queue() //Destructor
	{
	}

};


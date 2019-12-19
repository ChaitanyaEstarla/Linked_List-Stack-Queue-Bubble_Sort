#include "stdafx.h"

using namespace std;

template <class T>
class  BubbleSort {

	T m_bsArray[10];
	int m_arrLen;
	//static const int (m_arrLen) = 10;

	bool IsSorted() const //Check if Array is sorted
	{
		for (int i = 0; i < (m_arrLen) - 1; i++)
		{
			if (m_bsArray[i] > m_bsArray[i + 1])
			{
				return false;
			}
		}
		return true;
	}

public:

	BubbleSort() //Constructor
	{
		m_arrLen = sizeof(m_bsArray) / sizeof(m_bsArray[0]);
		for (int i = 0; i < m_arrLen; i++)
		{
			m_bsArray[i] = 0;
		}
	}

	void InsertValues() //User will Insert Values in Array 
	{
		cout << "\nEnter Array Elements :" << endl;
		for (int i = 0; i < (m_arrLen); i++)
		{
			cout << "Array[" << i + 1 << "]: ";
			cin >> m_bsArray[i];
		}
	}

	void  Display() const //Display Array
	{
		for (int i = 0; i < (m_arrLen); i++)
		{
			cout << m_bsArray[i] << "\t";
		}
		cout << endl;
	}	

	void SortArray() //Bubble Sort Algorithm
	{
		int count = 0;
		int Check = 0;
		T temp;

		cout << "\nDo you want to display the array after each iteration ?" << endl;
		cout << "\tEnter 1 for Yes and 0 for No: ";
		cin >> Check;

		while (count < (m_arrLen) - 1)
		{
			if (IsSorted())
			{
				return;
			}
			else
			{
				for (int i = 0; i < (m_arrLen) - 1; i++)
				{
					if (m_bsArray[i] > m_bsArray[i + 1])
					{
						temp = m_bsArray[i];
						m_bsArray[i] = m_bsArray[i + 1];
						m_bsArray[i + 1] = temp;
					}
				}
			}
			if (Check == 1)
			{
				Display();
			}
			count++;
		}
	}

	void BubbleSortMenu() //BubbleSort Menu UI
	{
		bool quit;

		quit = false;
		//system("cls");
		InsertValues();
		SortArray();
		int BSChoice;
		cout << "\n1. Display Sorted Array" << endl;
		cout << "2. Exit" << endl;
		cout << "Your Choice: ";
		cin >> BSChoice;
		switch (BSChoice)
		{
		case 1:
			Display();
			break;
		case 2:
			quit = true;
			break;
		default:
			cout << "\nInvalid choice try again. Choose from the options given above";
			break;
		}
	}

	~BubbleSort() //Destructor
	{
	}
};
#include "stdafx.h"
#include "BubbleSort.h"
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

enum myDSAssignment {StackDS =1, QueueDS=2, LinkedListDS=3, BubbleSortAlgo=4, Exit=5};

int main()
{
	Stack<float> stack;
	BubbleSort<float> bubbleSort;
	Queue<float> queue;
	LinkedList<float> linkedList;

	int choice;
	bool escape;
	bool quit;

	do
	{
		//system("cls");
		quit = false;
		escape = false;
		cout << "\nWelcome to Assignment 1 !!!" << endl;
		cout << "This Assignment is on basic data structures" << endl;
		cout << "It consists : " << endl;
		cout << "1. Stack" << endl;
		cout << "2. Queue" << endl;
		cout << "3. Linked-List" << endl;
		cout << "4. Bubble Sort" << endl;
		cout << "5. Exit" << endl;
		cout << "You may choose any of the options from above" << endl;
		cout << "Your choice: ";
		cin >> choice;

		while (quit == false)
		{
			switch (choice)
			{
			case StackDS:
				stack.StackMenu();
				break;
			case QueueDS:
				queue.QueueMenu();
				break;
			case LinkedListDS:
				linkedList.LinkedListMenu();
				break;
			case BubbleSortAlgo:
				bubbleSort.BubbleSortMenu();
				break;
			case Exit:
				escape = true;
				//system("cls");
				cout << "Bye Bye" << endl;
				break;
			default:
				cout << "Please enter a valid choice. Choose from the options given above";
				break;
			}
			quit = true;
		}
	} while (escape == false);

	return 0;
}
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Array is created here
#define WIDTH1 16 // Size of the Array
#define HEIGHT1 16
#define WIDTH2 24 
#define HIEGHT2 24

typedef struct {
	int x;
	int y;
} position;

void pushAjacentPositions(position);
// Make array into variable
char maze[WIDTH1*HEIGHT1];

stack <position> dfsStack;  // stack for dfs reaversal


int main(void)
{
	cout << "Find K to open the door!\n" << endl;
	//printf("Enter a Number!\n");
	//printf("1. 16x16 Maze\n");
	//printf("2. 24x24 Maze\n");
	//printf("3. Exit\n");

	//int cont = 1;
	//int UserInput = 1;
	//while (cont == 0)
	//{
	//	cout << "Enter a number" << endl;
	//	cout << "1. 16x16 maze" << endl;
	//	cout << "2. 24x24 maze" << endl;
	//	cout << "3. Exit" << endl;
	//}
	//cin >> UserInput;
	//if (UserInput == 3)
	//	cont = 0;
	//switch (UserInput) {
	//case 1:
	//{

	//	string line;
	//	 //Open file
	//	ifstream myfile("maze3.maz");
	//	if (myfile.is_open())
	//	{
	//		int count = 0;
	//		while (getline(myfile, line))
	//		{
	//			cout << line << endl;
	//			line.copy(&maze[WIDTH1*count], WIDTH1, 0);
	//			count++;
	//		}
	//		myfile.close();
	//	}
	//	else cout << "Unable to open file";
	//}

	//case 2:
	//{
	//	string line;
	//	// Open file
	//	ifstream myfile("maze4.maz");
	//	if (myfile.is_open())
	//	{
	//		int count = 0;
	//		while (getline(myfile, line))
	//		{
	//			cout << line << endl;
	//			line.copy(&maze[WIDTH2*count], WIDTH2, 0);
	//			count++;
	//		}
	//		myfile.close();
	//	}

	//	else cout << "Unable to open file";
	//}

	//cout << "Come back soon" << endl;
	//return 0;
	//}



	// Initialize current positionh
	position current;
	current.x = 1;
	current.y = 2;
	// Initialize start position
	position startPosition;
	startPosition.x = 1;
	startPosition.y = 2;

	string line;
	//Open file
	ifstream myfile("maze3.maz");
	if (myfile.is_open())
		{
		int count = 0;
		while (getline(myfile, line))
			{
				cout << line << endl;
				line.copy(&maze[WIDTH1*count], WIDTH1, 0);
				count++;
			}
			myfile.close();
		}
	 /*reading it into an array*/
	else cout << "Unable to open file";

	cout << endl << endl << endl;

	for (int y = 0; y < HEIGHT1; y++)
	{
		for (int x = 0; x < WIDTH1; x++)
		{
			if (maze[WIDTH1*y + x] == 'S')
			{

				startPosition.x = x;
				startPosition.y = y;
			}
			cout << maze[WIDTH1*y + x];
		}


		cout << endl;
	}
	cout << "Start located at position: (" << startPosition.x << "," << startPosition.y << ") of maze" << endl;

	// Initialize stack with start position
	dfsStack.push(startPosition);

	//for (int i = 0; i < 10; i++)  // Push lots of positions onto the stack to test it
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		current.x = i;
	//		current.y = j;
	//		dfsStack.push(current);
	//	}
	//}

	// Marking the current position 
	char  mark = 'x';
	// dfs While Loop
	while (!dfsStack.empty())
	{
		// Top of the stack
		current = dfsStack.top();  // top + pop = A stack pop operation
		dfsStack.pop();
		// Mark where current position is in the maze
		maze[WIDTH1*current.y + current.x] = '.';
		//system("cls");
		// Push current position to the next position 
		pushAjacentPositions(current);

		for (int y = 0; y < HEIGHT1; y++)
		{
			for (int x = 0; x < WIDTH1; x++)
			{
				cout << maze[WIDTH1*y + x];
			}
			cout << endl;
		}

		// Output current positions on screen
		cout << "Popping (" << current.x << "," << current.y << ")" << endl;
	}



	return 0;
	}

	void pushAjacentPositions(position current)
	{
		position temp;
		char  lookUp, lookDown, lookLeft, lookRight;
		lookUp = maze[WIDTH1*(current.y - 1) + current.x];
		cout << lookUp << endl;
		lookDown = maze[WIDTH1*(current.y + 1) + current.x];
		cout << lookDown << endl;
		lookLeft = maze[WIDTH1*(current.y) + current.x - 1];
		cout << lookLeft << endl;
		lookRight = maze[WIDTH1*(current.y) + current.x + 1];
		cout << lookRight << endl;

		// Tests
		if (lookUp == ' ')
		{
			(temp.x = current.x);
			(temp.y = current.y - 1);
			dfsStack.push(temp);
		}
		if (lookDown == ' ')
		{
			(temp.x = current.x);
			(temp.y = current.y + 1);
			dfsStack.push(temp);
		}
		if (lookLeft == ' ')
		{
			(temp.x = current.x - 1);
			(temp.y = current.y);
			dfsStack.push(temp);
		}
		if (lookRight == ' ')
		{
			(temp.x = current.x + 1);
			(temp.y = current.y);
			dfsStack.push(temp);
		}

		if (lookUp == 'K')
		{
			(temp.y = current.y - 1);
			(temp.x = current.x);
			dfsStack.push(temp);
			cout << "K is found(" << current.x << "," << current.y << ")" << endl;

		}
		if (lookDown == 'K')
		{
			(temp.y = current.y + 1);
			(temp.x = current.x);
			dfsStack.push(temp);
			cout << "K is found(" << current.x << "," << current.y << ")" << endl;

		}
		if (lookLeft == 'K')
		{
			(temp.y = current.y - 1);
			(temp.x = current.x);
			dfsStack.push(temp);
			cout << "K is found(" << current.x << "," << current.y << ")" << endl;

		}
		if (lookRight == 'K')
		{
			(temp.y = current.y + 1);
			(temp.x = current.x);
			dfsStack.push(temp);
			cout << "K is found(" << current.x << "," << current.y << ")" << endl;

		}

		if (lookUp == 'D')
		{
			(temp.y = current.y - 1);
			(temp.x = current.x);
			dfsStack.push(temp);
			cout << "Door is unlocked!(" << current.x << "," << current.y << ")" << endl;

		}
		if (lookDown == 'D')
		{
			(temp.y = current.y + 1);
			(temp.x = current.x);
			dfsStack.push(temp);
			cout << "Door is unlocked!(" << current.x << "," << current.y << ")" << endl;

		}
		if (lookLeft == 'D')
		{
			(temp.y = current.y - 1);
			(temp.x = current.x);
			dfsStack.push(temp);
			cout << "Door is unlocked!(" << current.x << "," << current.y << ")" << endl;

		}
		if (lookRight == 'D')
		{
			(temp.y = current.y + 1);
			(temp.x = current.x);
			dfsStack.push(temp);
			cout << "Door is unlocked!(" << current.x << "," << current.y << ")" << endl;
		}




	}

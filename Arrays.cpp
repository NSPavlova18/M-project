#include <iostream>
using namespace std;

int mainMenu() //front end dev, main menu
{
	int x;
	cin >> x;
	return x;
}

int operationMenu() //front end dev, a menu with operations
{
	int x;
	cin >> x;
	return x;
}

void xandy(int* x, int* y, int n, int m) 
{
	bool answer = false;
	cout << "x U y = ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) { if (x[i] == y[j]) { cout << x[i] << " "; answer = true; } }
	}
	if (answer == false) { cout << "0"; }
	cout << endl;
} //outputs if a number is in both

void xplusy(int* x, int* y, int n, int m)
{
	bool sameNumber = false;
	cout << "x ^ y = ";
	for (int i = 0; i < n; i++) { cout << x[i] << " "; }
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) { if (y[i] == x[j]) { sameNumber = true; } }
		if (sameNumber == false) { cout << y[i] << " "; }
		sameNumber = false;
	}
	cout << endl;
} //outputs if a number is in at least one of them

void xminusy(int* x, int* y, int n, int m)
{
	bool sameNumber = false;
	cout << "x / y = ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) { if (x[i] == y[j]) { sameNumber = true; } }
		if (sameNumber == false) { cout << x[i] << " "; }
		sameNumber = false;
	}
	cout << endl;
}

void yminusx(int* x, int* y, int n, int m)
{
	bool sameNumber = false;
	cout << "y / x = ";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) { if (x[j] == y[i]) { sameNumber = true; } }
		if (sameNumber == false) { cout << y[i] << " "; }
		sameNumber = false;
	}
	cout << endl;
}

void sortMenu(int *x, int n) //front end dev, menu stuff again
{
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 0: //sort from smallest to biggest
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < j - 1; j++) { if (x[i] > x[i + 1]) { swap(x[i], x[i + 1]); } }
		}
		break;
	}
	case 1: //sort from biggest to smallest
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < j - 1; j++) { if (x[i] < x[i + 1]) { swap(x[i], x[i + 1]); } }
		}
		break;
	}
	default: cout << "Invalid input" << endl; break; //outputs on invalid input
	}
}

int main()
{
	int choice = 0, n = 0, m = 0, sameElement = 0, x[10], y[10]; char choiceC;
	while (choice != 9)
	{
		choice = mainMenu();
		switch (choice)
		{
		case 0: //declare arrays
		{
			cout << "Change array x or y? (Enter '8' to go back): ";
			cin >> choiceC;
			switch (choiceC)
			{
			case 'x': 
			{
				cout << "Choose array size (not bigger than 10) = ";
				cin >> n;
				if (n > 10) { cout << "Value is too large"; }
				else
				{
					cout << "Choose array elements = ";
					for (int i = 0; i < n; i++)
					{
						cin >> x[i];
						for (int j = 0; j <= i; j++) { if (x[i] == x[j]) { sameElement++; } }
						if (sameElement > 1) { cout << "This element already exists, write another one = "; i--; }
						sameElement = 0;
					}
				}
				break;
			}
			case 'y':
			{
				cout << "Choose array size (not bigger than 10) = ";
				cin >> m;
				if (m > 10) { cout << "Value is too large"; }
				else
				{
					cout << "Choose array elements = ";
					for (int i = 0; i < m; i++)
					{
						cin >> y[i];
						for (int j = 0; j <= i; j++) { if (y[i] == y[j]) { sameElement++; } }
						if (sameElement > 1) { cout << "This element already exists, write another one = "; i--; }
						sameElement = 0;
					}
				}
			}
			case '8': break;
			default: cout << "Invalid input" << endl; break;
			}
			break;
		}
		case 1: //operations with arrays
		{
			choice = operationMenu();
			switch (choice)
			{
			case 0: xandy(x, y, n, m); break; //outputs if a number is in both
			case 1: xplusy(x, y, n, m); break; //outputs if a number is in at least one of them
			case 2: xminusy(x, y, n, m); break; //outputs if a number is not in y
			case 3: yminusx(x, y, n, m); break; //outputs if a number is not in x
			case 8: break; //goes back to main menu
			default: cout << "Invalid input" << endl; break; //outputs for invalid input
			}
			break;
		}
		case 2: //sorts arrays (idk why it doesn't work bruh)
		{
			cout << "Sort array x or y? (Enter '8' to go back): ";
			cin >> choiceC;
			switch (choiceC)
			{
			case 'x': sortMenu(x, n); cout << "Array x sorted!" << endl; break;
			case 'y': sortMenu(y, m); cout << "Array y sorted!" << endl; break;
			case '8': break;
			default: cout << "Invalid input" << endl; break;
			}
			break;
		}
		case 3: //outputs arrays
		{
			cout << "Output array x or y? (Enter '8' to go back): ";
			cin >> choiceC;
			switch (choiceC)
			{
			case 'x': cout << "x = "; for (int i = 0; i < n; i++) { cout << x[i] << " "; } cout << endl; break;
			case 'y': cout << "y = "; for (int i = 0; i < m; i++) { cout << y[i] << " "; } cout << endl; break;
			case '8': break;
			default: cout << "Invalid input" << endl; break;
			}
		}
		case 4: //outputs the team members (WIP), front end dev here
		case 9: break; //stops the program
		default: cout << "Invalid input" << endl; //outputs for invalid input
		}
	}
}
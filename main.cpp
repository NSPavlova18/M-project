// ConsoleApplication71.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
using namespace std;


int mainMenu(int choice) //front end dev, main menu
{
	int x;
	cout << endl<<"List: \n 0. Declare arrays.\n 1. Operations with arrays.\n 2. Sort the arrays.\n 3. Output the arrays.\n 4. About us.\n 9. Quit \n\n";
	cin >> x;
	while(cin.fail()){
        cout << "You haven't entered a number. Please enter a number: ";
        cin.clear();
        cin.ignore(1000,'\n');
        cin >> x;
        cout << endl;
	}
	return x;

}

int operationMenu(int choice) //front end dev, a menu with operations
{
	int x;
	cout << "\n 0. Outputs if a number is in both arrays.\n 1. Outputs if a number is at least in one of the arrays.\n 2. Outputs all elements of array x that are not in array y.\n 3. Outputs all elements of array y that are not in array x.\n 8. Return to main menu.\n\n";
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
}//

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

void sortMenu(int* x, int n) //front end dev, menu stuff again
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

	int choice = 0, ElementsInX = 0, ElementsInY = 0, sameElement = 0, x[10], y[10]; char choiceC;
	cout << "--------------WELCOME----------------" << endl << endl;


		while (choice != 9)
		{
			choice = mainMenu(choice);
            switch (choice){
			case 0: //declare arrays
			{
				cout << "Change array x or y? (Enter '8' to go back): " << endl;
				cin >> choiceC;
				switch (choiceC)
				{
				case 'x':
				{
					cout << "Choose array size (not bigger than 10) = " << endl;
					cin >> ElementsInX;
					if (ElementsInX < 0 or ElementsInX > 10) { cout << "Invalid value" << endl; }
					else
					{
						cout << "Choose array elements = ";
						for (int i = 0; i < ElementsInX; i++)
						{
							cin >> x[i];
							for (int j = 0; j <= i; j++) { if (x[i] == x[j]) { sameElement++; } }
							if (sameElement > 1) { cout << "This element already exists, write another one = " << endl; i--; }
							sameElement = 0;
						}
					}
					break;
				}
				case 'y':
				{
					cout << "Choose array size (not bigger than 10) = " << endl;
					cin >> ElementsInY;
					if (ElementsInY < 0 or ElementsInY > 10) { cout << "Invalid value" << endl; }
					else
					{
						cout << "Choose array elements = " << endl;;
						for (int i = 0; i < ElementsInY; i++)
						{
							cin >> y[i];
							for (int j = 0; j <= i; j++) { if (y[i] == y[j]) { sameElement++; } }
							if (sameElement > 1) { cout << "This element already exists, write another one = "<<endl; i--; }
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

				if (ElementsInX <= 0 or ElementsInY <= 0 or ElementsInX > 10 or ElementsInY > 10){
				     cout << "Both arrays need to have elements" << endl;
				     break;
                }

				else{
					choice = operationMenu(choice);

					switch (choice){
                        case 0: xandy(x, y, ElementsInX, ElementsInY); break; //outputs if a number is in both
                        case 1: xplusy(x, y, ElementsInX, ElementsInY); break; //outputs if a number is in at least one of them
                        case 2: xminusy(x, y, ElementsInX, ElementsInY); break; //outputs if a number is not in y
                        case 3: yminusx(x, y, ElementsInX, ElementsInY); break; //outputs if a number is not in x
                        case 8: break; //goes back to main menu
                        default: cout << "Invalid input" << endl; break; //outputs for invalid input
					}
                break;
				}

			}
			case 2: //sorts arrays (idk why it doesn't work bruh)
			{
			    if (ElementsInX <= 0 or ElementsInY <= 0 or ElementsInX > 10 or ElementsInY > 10){
				     cout << "The arrays need to have elements" << endl;
				     break;
                }
                else{

                    cout << "Sort array x or y? (Enter '8' to go back): "<<endl;
                    cin >> choiceC;
                    switch (choiceC){
                        case 'x':
                        {

                            if(ElementsInX <= 0 or ElementsInX > 10){
                                cout << "Array x has no elements" << endl;
                            }

                            else{
                                sortMenu(x, ElementsInX);
                                cout << "Array x sorted!" << endl;
                            }

                        break;
                        }
                        case 'y':
                        {
                            if(ElementsInY <= 0 or ElementsInY > 10){
                                cout << "Array y has no elements" << endl;
                            }

                            else{
                                sortMenu(y, ElementsInY);
                                cout << "Array y sorted!" << endl;
                            }

                            break;
                        }

                        case '8': break;

                        default: cout << "Invalid input" << endl; break;
                    }
                    break;
                }
			}
			case 3: //outputs arrays
			{
                if (ElementsInX <= 0 or ElementsInY <= 0 or ElementsInX > 10 or ElementsInY > 10){
				     cout << "The arrays need to have elements" << endl;
				     break;
                }

				else{
                    cout << "Output array x or y? (Enter '8' to go back): "<<endl;
                    cin >> choiceC;

                    switch (choiceC){

                        case 'x':
                            cout << "x = ";
                            for(int i = 0; i < ElementsInX; i++){
                                cout << x[i] << " ";
                            }
                            cout << endl; break;

                        case 'y':
                            cout << "y = ";
                            for(int i = 0; i < ElementsInY; i++){
                                cout << y[i] << " ";
                            }
                            cout << endl; break;

                        case '8': break;

                        default: cout << "Invalid input" << endl;
                        break;
                    }
				break;
				}
			}
			case 4: //outputs the team members (WIP), front end dev here

            case 5: //outputs what every part/number does(information about every function)

			case 9: break; //stops the program
			default: cout << "Invalid input" << endl; //outputs for invalid input
			}
        if(ElementsInX != 0){
            ElementsInX = sizeof(x) / sizeof(x[0]);
        }
        if(ElementsInY != 0){
            ElementsInY = sizeof(x) / sizeof(x[0]);
        }
    }
}

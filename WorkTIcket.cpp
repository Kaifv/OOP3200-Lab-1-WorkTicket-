/*
* This is the main.cpp file for the WorkTicket vs file for lab 1. In this file we will add the functionality for the basic work ticket environment, which will store the
* ticket number, date, id, name of the customer and the problem caused to them.
*
* Developer Name: Kaifkhan Vakil
* Student Id: 100772820.
* Date: 18th September, 2020.
*
*/

// Including all the libraries that will be helpful in the code. 
#include <iostream>
#include <iomanip>			
#include <sstream> 			
#include <cmath>			
#include <limits>			
#include <stdexcept>		
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()

using namespace std;
// class declaration section 
class WorkTicket
{
	// Private attributes are added to the class along with their proper datatypes.
private:
	int myticketNumber;
	int myticketDay;
	int myticketMonth;
	int myticketYear;
	string myclientID;
	string myissueDescrip;

	// Public section of the class which will be available outside of the class also. 
public:
	//Constructor - Parameterized constructor is the default value for the data entry of the attributes in the file whenever the input is not entered or
	//proper. 
	WorkTicket(int myticketNumber = 0, int myticketDay = 1, int myticketMonth = 1, int myticketYear = 2000, string myclientID = "", string myissueDescrip = "");

	// Accesors(getters) - This are the getters function which will be useful in displaying the values of the attributes in the console window. Getter function
	//for each of the membr of the attribute is added down below.
	int GetNumber();
	int GetDay();
	int GetMonth();
	int GetYear();
	string GetID();
	string GetDescription();
	string ShowWorkTicket() const;

	// Mutators(setters) - These the setters function which will manipulate the input in the attributes. Setter function for each of the attribute is added.:
	void SetNumber(int ticketNumber);
	void SetDay(int ticketDay);
	void SetMonth(int ticketMonth);
	void SetYear(int ticketYear);
	void SetID(string clientID);
	void SetDescription(string issueDescrip);
	bool SetWorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, string clientID, string issueDescrip);


};// end of class WorkTicket.

// main function
int main()
{
	// Declaration section for the main function.
	WorkTicket arr[3]; // Array of objects in the class to store the objects.
	int inputNumber; // Input for ticket number. 
	int inputday, inputMonth, inputYear; //input for date.
	string inputID; // input client ID.
	string inputDescrip; //input for description.
	int i = 0; // initialization of integer for while loop.

	// Noting the user to enter the information as asked. 
	std::cout << "Enter the information as prompted: " << endl;

	// Starting of the while loop.
	while (i < 3)
	{
		// Try and catch method for the input.	
		try
		{
			// Prompting to enter the ticket number, with validation through consoleinput class. 
			std::cout << "Enter the ticket number: ";
			inputNumber = ConsoleInput::ReadInteger(1);
			arr[i].SetNumber(inputNumber);

			std::cout << "Enter the Client ID: ";
			cin >> inputID;
			if (inputID.length() >= 1)
			{
				arr[i].SetID(inputID);
			}
			else
			{
				throw invalid_argument("Error! Please enter the ID in the alphanumeric format");
			}

			std::cout << "Enter the date(dd/mm/yyyy): ";
			cin >> inputday >> inputMonth >> inputYear;
			arr[i].SetDay(inputday);
			arr[i].SetMonth(inputMonth);
			arr[i].SetYear(inputYear);

			std::cout << "Write the brief description of the problem: ";
			cin >> inputDescrip;
			arr[i].SetDescription(inputDescrip);
			cout << endl;
			i++;
		}
		catch (exception& ex)
		{
			cerr << ex.what();
			i--;
		}

	}
	std::cout << endl << endl;
	std::cout << "You entered the noted below information, please check." << endl;
	for (int y = 0; y < 3; y++)
	{
		std::cout << "Your ticket number: " << arr[y].GetNumber() << endl;
		std::cout << "Your entered client ID: " << arr[y].GetID() << endl;
		std::cout << "Your entered date: " << arr[y].GetDay() << "/" << arr[i].GetMonth() << "/" << arr[i].GetYear() << endl;
		std::cout << "Your entered description: " << arr[y].GetDescription() << endl;

		std::cout << endl;
	}
}

// class definition section

WorkTicket::WorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, string clientID,
	string issueDescrip)
{
	SetWorkTicket(ticketNumber, ticketDay, ticketMonth, ticketYear, clientID, issueDescrip);
}

bool WorkTicket::SetWorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, string clientID, string issueDescrip)
{
	SetNumber(ticketNumber);
	SetDay(ticketDay);
	SetMonth(ticketMonth);
	SetYear(ticketYear);
	SetID(clientID);
	SetDescription(issueDescrip);

	return true;
}

void WorkTicket::SetNumber(int ticketNumber)
{
	if (ticketNumber > 0)
	{
		myticketNumber = ticketNumber;
	}
	/*else
	{
		throw invalid_argument("Error! Please enter positive whole number");
	}*/
}

void WorkTicket::SetDay(int ticketDay)
{
	if (ticketDay >= 1 && ticketDay <= 31)
	{
		myticketDay = ticketDay;
	}
	else
	{
		throw invalid_argument("Error! Please enter the day between 1 to 31");
	}
}

void WorkTicket::SetMonth(int ticketMonth)
{
	if (ticketMonth >= 1 && ticketMonth <= 12)
	{
		myticketMonth = ticketMonth;
	}
	else
	{
		throw invalid_argument("Error! Please enter the month between 1 to 12");
	}
}

void WorkTicket::SetYear(int ticketYear)
{
	if (ticketYear >= 2000 && ticketYear <= 2099)
	{
		myticketYear = ticketYear;
	}
	else
	{
		throw invalid_argument("Error! Please enter the Year between 2000 to 2099");
	}
}

void WorkTicket::SetID(string clientId)
{
	/*if (clientId.length() >= 1)
	{*/
	myclientID = clientId;
	//}

}

void WorkTicket::SetDescription(string issueDescrip)
{
	if (issueDescrip.length() >= 1)
	{
		myissueDescrip = issueDescrip;
	}
	/*else
	{
		throw invalid_argument("Error! Please enter the description, do not keep it empty");
	}*/
}

int WorkTicket::GetNumber()
{
	return myticketNumber;
}

int WorkTicket::GetDay()
{
	return myticketDay;

}

int WorkTicket::GetMonth()
{
	return myticketMonth;
}

int WorkTicket::GetYear()
{
	return myticketYear;
}

string WorkTicket::GetID()
{
	return myclientID;
}

string WorkTicket::GetDescription()
{
	return myissueDescrip;
}

//string WorkTicket::ShowWorkTicket() const
//{
//   
//}
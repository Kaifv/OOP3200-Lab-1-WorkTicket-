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
#include <utility>
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
	//for each of the member of the attribute is added down below.
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
	void SetDescription(const string& issueDescrip);
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

			// Prompting the user to enter the client ID.
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

			// Prompting the user to enter the date of their information. 
			std::cout << "Enter the date(dd/mm/yyyy): ";
			cin >> inputday >> inputMonth >> inputYear;
			arr[i].SetDay(inputday);
			arr[i].SetMonth(inputMonth);
			arr[i].SetYear(inputYear);

			// Prompting the user to write the description of their problem. 
			std::cout << "Write the brief description of the problem: ";
			cin >> inputDescrip;
			arr[i].SetDescription(inputDescrip);
			cout << endl;
			i++;
		}
		// We will catch the exception if any of the input values stands out the validation parameters.
		catch (exception& ex)
		{
			cerr << ex.what();
			i--;
		}

	}
	std::cout << endl << endl;

	//Now we will show the entered data by the user using a for loop.
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

// Defining constructor with all the necessary parameters. 
WorkTicket::WorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, string clientID,
	string issueDescrip)
{
	SetWorkTicket(ticketNumber, ticketDay, ticketMonth, ticketYear, std::move(clientID), std::move(issueDescrip));
}

// Defining SetWorkTicket function with its parameters and if all are valid then return true.
bool WorkTicket::SetWorkTicket(int ticketNumber, int ticketDay, int ticketMonth, int ticketYear, string clientID, string issueDescrip)
{
	SetNumber(ticketNumber);
	SetDay(ticketDay);
	SetMonth(ticketMonth);
	SetYear(ticketYear);
	SetID(std::move(clientID));
	SetDescription(issueDescrip);

	return true;
}

// Defining setter for ticket number which will validate the user input if it is in outside range.
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

// Defining setter for day attribute in date, so that it is always between 1 and 31.
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

// Defining setter for month attribute in date, so that it is always between 1 and 12.
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

// Defining setter for year attribute in date, so that it is always between 2000 and 2099.
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

// Defining setter for client ID, so that it's length is always 1 or more.
void WorkTicket::SetID(string clientId)
{
	/*if (clientId.length() >= 1)
	{*/
	myclientID = std::move(clientId);
	//}

}

// Defining setter for description, so that it's length is always 1 or more.
void WorkTicket::SetDescription(const string& issueDescrip)
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

// Defining getter for ticket number.
int WorkTicket::GetNumber()
{
	return myticketNumber;
}

// Defining getter for ticket day. 
int WorkTicket::GetDay()
{
	return myticketDay;

}

// Defining getter for ticket month.
int WorkTicket::GetMonth()
{
	return myticketMonth;
}

// Defining getter for ticket year. 
int WorkTicket::GetYear()
{
	return myticketYear;
}

// Defining getter for client ID. 
string WorkTicket::GetID()
{
	return myclientID;
}

// Defining getter for problem description. 
string WorkTicket::GetDescription()
{
	return myissueDescrip;
}

// Defining getter to show the data in the proper format. 
//string WorkTicket::ShowWorkTicket() const
//{
//   
//}
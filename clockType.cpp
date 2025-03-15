#include<iostream>
using namespace std;

class clockType
{
	int hr;
	int min;
	int sec;
public:

	clockType(int hour, int minute, int second);
	//Parametrized constructor to set time.
	//Constructor assigns hour value to hr, minute to min and second to sec.
	//Constructor also checks for invalid values. If any value is invalid then the function will assign 0 to each variable.

	clockType();
	//Default constructor to set time.
	//Constructor will assign 0 to hr, min & sec.
	//Time is set to 00:00:00

	void setTime(int hour, int minute, int second);
	//Function to set time.
	//Function assigns hour value to hr, minute to min and second to sec.
	//Function also checks for invalid values. If any value is invalid then the function will assign 0 to each variable.

	void getTime(int& hour, int& minute, int& second) const;
	//Function to get time.
	//Function will assign hr, min & sec to passed parametres.

	void printTime() const;
	//Function to print time.
	//Time will be printed in hh:mm:ss format.

	void incrementSeconds();
	//Function to increment second by 1.
	//If the time is 23:59:59, time will reset to 00:00:00.

	void incrementMinutes();
	//Function to increment minute by 1.
	//If the time is 23:59:34, time will reset to 00:00:34.

	void incrementHours();
	//Function to increment hour by 1.
	//If the time is 23:09:59, time will reset to 00:09:59.

	bool equalTime(const clockType& otherClock) const;
	//Function to check if 2 times are equal.
	//If 2 times are equal the function will return 1 otherwise 0.

};

clockType::clockType(int hour, int minute, int second)
{
	if (hour > 0 && hour < 24)
		hr = hour;
	else
		hr = 0;

	if (minute > 0 && minute < 60)
		min = minute;
	else
		min = 0;

	if (second > 0 && second < 60)
		sec = second;
	else
		sec = 0;
}

clockType::clockType()
{
	hr = 0;
	min = 0;
	sec = 0;
}

void clockType::setTime(int hour, int minute, int second)
{
	if (hour > 0 && hour < 24)
		hr = hour;
	else
		hr = 0;

	if (minute > 0 && minute < 60)
		min = minute;
	else
		min = 0;

	if (second > 0 && second < 60)
		sec = second;
	else
		sec = 0;
}

void clockType::getTime(int& hour, int& minute, int& second) const
{
	hour = hr;
	minute = min;
	second = sec;
}

void clockType::printTime() const
{
	if(hr<10)
		cout << '0';
	cout << hr << ':';

	if (min < 10)
		cout << '0';
	cout << min << ':';

	if (sec < 10)
		cout << '0';
	cout << sec << endl << endl;
}

void clockType::incrementSeconds()
{
	sec++;
	if (sec > 59)
	{
		sec = 0;
		incrementMinutes();
	}
}

void clockType::incrementMinutes()
{
	min++;
	if (min > 59)
	{
		min = 0;
		incrementHours();
	}
}

void clockType::incrementHours()
{
	hr++;
	if (hr > 23)
		hr = 0;
}

bool clockType::equalTime(const clockType& otherClock) const
{
	return(hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

void main()
{
	clockType clock1(21, 8, 0);//parametrized constructor will be called
	clockType clock2;//default constructor will be called

	cout << "clock1:" << endl;
	clock1.printTime();
	cout << "clock2:" << endl;
	clock2.printTime();

	clock2.setTime(19, 31, 59);
	cout << "clock2 after using setTime function:" << endl;
	clock2.printTime();

	int h, m, s;
	clock2.getTime(h, m, s);
	cout << "Using getTime function on clock2:" << endl;
	cout << h << ':' << m << ':' << s << endl << endl;

	clock2.incrementSeconds();
	cout << "clock2 after using incrementSeconds function:" << endl;
	clock2.printTime();

	clock1.setTime(23, 59, 7);
	cout << "clock1 after using setTime function:" << endl;
	clock1.printTime();

	clock1.incrementMinutes();
	cout << "clock1 after using incrementMinutes function:" << endl;
	clock1.printTime();

	clock1.incrementHours();
	cout << "clock1 after using incrementHours function:" << endl;
	clock1.printTime();

	cout << "Using equalTime function:" << endl;
	(clock1.equalTime(clock2) == 1) ? cout << "Equal" << endl << endl : cout << "Not Equal" << endl << endl;

	cout << "Using equalTime function after changing values:" << endl;
	clock1 = clock2;
	(clock1.equalTime(clock2) == 1) ? cout << "Equal" << endl << endl : cout << "Not Equal" << endl << endl;
}

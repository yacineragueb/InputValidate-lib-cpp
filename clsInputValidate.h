#pragma once
#include <iostream>
#include <string>
#include "../date/clsDate.h" // You can get this lib from https://github.com/yacineragueb/Date-lib-cpp

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Number, short From, short To) {
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(int Number, int From, int To) {
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(float Number, float From, float To) {
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(double Number, double From, double To) {
		return Number >= From && Number <= To;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again: ") {
		short Number;

		// You can use cin.fail()
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}

		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage) {
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again: ") {
		int Number;

		// You can use cin.fail()
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage) {
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again: ") {
		float Number;

		// You can use cin.fail()
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}

		return Number;
	}

	static float ReadFloatNumberBetween(float From, float To, string ErrorMessage) {
		float Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again: ") {
		double Number;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
			cin >> Number;
		}

		return Number;
	}

	static int ReadDblNumberBetween(double From, double To, string ErrorMessage) {
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static bool IsValideDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

	static string ReadString() {
		string S1 = "";

		// Usage of ws: extract all the whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};


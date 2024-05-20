#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
#include <conio.h>
class clsLoginScreen {
private:

	static  bool _Login() {
		bool LoginFailed = false;
		short FailedLoginCount = 0;
		std::string Username, Password;

		do
		{
			system("cls");
			std::cout << std::setw(40) << std::left << "" << "---------------------------------\n";
			std::cout << std::setw(37) << std::left << "" << "\t\t   Login Screen\n";
			std::cout << std::setw(40) << std::left << "" << "---------------------------------\n";

			if (LoginFailed)
			{
				FailedLoginCount++;
				std::cout << std::setw(40) << std::left << "" << "Invalid Username or Password!\n\n";
				std::cout << std::setw(40) << std::left << "" << "You have " << (3 - FailedLoginCount)
					<< " attempt(s) remaining to login.\n\n";
			}

			if (FailedLoginCount == 3)
			{
				system("cls");
				std::cout << "\n\n\n\n\n\n\n\n";
				std::cout << std::setw(40) << std::left << "" << "You are locked out after 3 failed login attempts.\n\n";
				return false;
			}

			std::cout << std::setw(40) << std::left << "" << "Enter Username: ";
			std::cin >> Username;

			std::cout << std::setw(40) << std::left << "" << "Enter Password: ";
			Password = GetPasswordFromUser(); // Get password securely

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();
		} while (LoginFailed);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
	}

public:
	static bool ShowLoginScreen() {
		system("cls");
		return _Login();
	}
	// Function to get password securely
	static std::string GetPasswordFromUser() {
		const char BACKSPACE = 8;
		const char ENTER = 13;
		std::string password;
		char ch = 0;

		while ((ch = _getch()) != ENTER) {
			if (ch == BACKSPACE) {
				if (password.length() != 0) {
					std::cout << "\b \b";
					password.resize(password.length() - 1);
				}
			}
			else {
				password += ch;
				std::cout << '*';
			}
		}
		std::cout << std::endl;
		return password;
	}

};

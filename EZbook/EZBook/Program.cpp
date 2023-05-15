
#include "LoginForm.h"
#include "MainForm.h"
#include "RegisterForm.h"
#include "Launch.h"
#include "EditName.h"
#include "EditEmail.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	User^ user = nullptr;
	while (true) {
		EZBook::Launch launch;
		launch.ShowDialog();

		if (launch.switchToReservation) {
			//show the register form
			EZBook::RegisterForm registerForm;
			registerForm.ShowDialog();

			if (registerForm.switchToLogin) {
				continue;
			}
			else {
				user = registerForm.user;
				break;
			}
		}

		else if (launch.switchToLogin) {
			//show the register form
			EZBook::LoginForm loginForm;
			loginForm.ShowDialog();

			if (loginForm.switchToReservation) {
				continue;
			}
			else {
				user = loginForm.user;
				break;
			}
		}

		else {
			user = launch.user;
			break;
		}
	}

	if (user != nullptr) {
		EZBook::MainForm mainForm(user);
		Application::Run(% mainForm);
		if (mainForm.switchToEditName) {
			//show the edit name
			EZBook::EditName editName;
			editName.ShowDialog();
			if (editName.switchToMain) {
				//show the edit name
				Application::Run(% mainForm);

				/*
				if (registerForm.switchToLogin) {
					continue;
				}
				else {
					user = registerForm.user;
					break;
				}
				*/
			}
		if (mainForm.switchToEditEmail) {
				//show the edit name
			EZBook::EditEmail editEmail;
			editEmail.ShowDialog();
			if (editEmail.switchToMain) {
				//show the edit name
				mainForm.ShowDialog();

					/*
					if (registerForm.switchToLogin) {
						continue;
					}
					else {
						user = registerForm.user;
						break;
					}
					*/
				}

			}
		else {
			MessageBox::Show("Authentication Canceled",
				"Program.cpp", MessageBoxButtons::OK);
			}
		}
	}
}


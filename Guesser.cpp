// Written by Treebug842
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <cstring>

int mode;
int diff;
int bet;
int number;
int balance = 9999;
int final_guess;
int multiplier;
int ending = 0;

std::string modeOption;
std::string betOption;
std::string againChoice;
std::string guess;

long double time_in_milis() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
    std::chrono::system_clock::now().time_since_epoch()
  ).count();
}

int generate_random(int min, int max) {
	std::mt19937 mt_rand(time_in_milis());
	std::uniform_int_distribution<int> distr(min, max);
	return distr(mt_rand);
}

void print_heading() {
	system("cls");
	std::cout << "Enter '\033[31mx\033[0m' to exit\n";
	std::cout << "\033[33m ================================================================================\033[33m\033[0m" << std::endl;
	std::cout << "\033[33m|\033[0m   _   _                 _                  ____                                \033[33m|\033[0m" << std::endl;
	std::cout << "\033[33m|\033[0m  | \\ | |_   _ _ __ ___ | |__   ___ _ __   / ___|_   _  ___  ___ ___  ___ _ __  \033[33m|\033[0m" << std::endl;
	std::cout << "\033[33m|\033[0m  |  \\| | | | | '_ ` _ \\| '_ \\ / _ \\ '__| | |  _| | | |/ _ \\/ __/ __|/ _ \\ __|  \033[33m|\033[0m" << std::endl;
	std::cout << "\033[33m|\033[0m  | |\\  | |_| | | | | | | |_) |  __/ |    | |_| | |_| |  __/\\__ \\__ \\  __/ |    \033[33m|\033[0m" << std::endl;
	std::cout << "\033[33m|\033[0m  |_| \\_|\\__,_|_| |_| |_|_.__/ \\___|_|     \\____|\\__,_|\\___||___/___/\\___|_|    \033[33m|\033[0m" << std::endl;
	std::cout << "\033[33m|\033[0m                                                                                \033[33m|\033[0m" << std::endl;
	std::cout << "\033[33m ================================================================================\033[0m" << std::endl << std::endl;
	std::cout << "\033[1mBalance: " << balance << "\033[0m\n\n";
}

void check_ending() {
	if (balance >= 10000 && ending == 0) {
		ending = 1;
		system("cls");
		std::cout << "Secret Ending\n";
		std::cout << "                ,---------------------------,\n";
		std::cout << "                |  /---------------------\\  |\n";
		std::cout << "                | |                       | |\n";
		std::cout << "                | |     Thank you for     | |\n";
		std::cout << "                | |        playing        | |\n";
		std::cout << "                | |     \033[33mNumber Guesser\033[0m    | |\n";
		std::cout << "                | |                       | |\n";
		std::cout << "                |  \\_____________________/  |\n";
		std::cout << "                |___________________________|\n";
		std::cout << "              ,---\\_____     []     _______/------,\n";
		std::cout << "            /         /______________\\           /|\n";
		std::cout << "          /___________________________________ /  | ___\n";
		std::cout << "          |                                   |   |    )\n";
		std::cout << "          |  _ _ _                 [-------]  |   |   (\n";
		std::cout << "          |  o o o                 [-------]  |  /    _)_\n";
		std::cout << "          |__________________________________ |/     /  /\n";
		std::cout << "      /-------------------------------------/|      ( )/\n";
		std::cout << "    /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n";
		std::cout << "  /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n";
		std::cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		std::cout << "     \033[32mCongratulations! You have hit 10,000!\033[0m \n\n\n";
		std::cout << "Press ENTER to continue...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void inputError() {
	std::cout << "\n\033[31mINVALID INPUT!\033[0m\n\n";
	std::cout << "Press ENTER to continue...";
	fgetc(stdin);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void checkBalance() {
	if (balance <= 0) {
		print_heading();
		std::cout << "--==<< Oh No, Your Balance has Hit Zero >>==--\n\n";
		std::cout << "Play again? (y/n): ";
		std::cin >> againChoice;
		if (strcmp(againChoice.c_str(), "y") == 0) {
			balance = 100;
			ending = 0;
		}
		else if (strcmp(againChoice.c_str(), "n") == 0) {
			exit(0);
		}
		else if (strcmp(againChoice.c_str(), "x") == 0) {
			exit(0);
		}
		else {
			inputError();
			checkBalance();
		}
	}
}

int get_mode() {
	print_heading();
	std::cout << "Difficulties: \n 1) 1 to 3  [x2 multiplier]\n 2) 1 to 10 [x15 multiplier]\n 3) 1 to 50 [x300 multiplier]\n\n";
	std::cout << "\033[1mChoose Difficulty: \033[0m";
	std::cin >> modeOption;
	if (strcmp(modeOption.c_str(), "1") == 0 || strcmp(modeOption.c_str(), "2") == 0 || strcmp(modeOption.c_str(), "3") == 0 || strcmp(modeOption.c_str(), "x") == 0) {
		if (strcmp(modeOption.c_str(), "x") == 0) {
			exit(0);
		}
		return std::stoi(modeOption);
	}
	else {
		inputError();
		get_mode();
	}
}

int get_bet() {
	print_heading();
	std::cout << "\033[1mEnter Bet Amount:\033[0m ";
	std::cin >> betOption;
	if (strcmp(betOption.c_str(), "x") == 0) {
		exit(0);
	}
	try {
		std::stoi(betOption);
	}
	catch (...) {
		inputError();
		get_bet();
	}
	if (std::stoi(betOption) > balance || std::stoi(betOption) < 1) {
		inputError();
		get_bet();
	}
	else {
		return std::stoi(betOption);
	}
}

int get_guess() {
	print_heading();
	std::cout << "Your number is between 1 - " << diff;
	std::cout << "\n\n\033[1mEnter your guess:\033[0m ";
	std::cin >> guess;
	if (strcmp(guess.c_str(), "x") == 0) {
		exit(0);
	}
	try {
		std::stoi(guess);
	}
	catch (...) {
		inputError();
		get_guess();
	}
	if (std::stoi(guess) < 1 || std::stoi(guess) > diff) {
		inputError();
		get_guess();
	}
	return std::stoi(guess);
}

void play() {
	switch(get_mode()) {
		case 1: diff = 3; break;
		case 2: diff = 10; break;
		case 3: diff = 50; break;
	}
	switch(diff) {
		case 3: multiplier = 2; break;
		case 10: multiplier = 15; break;
		case 50: multiplier = 300; break;
	}
	std::cout << diff;
	bet = get_bet();
	number = generate_random(1, diff);
	final_guess = get_guess();
	
	if (final_guess == number) {
		balance = balance + (bet * multiplier);
		print_heading();
		std::cout << "Your number is:\n\033[96m--==<<\033[33m " << number << " \033[96m>>==--\033[0m\n\n";
		std::cout << "\033[32mCORRECT!\033[0m\n\n";
		std::cout << "Press ENTER to continue...";
		fgetc(stdin);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		checkBalance();
		check_ending();
		play();
	}
	else {
		balance = balance - bet;
		print_heading();
		std::cout << "Your number is:\n\033[96m--==<<\033[33m " << number << " \033[96m>>==--\033[0m\n\n";
		std::cout << "\033[31mWRONG!\033[0m\n\n";
		std::cout << "Press ENTER to continue...";
		fgetc(stdin);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		checkBalance();
		check_ending();
		play();
	}
}

int main() {
	play();
	system("pause");
	return 0;
}

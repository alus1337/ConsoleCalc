#include <iostream>
#include <string>
#include <sstream>

void printWelcome()
{
	std::cout << "Welcome to ConsoleCalc! - type 'help' for assistance\n";
	std::cout << "> ";
}

std::string getUserInput()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

void clearConsole()
{
	std::system("cls");
}

bool isValidExpression()
{
	return false;
}

int expressionResult(int left_operand, char charCharacter, int right_operand)
{
	switch (charCharacter) {
	case '+':
		return left_operand + right_operand;
	case '-':
		return left_operand - right_operand;

	case '*':
		return left_operand * right_operand;
	case '/':
		if (right_operand != 0)
			return left_operand / right_operand;
		else
		{
			std::cout << "Error: Division by zero is not allowed.\n";
			return 0;
		}
	}
}

int main()
{
    while (true)
	{
		clearConsole();
		printWelcome();

		std::string input;
		input = getUserInput();

		// check if any input was provided
		if (input.size() == 0)
		{
			continue;
		}

		if (input == "help" || input == "Help")
		{
			clearConsole();
			std::cout << "Using ConsoleCalc is simple just create a 3 input expression [\"operand\" + \"operator\" + \"operand\"]\n";
			std::cout << "Example:\n";
			printWelcome();
			std::cout << "10 * 8\n";

			std::cout << "Press enter to exit\n";
			std::cin.get();
			continue;
		}

		// check if the input is a valid expression
		std::istringstream stream(input);
		stream.exceptions(std::ios::failbit | std::ios::badbit);

		int leftOperand;
		char operatorChar;
		int rightOperand;
		try
		{ 
			stream >> leftOperand >> operatorChar >> rightOperand;

		}
		catch (const std::ios_base::failure& e)
		{
			std::cout << "Invalid expression. Please try again.\n";
			std::cout << "Press enter to continue\n";
			std::cin.get();
			continue;
		}

		if (
			operatorChar != '+' &&
			operatorChar != '-' &&
			operatorChar != '*' &&
			operatorChar != '/'
			)
		{
			std::cout << "Invalid operator. Please use +, -, *, or /.\n";
			std::cout << "[WARNING]: expressions with decimal/non integer numbers is not supported.\n";
			std::cout << "Press enter to continue\n";
			std::cin.get();
			continue;
		}

		std::cout << expressionResult(leftOperand, operatorChar, rightOperand) << std::endl;
		std::cin.get();
	}


}

#include <iostream>
#include <cmath> // Include the cmath library to use pow function
#include <string> // Include the string library to use strings
int bitwiseAND(int a, int b) {
	return a & b;
}

int bitwiseOR(int a, int b) {
	return a | b;
}
int bitwiseNOT(int a) {
	return ~a;
}
int bitwiseXOR(int a, int b) {
	return a ^ b;
}
int bitwiseLeftShift(int a, int bits) {
	return a << bits;
}
int bitwiseRightShift(int a, int bits) {
	return a >> bits;
}
std::string printBinary(int value)
{
	std::string tmp;
	value = abs(value);
	while (value)
	{
		tmp.push_back((value % 2) + '0');
		value /= 2;
	}
	std::string result;
	for (int i = tmp.length() - 1; i >= 0; i--)
	{
		result.push_back(tmp[i]);
	}
	return result;
}

int main() {
	setlocale(LC_ALL, "Rus");
	char operation = '\0'; // operation = ' '
	while (operation != 'q')
	{
		std::cout << "Enter operator ((&, |, ~, ^, 'r', 'l') or press 'q' to quit): ";
		std::cin >> operation;
		if (operation != 'q' && operation != '&' && operation != '|'
			&& operation != '~' && operation != '^'
			&& operation != 'r' && operation != 'l') {
			std::cout << "Operator input error. Please repeat the input" << std::endl;
			continue;
		}
		if (operation == 'q') {
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		std::cout << "Введите 2 числа формата 1110 или 111: ";
		std::string myBits1, myBits2;
		std::cin >> myBits1 >> myBits2;
		int numberMyBits1 = 0;
		int numberMyBits2 = 0;
		int length1 = myBits1.length();
		int length2 = myBits2.length();
		//int length1 = std::stoi(myBits1, nullptr, 2); //конвертирует string в int и пересчитывает в десятичную систему 10, 25 и т.д.
		//int length2 = std::stoi(myBits2, nullptr, 2);
		for (int i = 0; i < 16 && i < length1; i++) {
			if (myBits1[i] == '1') {
				numberMyBits1 += pow(2, i) * 1;
			}
		}
		for (int i = 0; i < 16 && i < length2; i++) {
			if (myBits2[i] == '1') {
				numberMyBits2 += pow(2, i) * 1;
			}
		}
		switch (operation)
		{
		case '&':
			std::cout << "Битовое И (AND):" << std::endl;
			std::cout << "Result (DEC): " << bitwiseAND(numberMyBits1, numberMyBits2) << std::endl;
			std::cout << "Result (Binary): " << printBinary(bitwiseAND(numberMyBits1, numberMyBits2)) << std::endl;
			break;
		case '|':
			std::cout << "Битовое ИЛИ (or, '|')" << std::endl;
			std::cout << "Result (DEC): " << bitwiseOR(numberMyBits1, numberMyBits2) << std::endl;
			std::cout << "Result (Binary): " << printBinary(bitwiseOR(numberMyBits1, numberMyBits2)) << std::endl;
			break;
		case '~':
			std::cout << "Битовое НЕ(NOT, '~')" << std::endl;
			std::cout << "Result (DEC): " << bitwiseNOT(numberMyBits1) << std::endl;
			std::cout << "Result (Binary): " << printBinary(bitwiseNOT(numberMyBits1)) << std::endl;
			std::cout << "Result (DEC): " << bitwiseNOT(numberMyBits2) << std::endl;
			std::cout << "Result (Binary): " << printBinary(bitwiseNOT(numberMyBits2)) << std::endl;
			break;
		case '^':
			std::cout << "Битовое исключающее ИЛИ (XOR, '^')" << std::endl;
			std::cout << "Result (DEC): " << bitwiseXOR(numberMyBits1, numberMyBits2) << std::endl;
			std::cout << "Result (Binary): " << printBinary(bitwiseXOR(numberMyBits1, numberMyBits2)) << std::endl;
			break;
		case 'r':
			std::cout << "Битовый сдвиг вправо (right shift, '>>')" << std::endl;
			std::cout << "Result (DEC): " << bitwiseRightShift(numberMyBits1, numberMyBits2) << std::endl;
			std::cout << "Result (Binary): " << printBinary(bitwiseRightShift(numberMyBits1, numberMyBits2)) << std::endl;
			break;
		case 'l':
			std::cout << "Битовый сдвиг вправо (left shift, '<<')" << std::endl;
			std::cout << "Result (DEC): " << bitwiseLeftShift(numberMyBits1, numberMyBits2) << std::endl;
			std::cout << "Result (Binary): " << printBinary(bitwiseLeftShift(numberMyBits1, numberMyBits2)) << std::endl;
			break;
		default:
			std::cout << "Invalid operator or character. Please repeat" << std::endl;
		}
	}
	std::cout << "\nКонец программы. Возвращайтесь :) \n";
	return 0;
}

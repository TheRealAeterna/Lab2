#include <iostream>
#include <bitset>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	unsigned short A;   // unsigned short целочисленное безнаковое число от 0 до 65535 (2 байта)
	int i;

	cout << "ввод A (2 byte) >> ";
	cin >> A;

	cout << "ввод i (0-7) >> ";
	cin >> i;

	if (i < 0 || i > 7) {   // проверка i на допустимые значения
		cout << "ошибка при вводе i" << endl;
		return 1;
	}

	cout << A << " >> " << bitset<8>(A) << endl; //вывод по образцу

	bitset<8> bits(A);

	int bit = (A >> i) & 1;
    cout << "Бит " << i << " = " << bit << endl;

	// начало задания (вариант 3)

	//пункт 2
	int a;
	int b;

	
	if (bit != 0) {

		cout << "ввод чисел: " << endl
			<< "a >> "; 
		cin >> a;
		cout << "b >> ";
		cin >> b;

		if ((b != 0) && (a % b == 0)) {
			cout << "a / b = " << a / b << endl;
		}
		else if ((a != 0) && (b % a == 0)) {
			cout << "b / a = " << b / a << endl;
		}
		else {
			cout << "a * b = " << a * b << endl;
		}
	}
	else {
		if (i > 0) {
			A = A ^ (1 << (i - 1));
		}
		if (i < 7) {
			A = A ^ (1 << (i + 1));
		}
		cout << bitset<8>(A) << endl;
	}
	//пункт 3

	unsigned short N;
	cout << "ввод N >> ";
	cin >> N;

	/*
	перебор ошибок
	с использованием конструкции switch case
	*/

	switch (N) { 
		case 1:
		cout << "error 1: Неисправность ЭБУ впрыска" << endl;
		break;
	case 2:
		cout << "error 2: Неисправность ДУТ" << endl;
		break;
	case 4:
		cout << "error 4: Повышенное напряжение" << endl;
		break;
	case 8:
		cout << "error 8: Пониженное напрядение" << endl;
		break;
	case 13:
		cout << "error 13: Отсутствует сигнал датчика кислорода" << endl;
		break;
	case 51:
		cout << "error 51: Неисправность работы ПЗУ" << endl;
		break;
	case 52:
		cout << "error 52: Неисправность работы ОЗУ" << endl;
		break;
	case 55:
		cout << "error 55: Слишком бедная смесь" << endl;
		break;
	case 61:
		cout << "error 61: Проблемы в работе датчика кислорода" << endl;
		break;
	default:
		cout << "unknown error: Неопознанная ошибка" << endl;
		break;
	}

	return 0;
}
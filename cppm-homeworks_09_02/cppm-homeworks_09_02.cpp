// cppm-homeworks_09_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>



class Fraction
{
private:
	int numerator_;
	int denominator_;
	//возвращает числитель
	

public:

	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	//для  вывода в консоль
	std::string get_fract() {
	
		return std::to_string(numerator_) + "/" + std::to_string(denominator_);
	}
	//для сокращения дроби
	Fraction get_tuned() {
		for (int i = 9; i > 0; i--) {
			if ((numerator_ % i == 0) && (denominator_ % i == 0)) {
				numerator_ /= i;
				denominator_ /= i;
			}
		}
		return *this;
	}
	

	//префиксный
	Fraction& operator++() { numerator_ += denominator_; return *this; }
	Fraction& operator--() { numerator_ -= denominator_; return *this; }
	//постфиксный
	Fraction operator++(int) {
		Fraction tmp = *this;
		numerator_ += denominator_;
		return tmp;
	}
	Fraction operator--(int) {
		Fraction tmp = *this;
		numerator_ -= denominator_;
		return tmp;
	}
	//+
	Fraction operator+(Fraction another) {
		int tmp_numer = (numerator_ * another.denominator_) + (another.numerator_ * denominator_);
		int tmp_denom = denominator_ * another.denominator_;
		return Fraction(tmp_numer, tmp_denom);
	}
	//-
	Fraction operator-(Fraction another) {
		int tmp_numer = (numerator_ * another.denominator_) - (another.numerator_ * denominator_);
		int tmp_denom = denominator_ * another.denominator_;
		return Fraction(tmp_numer, tmp_denom);
	}
	//*
	Fraction operator*(Fraction another) {
		int tmp_numer = numerator_ * another.numerator_;
		int tmp_denom = denominator_ * another.denominator_;
		return Fraction(tmp_numer, tmp_denom);
	}
	// "/"
	Fraction operator/(Fraction another) {
		int tmp_numer = numerator_ * another.denominator_;
		int tmp_denom = denominator_ * another.numerator_;
		return Fraction(tmp_numer, tmp_denom);
	}
	
};


int main()
{
	setlocale(LC_ALL, "rus");
	//дробь 1
	int numerator, denominator;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator;
	Fraction fraction1(numerator, denominator);
	//дробь 2
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator;
	Fraction fraction2(numerator, denominator);

	std::cout << fraction1.get_fract() << " + " << fraction2.get_fract() << " = " << (fraction1 + fraction2).get_tuned().get_fract() << std::endl;
	std::cout << fraction1.get_fract() << " - " << fraction2.get_fract() << " = " << (fraction1 - fraction2).get_tuned().get_fract() << std::endl;
	std::cout << fraction1.get_fract() << " * " << fraction2.get_fract() << " = " << (fraction1 * fraction2).get_tuned().get_fract() << std::endl;
	std::cout << fraction1.get_fract() << " / " << fraction2.get_fract() << " = " << (fraction1 / fraction2).get_tuned().get_fract() << std::endl;
	std::cout << "++" << (fraction1.get_fract()) << " * " << (fraction2.get_fract()) << " = ";
	std::cout << (++fraction1 * fraction2).get_tuned().get_fract() << std::endl;
	std::cout << "Значение дроби 1 = " << fraction1.get_fract() << std::endl;
	std::cout << (fraction1.get_fract()) << "--" << " * " << (fraction2.get_fract()) << " = ";
	std::cout << (fraction1-- * fraction2).get_tuned().get_fract() << std::endl;
	std::cout << "Значение дроби 1 = " << fraction1.get_fract() << std::endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

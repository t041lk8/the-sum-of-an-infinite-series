/***---------------------------------------****
****-----------Курс информатика------------****
****---------------------------------------****
* Project Type : Win32 Console Application    *
* Project Name : Lab_1.CPP                    *
* Language     : CPP, MSVS ver 2015 and above *
* Programmers  : Zhbanov I.A.                 *
* Modified By  : Zhbanov I.A.                 *
* Created      : 15/09/2020                   *
* Last Revision: 16/09/2020                   *
* --------------------------------------------*
* Comment      : Первая лабораторная работа   *
****------------------------------------------*/

#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");                       //Подключение русской локализации

	int N, Sign;                                      
	float Eps, X, Sum, TSum, Diff, ArgX, Slag;        

	std::cout << "Введите аргумент Х: ";
	std::cin >> X;
	std::cout << "Вы ввели Х = " << X << endl;        //ЭХО-печать аргумента Х
	if ((X <= -1) || (X > 1)) {                       //Входной контроль
		std::cout << "Ошибка! X должен быть в промежутке (-1;1]";
		return 1;
	}//if

	std::cout << "Введите точность: ";                  
	std::cin >> Eps;									
	std::cout << "Вы ввели Eps = " << Eps << endl;      //ЭХО-печать точности Eps
	if (Eps <= 0)										//Входной контроль
	{                                                           
		std::cout << "Ошибка! Eps должен быть >0";
		return 2;
	}//if


    //Инициализация переменных
	N = 0;                          //Кол-во просуммированных элементов
	TSum = log(1 + X);              //Точное значение
	Sum = 0;                        //Сумма ряда
	Sign = -1;                      //Определяет знак перед слагаемым
	ArgX = 1;                       //Аргумент Х, возведенный в степень N
	Diff = TSum - Sum;              //Разность между точным значением и суммой ряда
	if (Diff < 0) Diff = -Diff;     //Берем модуль от Diff

	while (Diff > Eps)               //Расчет суммы ряда
	{             
		N++;                         //Переход к следующему N
		Sign = -Sign;                //Меняем знак слагаемого
		ArgX = ArgX * X;             //Увеличиваем степень аргумента Х
		Slag = Sign * ArgX / N;      //Формируем слагаемое
		Sum = Sum + Slag;            //Считаем новую сумму
		Diff = TSum - Sum;           //Считаем разность
		if (Diff < 0) Diff = -Diff;  //Берем модуль от Diff
	} //while

	std::cout << "Количество просуммированных элементов: " << N << endl 
		<< "Точное значение: " << TSum << endl << "Сумма ряда: " << Sum 
		<< endl << "Разница:  " << Diff << endl << "Точность: " << Eps;
	return 0;
} //main
/**** End Of File LAB1.CPP ****/
/***---------------------------------------****
****-----------���� �����������------------****
****---------------------------------------****
* Project Type : Win32 Console Application    *
* Project Name : Lab_1.CPP                    *
* Language     : CPP, MSVS ver 2015 and above *
* Programmers  : Zhbanov I.A.                 *
* Modified By  : Zhbanov I.A.                 *
* Created      : 15/09/2020                   *
* Last Revision: 16/09/2020                   *
* --------------------------------------------*
* Comment      : ������ ������������ ������   *
****------------------------------------------*/

#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");                       //����������� ������� �����������

	int N, Sign;                                      
	float Eps, X, Sum, TSum, Diff, ArgX, Slag;        

	std::cout << "������� �������� �: ";
	std::cin >> X;
	std::cout << "�� ����� � = " << X << endl;        //���-������ ��������� �
	if ((X <= -1) || (X > 1)) {                       //������� ��������
		std::cout << "������! X ������ ���� � ���������� (-1;1]";
		return 1;
	}//if

	std::cout << "������� ��������: ";                  
	std::cin >> Eps;									
	std::cout << "�� ����� Eps = " << Eps << endl;      //���-������ �������� Eps
	if (Eps <= 0)										//������� ��������
	{                                                           
		std::cout << "������! Eps ������ ���� >0";
		return 2;
	}//if


    //������������� ����������
	N = 0;                          //���-�� ���������������� ���������
	TSum = log(1 + X);              //������ ��������
	Sum = 0;                        //����� ����
	Sign = -1;                      //���������� ���� ����� ���������
	ArgX = 1;                       //�������� �, ����������� � ������� N
	Diff = TSum - Sum;              //�������� ����� ������ ��������� � ������ ����
	if (Diff < 0) Diff = -Diff;     //����� ������ �� Diff

	while (Diff > Eps)               //������ ����� ����
	{             
		N++;                         //������� � ���������� N
		Sign = -Sign;                //������ ���� ����������
		ArgX = ArgX * X;             //����������� ������� ��������� �
		Slag = Sign * ArgX / N;      //��������� ���������
		Sum = Sum + Slag;            //������� ����� �����
		Diff = TSum - Sum;           //������� ��������
		if (Diff < 0) Diff = -Diff;  //����� ������ �� Diff
	} //while

	std::cout << "���������� ���������������� ���������: " << N << endl 
		<< "������ ��������: " << TSum << endl << "����� ����: " << Sum 
		<< endl << "�������:  " << Diff << endl << "��������: " << Eps;
	return 0;
} //main
/**** End Of File LAB1.CPP ****/
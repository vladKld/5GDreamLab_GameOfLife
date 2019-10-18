#ifndef __GAME_2019__
#define __GAME_2019__
#include "Table.h"
#include <random>
#include <time.h>
#include <Windows.h>

class Game {
	Table gameField; // ������� ����
	unsigned long long iteration; // ���������� �������� ����
	bool clearConsole; // �������� ������� ( ���� / �� ���� )
public:
	Game() : iteration(0), clearConsole(true) {
		srand(time(NULL));
		int rows, cols; 
		int mode;
		bool** f; // �������� ����
		int tmp1;
		std::cout << "\t\t ========== ����� ���������� � ���� '�����' ==========" << std::endl;
		std::cout << "\t\t ====== ��� ������, ������ ����������� ������ ========" << std::endl;
		std::cout << "\t | ������� '1', ���� ������, ����� ������� ��������� �� ������ �������� ����� |\n";
		std::cout << "\t | ������� '2', ���� ������, ����� ������ �������� ����� ���������� �� ������ |\n";
		std::cout << "\t |> ����: ";
		std::cin >> tmp1;
	
		if (tmp1 == 2) clearConsole = false;
		else clearConsole = true;

		std::cout << "\t | ������� '1' ��� ������ ���� �� ��������� �������������                     |\n";
		std::cout << "\t | ������� '2' ��� ������ ���� �� ����� �������������                         |\n";
		std::cout << "\t |> ����: ";
		std::cin >> mode;
		if (mode == 2) {   // �������� ������ ������������ ����
			do { 
				std::cout << "\t |> ������� ���������� �����(0 < x < 1001 ): ";
				std::cin >> rows;
			} while (rows > 1000 || rows < 1);

			do { 
				std::cout << "\t |> ������� ���������� ��������( 0 < y < 1001 ): ";
				std::cin >> cols; 
			} while (cols > 1000 || cols < 1);

			f = new bool*[rows];
			for (int i = 0; i < rows; ++i)
				f[i] = new bool[cols];
			std::cout << std::endl;
			std::cout << "\t\t =================== ������� ���� ====================" << std::endl;
			std::cout << "\t| 0 0 0 0 0 0 0 |\n";
			std::cout << "\t| 0 0 0 1 0 0 0 |\n";
			std::cout << "\t| 0 0 0 0 1 0 0 |              - ������ ������� ����, ��� 0 - �������, 1 - ����� \n";
			std::cout << "\t| 0 0 1 1 1 0 0 |\n";
			std::cout << "\t| 0 0 0 0 0 0 0 |\n";
			std::cout << "\t =====================================================" << std::endl;
			std::cout << "\t|> ������� ������ ���� (���� ������ �������� ������ �� 0 � 1, ����������� ���������): \n";
			for (int i = 0; i < rows; ++i) {
				std::cout << "\t|> ";
				for (int j = 0; j < cols; ++j)
					std::cin >> f[i][j];
			}
		}
		else { // ��������� ������������ ����
			rows = rand() % 16 + 5, cols = rand() % 16 + 5;
			f = new bool*[rows];
			for (int i = 0; i < rows; ++i)
				f[i] = new bool[cols];
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					f[i][j] = rand() % 2;
		}
		gameField = Table(cols, rows, f); 
		 
		for (int i = 0; i < rows; ++i)
			delete[] f[i];
		delete[] f;
	}

	void playGame() {
		do {
			Sleep(1000); // ���������� ��������� ��������� (��� � 1 ���)
			if(clearConsole)
				system("cls"); // ������� �������
			++iteration;
			std::cout << "\t ======= " << iteration << " ======="<< std::endl;
			std::cout << "======= ���������� ����� ������: " << gameField.countOfAlive() << " =======" << std::endl;
			gameField.printField();
			if (iteration == 1) {
				char p;
				std::cout << "\n������� '1', ����� ������: ";
				std::cin >> p;
			}
		} while (gameField.countOfAlive() > 0 && !gameField.nextGeneration()); // ���� ���� ���� �� ���� ����� ������
																			   // � ���������� ��������� �� ����� ��������
	}
};

#endif
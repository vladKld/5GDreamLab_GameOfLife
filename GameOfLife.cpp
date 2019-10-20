//================= 5G_DreamLab project ==========================
//================ Conway's game of life =========================
//========== Подготовил студент 2 курса бакалавриата =============
//========================  СПБГУ  ===============================
//===========    Жаворонков Владислав Олегович    ================
//== Проект содержит три файла: GameOfLife.cpp; Game.h; Table.h ==
//----------------------------------------------------------------
// Table.h содержит класс Table, описывающий логику игрового поля: 
// его создание, хранение, и удаление. Также Table содержит метод,
// меняющий поколение.
//----------------------------------------------------------------
// Game.h содержит класс Game, описывающий саму игру:
// Выводит инструкцию по игре, запускает основной игровой цикл.
//----------------------------------------------------------------
// GameOfLife.cpp содержит только функцию main: создает объект
// класса Game и запускает игру
//----------------------------------------------------------------

#include <iostream>
#include "Game.h"

int main()
{
	setlocale(0, "Russian");
	Game mainGame;
	mainGame.playGame();
	system("pause");
	return 0;
}


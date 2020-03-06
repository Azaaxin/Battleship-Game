#include <iostream>
#include <stdlib.h>
#include <ctime>	// gör det möjligt att använda "random" funktionen i programmet
#include <windows.h>
using namespace std;

int hit = 0, timesG = 0;
int y, x, ysvar, xsvar, playgroundx = 0, playgroundy = 0;
float gameVerisin = 4.0;
int i = 0, j = 0, counterVert;
const int width = 27;
const int height = 27;
char gameboard[width][height] = {
		{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },	// 32 = mellanslag (ASCII) sparat i vektor/array
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 }
};
void loadfor();
void userbattle();
void AIbattle();
void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);	// Get Handle
	SetConsoleScreenBufferSize(Handle, coord);	// Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);	// Set Window Size
}
void begin_screen()
{
	system("color 05");
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "@                                                                                    @" << endl;
	cout << "@  @@@@@@/    .@@@   %@@@@@@@*@@@@@@@% @@     @@@@@@  @@@@@#  @@    @@  @@* @@@@@@  @" << endl;
	cout << "@  @@   @@    @@#@(    @@*     *@%    @@     @@     ,@@      @@    @@  @@* @@  ,@@ @" << endl;
	cout << "@  @@@@@@.   @@  @@     @@*     *@%    @@     @@@@@,  %@@@@   @@@@@@@@  @@*  @@ .@@*@" << endl;
	cout << "@  @@   &@& (@@@@@@@    @@*     *@%    @@     @@         ,@@  @@    @@  @@* @@,,    @" << endl;
	cout << "@  @@,,#@@. @@    &@@   @@*     *@%    @@%%%* @@%%%% #@*,@@@  @@    @@  @@* @@      @" << endl;
	cout << "@                                                                                    @" << endl;
	cout << "@            By: Azaaxin                                                             @" << endl;
	cout << "@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@" << endl;

}
int main()
{
	string title = ("Azaaxin's Battleship");
	SetConsoleTitle(title.c_str());
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &ConsoleInfo);
	int originalAttrs = ConsoleInfo.wAttributes;
	SetWindow(90, 50);
	begin_screen();
	//locale swedish("swedish");	//äöå
	//locale::global(swedish);	// äöå
	srand(time(NULL));
	char answerONswitch;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[P]lay " << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	//cout << "[L]åt en bot gissa" << endl;
	cout << "[E]xit " << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
	cin >> answerONswitch;
	switch (answerONswitch)
	{
		case 'P':
		case 'p':
			{
				userbattle();
				break;
			}
		case 'L':
		case 'l':

			{

				cout << "Doesn't work!" << endl;
				system("pause");
				system("cls");
				return main();
				//AIbattle();
				break;
			}
	}
	return 0;
}
void userbattle()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &ConsoleInfo);
	int originalAttrs = ConsoleInfo.wAttributes;
	cout << "Choose the size of the playground " << endl;
	cout << "Height of the playground(in rows, between 1-27 rows)? ";
	cin >> playgroundy;
	cout << endl << "Width of the playground(in rows, between 1-27 rows)? ";
	cin >> playgroundx;
	if (playgroundx >= 28 || playgroundy >= 28)
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR]The maximum size of the playground is: 27x27 " << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
		system("pause cls");

		return userbattle();
	}
	else if (playgroundx <= 0 || playgroundy <= 0)
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "[ERROR]The minimum size of the playground is: 1x1 " << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
		system("pause cls");
		return userbattle();
	}
	else
	{
		y = rand() % playgroundy;
		x = rand() % playgroundx;
		system("cls");
		do { 	// början på do-while loop
			//cout << x << y<<endl; Skriver ut svaret i fšrvŠg
			cout << "  " << "|";
			for (counterVert = 0; playgroundy > counterVert; counterVert++)
			{
				if (counterVert > 10)
				{
					cout << counterVert << " ";
				}
				else
				{
					cout << counterVert << " ";
				}
			}
			cout << endl;
			for (i = 0; i < playgroundx; i++)
			{
				if (i < 10)
				{
					cout << i << " |";
				}
				else
				{
					cout << i << "|";
				}
				for (j = 0; j < playgroundy; j++)
				{

					if (j < 10)
					{

						cout << gameboard[j][i] << " ";
					}
					else
					{
						cout << gameboard[j][i] << "  ";
					}
				}
				cout << endl;
			}

			cout << "-----------------" << endl;
			cout << "A new shot\n";
			cout << "Set Y-Coordinate: ";
			cin >> xsvar;
			cout << endl;
			cout << "Set X-Coordinate: ";
			cin >> ysvar;
			cout << endl << endl;
			system("cls");
			if (x == xsvar && y == ysvar)	// checkar svaret på gissningarna
			{
				hit = 1;
				gameboard[ysvar][xsvar] = 42;
			}
			else if (xsvar == 624)
			{
				system("cls");
				cout << "The answer is:" << x << " &" << y << endl;
				system("pause cls");
			}
			else if (xsvar >= playgroundx || ysvar >= playgroundy)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout << "Oops, you missed the playground" << endl;
				SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
				system("pause");
			}
			else
			{
				gameboard[ysvar][xsvar] = 120;
			}

			timesG++;	// hur många gånger
		} while (hit != 1);

		cout << "*--------------------------------------------------------------*" << endl;
		cout << "                   Congratulations you won!!" << endl;
		cout << "Statistics:" << endl << "------" << endl;
		cout << "X-Answer: " << x << endl;
		cout << "Y-Answer: " << y << endl;
		cout << "Chances: " << timesG << endl;
		cout << "Difficulty: " << playgroundy << "x" << playgroundx << endl;
		cout << "*--------------------------------------------------------------*" << endl;
		cout << "This is the first English version of the game, created by Azaaxin" << endl << "version:" << gameVerisin << endl;
		cout << endl << "Press any key to exit! :D";
		cin.get();
		cin.get();
	}
}
void AIbattle()
{
	int x1 = 0, y1 = 0;
	y = rand() % 27 + 1;
	x = rand() % 27 + 1;
	x = playgroundx;
	y = playgroundy;
	cout << "  " << "|";
	for (counterVert = 0; playgroundx > counterVert; counterVert++)
	{
		if (counterVert > 10)
		{
			cout << counterVert << " ";
		}
		else
		{
			cout << counterVert << " ";
		}
	}
	cout << endl;
	//	cout << " " << "|123456789" << endl;
	for (i = 0; i < playgroundy; i++)
	{
		if (i < 10)
		{
			cout << i << " |";
		}
		else
		{
			cout << i << "|";
		}

		for (j = 0; j < playgroundx; j++)
		{

			if (j < 10)
			{

				cout << gameboard[j][i] << " ";
			}
			else
			{
				cout << gameboard[j][i] << "  ";
			}
		}
		cout << endl;
	}
	do {
		int totalRandomsize = 0;
		totalRandomsize = playgroundx * playgroundy;
		for (int o = 0; x == x1 && y == y1; o++)
		{
			if (x1 == xsvar && y1 == ysvar)	// checkar svaret på gissningarna
			{
				hit = 1;
				gameboard[ysvar][xsvar] = 42;
			}
			else
			{
				gameboard[ysvar][xsvar] = 120;
			}
		}
		while (x1 == xsvar && y1 == ysvar);
		timesG++;	// hur många gånger
	} while (hit != 1);
	cout << "*--------------------------------------------------------------*" << endl;
	cout << "                   Congratulations you won!!" << endl;
	cout << "Statistics:" << endl << "------" << endl;
	cout << "X-Answer: " << x << endl;
	cout << "Y-Answer: " << y << endl;
	cout << "Chances: " << timesG << endl;
	cout << "Difficulty: " << playgroundy << "x" << playgroundx << endl;
	cout << "*--------------------------------------------------------------*" << endl;
	cout << "This is the first English version of the game, created by Azaaxin" << endl << "version:" << gameVerisin << endl;
	cout << endl << "Press any key to exit! :D";
	cin.get();
	cin.get();
}

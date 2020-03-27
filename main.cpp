#include"main.h"

using namespace std;

void map_show();
void map_move(int ch, int count);
void gotoxy(int x, int y);

void CursorView(char show)//Ä¿¼­¼û±â±â
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int main() {
	CursorView(0);
	gotoxy(0, 0);
	map_show();
	while (true) {
		srand((unsigned int)time(NULL));
		int ch = rand() % num;//Ãß°¡ ¹æÇØ¹° ¸Ê ·£´ý ¼±ÅÃ
		int count = 0;
		for (int i = 0; i < 12; i++){
			gotoxy(0, 0);
			map_move(ch, count);
			map_show();
			Sleep(50);
			count++;
		}


		//Sleep(100);
	}
	
	return 0;
}

void gotoxy(int x, int y) {
	COORD posXY = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}

void map_show() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 1) {
				cout << "¡á";
			}
			else
				cout << "  ";
		}
		cout << endl;
	}
}

void map_move(int ch, int count) {
	
	for (int i = 1; i < row - 1; i++) {
		for (int j = 1; j < col - 1; j++) {
			map[i][j] = map[i][j + 1];

		}
		map[i][col - 2] = map_add[ch][i][count];

	}

}
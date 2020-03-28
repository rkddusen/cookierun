#include"main.h"

using namespace std;

void map_show();
void map_move(int ch, int count);
void gotoxy(int x, int y);
void character();
int Jump(int ch_y);
void char_move(int ch_x, int ch_y);
void char_clean(int ch_x, int ch_y);
int Jump_back(int ch_y);

void CursorView(char show)//커서숨기기
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
		int ch = rand() % num;//추가 방해물 맵 랜덤 선택
		int count = 0;
		for (int i = 0; i < 12; i++){
			gotoxy(0, 0);
			map_move(ch, count);
			map_show();
			character();
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
				cout << "■";
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

void character() {
	int ch_x = 12;
	int ch_y = 17;

	char kb = 0;
	if (_kbhit()) {
		kb = _getch();
		if (kb == 'j') {
			for (int i = 0; i < 5; i++) {
				
				ch_y = Jump(ch_y);
				char_clean(ch_x, ch_y);
				char_move(ch_x, ch_y);
				Sleep(5);
			}
		}
	}
	else {
		//if (ch_y != 17) {
		//	ch_y = Jump_back(ch_y);
		//	
		//}
		//else {
		//	//gotoxy(10, 14);//5*4배열일 때
		//	ch_x = 12;
		//	ch_y = 17;
		//}
		for (int i = 0; i < 5; i++) {
			if (ch_y != 17) {
				ch_y = Jump_back(ch_y);
				char_clean(ch_x, ch_y);
				char_move(ch_x, ch_y);
				Sleep(5);
			}
			else {
				char_move(ch_x, ch_y);
				break;
			}
		}
		//char_move(ch_x, ch_y);
	}
	
}
void char_move(int ch_x, int ch_y) {
	gotoxy(ch_x, ch_y);
	for (int i = 0; i < ch_row; i++) {
		for (int j = 0; j < ch_col; j++) {
			if (char_map[i][j] == 1) {
				cout << "＠";
			}
			else
				cout << "  ";
		}
		//gotoxy(10, 15 + i);//5*4배열일 때
		gotoxy(ch_x, ch_y + i + 1);
	}
}

int Jump(int ch_y) {
	ch_y--;

	return ch_y;
}

int Jump_back(int ch_y) {
	ch_y++;

	return ch_y;
}

void char_clean(int ch_x, int ch_y) {//점프 후 잔상 지우기
	gotoxy(ch_x, ch_y);
	for (int i = 0; i < ch_row; i++) {
		for (int j = 0; j < ch_col; j++) {
			cout << "  ";
		}
		gotoxy(ch_x, ch_y+i+1);
		cout << "  ";
	}
}
﻿#include "header.h"

#include <stdio.h>
#include <conio.h>
#include <ctime> 
#include "windows.h"


//========= lấy tọa độ x của con trỏ hiện tại =======
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
inline void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { (SHORT)x, (SHORT)y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}

	return KEY_NONE;
}
// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void SetColor2(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}
// Hàm tự viết
// x, y là tọa độ con trỏ cần nhảy đến để viết, content là chuỗi cần truyền vào, t_color là màu truyền vào
void my_print(int x, int y, int t_color, std::string content) {
	textcolor(t_color);
	gotoXY(x, y);
	std::cout << content;
	textcolor(WHITE);
}
//Tạo box
void box(int x, int y, int width, int height, int t_color) {
	if (width <= 2 || height <= 1)
		return;
	textcolor(t_color);
	for (int i = x + 1; i < x + width; i++) {
		gotoXY(i, y);
		std::cout << char(196);
		gotoXY(i, y + height);
		std::cout << char(196);

	}
	for (int i = y + 1; i < y + height; i++) {
		gotoXY(x, i);
		std::cout << char(179);
		gotoXY(x + width, i);
		std::cout << char(179);
	}
	gotoXY(x, y); std::cout << char(218);
	gotoXY(x + width, y); std::cout << char(191);
	gotoXY(x, y + height); std::cout << char(192);
	gotoXY(x + width, y + height); std::cout << char(217);

	textcolor(WHITE);
}
// Tạo nhiều BOX
void n_box(int x, int y, int width, int height, int amount, int t_color) {
	if (width <= 2 || height <= 1)
		return;
	for (int i = 0; i < amount; i++) {
		box(x, y + i * height, width, height, t_color);
	}
	SetColor(t_color);
	for (int i = 1; i < amount; i++) {
		gotoXY(x, y + i * height); std::cout << char(195);
		gotoXY(x + width, y + i * height); std::cout << char(180);
	}
	SetColor(WHITE);
}
void mark_bar(int x, int y, int width, int height, int b_color, std::string content) {
	if (width <= 2 || height <= 1)
		return;

	textcolor(b_color);//68
	for (int i = x; i < x - 1 + width; i++)
		for (int j = y; j < y - 1 + height; j++) {
			gotoXY(i, j);
			std::cout << " ";
		}
	gotoXY(x, y);
	std::cout << content;

	textcolor(7);
}
//Menu 
int menu(int x, int y, int width, int height, int amount, std::string option[], int box_color, int text_color, int b_color_light) {
	char ch;
	ShowCur(0);
	int x_tmp = x, y_tmp = y;
	bool check = 1;
	n_box(x, y, width, height, amount, box_color);
	for (int i = 1; i <= amount; i++) {
		my_print(x + 1, y + 1 + (i - 1) * height, text_color, option[i - 1]);
	}
	int x_del = x, y_del = y;
	while (1) {
		if (check == 1) {
			mark_bar(x_del + 1, y_del + 1, width, height, text_color, option[(y_del - y) / height]);
			mark_bar(x_tmp + 1, y_tmp + 1, width, height, text_color + b_color_light * 16, option[(y_tmp - y) / height]);
			check = 0;
			x_del = x_tmp, y_del = y_tmp;
		}
		if (_kbhit()) {
			ch = _getch();
			if (ch == -32) {
				ch = _getch();
				check = 1;
				if (ch == 72) {
					if (y_tmp - y == 0)
						y_tmp = y + (amount - 1) * height;
					else
						y_tmp -= height;
				}
				else if (ch == 80) {
					if (y_tmp - y == (amount - 1) * height)
						y_tmp = y;
					else
						y_tmp += height;
				}
				//else if (ch == 75) {
				//	//đi qua trái
				//}
				//else if (ch == 77) {
				//	// đi qua phải
				//}
			}
			else if (ch == 13) {
				return (y_tmp - y) / height + 1;
			}
		}
	}
}
int enter_again_yes_no(int coordinate_x, int coordinate_y, int width_box, int height_box, int distance, int mark_bar_color, int text_color) {
	std::string option[] = { "YES", "NO" };
	int amount = sizeof(option) / sizeof(option[0]);

	box(coordinate_x, coordinate_y, width_box, height_box, text_color);
	box(coordinate_x + width_box + distance, coordinate_y, width_box, height_box, text_color);
	my_print(coordinate_x + 1 + 2, coordinate_y + 1, text_color, option[0]);
	my_print(coordinate_x + width_box + distance + 1 + 2, coordinate_y + 1, text_color, option[1]);
	char ch;
	int check = 1;
	int x_cur = coordinate_x;
	int y_cur = coordinate_y;
	int x_old = x_cur;
	int y_old = y_cur;

	int choice = 0;
	while (true) {
		if (check == 1) {
			textcolor(BLACK * 16 + text_color);
			for (int j = 0; j < height_box - 1; j++)
				for (int i = 0; i < width_box - 1; i++) {
					gotoXY(x_old + 1 + i, y_old + 1 + j);
					std::cout << " ";
				}
			gotoXY(x_old + 1 + 2, y_old + 1);
			std::cout << option[(x_old - coordinate_x) / (width_box + distance)];
			textcolor(WHITE);

			textcolor(mark_bar_color * 16 + BLACK);
			for (int j = 0; j < height_box - 1; j++)
				for (int i = 0; i < width_box - 1; i++) {
					gotoXY(x_cur + 1 + i, y_cur + 1 + j);
					std::cout << " ";
				}
			gotoXY(x_cur + 1 + 2, coordinate_y + 1);
			std::cout << option[(x_cur - coordinate_x) / (width_box + distance)];
			textcolor(WHITE);

			x_old = x_cur, y_old = y_cur;
			check = 0;
		}
		if (_kbhit()) {
			ch = _getch();
			if (ch == -32) {
				ch = _getch();
				check = 1;
				if (ch == 75) {
					if (x_cur == coordinate_x)
						x_cur = coordinate_x + (amount - 1) * (width_box + distance);
					else
						x_cur -= width_box + distance;
				}
				else if (ch == 77) {
					if (x_cur == coordinate_x + (amount - 1) * (width_box + distance))
						x_cur = coordinate_x;
					else
						x_cur += width_box + distance;
				}
			}
			else if (ch == 13) {
				return (x_cur - coordinate_x) / (width_box + distance) + 1;

			}
		}
	}
}

//menu Staff
void menu_Staff(int x, int y, int width, int height, int amount, std::string option[], int box_color, int text_color, int b_color_light, int option_num) {

	ShowCur(0);
	n_box(x, y, width, height, amount, box_color);
	for (int i = 1; i <= amount; i++) {
		my_print(x + 1, y + 1 + (i - 1) * height, text_color, option[i - 1]);
	}
	int x_tmp = x, y_tmp = y + (option_num - 1) * height;
	mark_bar(x_tmp + 1, y_tmp + 1, width, height, text_color + b_color_light * 16, option[(y_tmp - y) / height]);

}
// Hàm nhập tối đa số lượng cho trước, và "chỉ nhận chữ cái và kí tự @ và dấu chấm "."
std::string my_getline(int max) {
	char ch;
	std::string str = "";
	while (1) {
		if (_kbhit()) {
			ch = _getch();

			if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || ch == '@' || ch == '.' || ch == '-' || ch == '_') {
				if (str.length() != max) {
					str += ch;
					std::cout << char(ch);
				}
			}
			else if (ch == 27) {
				return "-1";
			}
			else if ((ch == 13) && str.length() > 0) {
				break;
			}
			else if (ch == 8) {
				size_t n = str.length();
				if (n > 0) {
					str.erase(n - 1);
					std::cout << "\b \b";
				}
			}
			else if (ch == -32) {
				ch = _getch();
				if (ch == 72) {

				}
				else if (ch == 80) {

				}
				else if (ch == 75) {

				}
				else if (ch == 77) {

				}
			}
		}
	}
	return str;
}
// Hàm nhập tối đa số lượng cho trước, và chỉ nhận số
std::string my_getline_onlyNumber(int max) {
	char ch;
	std::string str = "";
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if ((ch >= '0' && ch <= '9' )|| (ch == '.') || (ch == '-')) {
				if (str.length() != max) {
					str += ch;
					std::cout << char(ch);
				}
			}
			else if (ch == 27)
				return "-1";
			else if ((ch == 13 ) && str.length() > 0) {
				break;
			}
			else if (ch == 8) {
				size_t n = str.length();
				if (n > 0) {
					str.erase(n - 1);
					std::cout << "\b \b";
				}
			}
			else if (ch == -32) {
				ch = _getch();
				if (ch == 72) {

				}
				else if (ch == 80) {

				}
				else if (ch == 75) {

				}
				else if (ch == 77) {

				}
			}
		}

	}
	return str;
}
// Hàm nhập tối đa số lượng cho trước, và "chỉ nhận chữ cái và kí tự @ và dấu chấm "." và space
std::string my_getline_addSpace(int max) {
	char ch;
	std::string str = "";
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || ch == '@' || ch == '.' || ch == ' ') {
				if (str.length() != max) {
					str += ch;
					std::cout << char(ch);
				}
			}
			else if (ch == 27)
				return "-1";
			else if (ch == 13) {
				break;
			}
			else if (ch == 8) {
				size_t n = str.length();
				if (n > 0) {
					str.erase(n - 1);
					std::cout << "\b \b";
				}
			}
			else if (ch == -32) {
				ch = _getch();
				if (ch == 72) {

				}
				else if (ch == 80) {

				}
				else if (ch == 75) {

				}
				else if (ch == 77) {

				}
			}
		}
	}
	return str;
}


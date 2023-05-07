#pragma once
#ifndef MY_GRAPHICS_LIBRARY_H_
#define MY_GRAPHICS_LIBRARY_H_

#include <conio.h>
#include <ctime> 
#include "windows.h"
#include <string>
#include <iostream>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

#define KEY_NONE	-1

//========= lấy tọa độ x của con trỏ hiện tại =======
int whereX();
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY();
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y);
//============= đặt màu cho chữ =========
void SetColor(WORD color);
void SetColor2(int backgound_color, int text_color);
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility);
//======= trả về mã phím người dùng bấm =========
int inputKey();
// Hàm tô màu.
void textcolor(int x);
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height);
// Hàm tự viết
void my_print(int x, int y, int t_color, std::string content);
// Tạo box
void box(int x, int y, int width, int height, int t_color);
// Tạo nhiều box
void n_box(int x, int y, int width, int height, int amount, int t_color);
//Menu của staff
int menu(int x, int y, int width, int height, int amount, std::string option[], int box_color, int text_color, int b_color_light);
void menu_Staff(int x, int y, int width, int height, int amount, std::string option[], int box_color, int text_color, int b_color_light, int option_num);

int enter_again_yes_no(int coordinate_x, int coordinate_y, int width_box, int height_box, int distance, int mark_bar_color, int text_color);
// Hàm nhập tối đa số lượng cho trước, và "chỉ nhận chữ cái và kí tự @ và dấu chấm "."
std::string my_getline(int max);
// Hàm nhập tối đa số lượng cho trước, và chỉ nhận số"
std::string my_getline_onlyNumber(int max);
// Hàm nhập tối đa số lượng cho trước, và "chỉ nhận chữ cái và kí tự @ và dấu chấm "." và space//
std::string my_getline_addSpace(int max);

#endif // !MY_GRAPHICS_LIBRARY_H_



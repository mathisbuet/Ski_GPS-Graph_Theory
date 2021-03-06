//
// Created by mathis on 11/04/2021.
//

/*
 * Source pour les couleurs : https://stackoverflow.com/questions/20608058/c-colour-console-text
 */

#ifndef SKIPISCINE_FONCTION_H
#define SKIPISCINE_FONCTION_H
#include <iostream>
#include <string>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#endif // _WIN32

#define color_black      0
#define color_dark_blue  1
#define color_dark_green 2
#define color_light_blue 3
#define color_dark_red   4
#define color_magenta    5
#define color_orange     6
#define color_light_gray 7
#define color_gray       8
#define color_blue       9
#define color_green     10
#define color_cyan      11
#define color_red       12
#define color_pink      13
#define color_yellow    14
#define color_white     15
void print(const std::string s, const int textcolor, const int backgroundcolor=color_black);

#endif //SKIPISCINE_FONCTION_H

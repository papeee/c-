// curpath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//https://cboard.cprogramming.com/cplusplus-programming/23754-importing-class-dllimport.html
//#pragma comment(lib,"mcpath.lib")
#include "pch.h"
#include <iostream>
#include <windows.system.h>
#include <windows.h>
#ifndef bsolwindow_h
#define bsolwindow_h
#endif
#include <time.h>

//Load the DLL
#define DllImport __declspec(dllimport)
HMODULE lib = LoadLibrary(L"mcpath.dll");

class CurPath {

public:
	CurPath() {
		CallDll();
	}

	~CurPath() {
	}
public:
	void CallDll() {
		typedef void(__stdcall *FUNCPTR)();
		FUNCPTR myfunc = (FUNCPTR)GetProcAddress(lib, "_Directory@0");
		if (!lib) {
			//ERROR
			std::cout << "Could not load library! ";
		}
		else if (myfunc != NULL) {
			time_t t = time(0);
			struct tm ti = { 0 };
			localtime_s(&ti, &t);
			std::cout << "Time: " << ti.tm_hour << ":" << ti.tm_min << "." << ti.tm_sec << std::endl;
			std::cout << "Memory address of DLL: " << &myfunc;
			myfunc();
		}
		FreeLibrary(lib);
	}
};
CurPath curPath;

int main()
{
	curPath.CallDll();
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

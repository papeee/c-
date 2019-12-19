// curpath.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <windows.system.h>
#include <windows.h>
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

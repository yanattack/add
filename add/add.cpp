// add.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#ifndef __ADD
#define __ADD "v1.0"
#endif
///////////////////
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <stdexcept>
#include <vector>
///////////////////
class Console {
public:
	void print(std::string str);
};
void Console::print(std::string str) {
	try {
	std::cout << str << std::endl;
	}
	catch(std::exception ex) {
		std::ofstream DebugMesFile;
		DebugMesFile.open("debug.txt");
		DebugMesFile << ex.what();
		DebugMesFile.close();
	}

}

int polyadd(int count, int x, ...);

int _tmain(int argc, _TCHAR* argv[]) {
	try {
	Console *c = new Console();
	Console O;
	c->print("wmain");
	delete c;
	c = &O;
	}
	catch (std::exception f) {
		MessageBoxA(NULL,LPCSTR("哎呀，出现错误了！"),LPCSTR("错误"),MB_ICONERROR);
	}
	
	
	std::cin.get();
	return 0;
}

int polyadd(int count, int x, ...) {
        char *p = (char *)&x;
        p += sizeof(x);
        int sum = 0;
        int tmp = 1;
        for(int i = 0; i < count; i++)
        {
                sum += *(int *)p * tmp;
                p += sizeof(int);
                tmp *= x;
        }
        return sum;
}

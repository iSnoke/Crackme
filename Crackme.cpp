#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <Tlhelp32.h>
#define debuggers_length    7

bool end = false;


char debuggers[debuggers_length][255] = {
    "cheatengine-x86_64.exe",
    "ollydbg.exe",
    "ida.exe",
    "ida64.exe",
    "radare2.exe",
    "x64dbg.exe",
    "x32dbg.exe"

};

int proccess(char* str){
	HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32 procinfo = {sizeof(PROCESSENTRY32)};

    while (Process32Next(handle,&procinfo)){
        if (!strcmp(procinfo.szExeFile,str)){
            //std::cout << "DEBUGGER\n";
            return 1;

        }
    }
    return 0;
}


int detect_debbuger(){

    for (int debugger=0;debugger <= debuggers_length;debugger++){
        //std::cout << debuggers[debugger] << "\n";
        if (proccess(debuggers[debugger]) == 1){
            return 1;

        }


    	}

    return 0;
}

int main(){
    int _count = 0;
    int count__ = 0;
    char u_[255];
    char p_[255];
    char* user = "Hs42kkpPPks";
    char* pass = "sfwTWwool24";
    while (not end){
        if (_count == 5){
            std::cout << "You have reached the maximum number of attempts\n";
            return 1;

        }
        if (detect_debbuger() == 1){
            std::cout << "Debugger detected\n";
            system("pause > null");
            return 1;
        }
        std::cout << "Write the user: ";
        std::cin >> u_;
        std::cout << "Write the password: ";
        std::cin >> p_;
        if (strcmp(user,u_) == 0 and strcmp(pass,p_) == -0){
                std::cout << "Congrats you resolve this problem!!!!!!\n";
                system("pause > null");
                return 0;


        }

        else{

            std::cout << "User or password incorrect. Try again!!!\n";

        }
        _count += 1;

    }









    system("pause > null");
    return 0;
}

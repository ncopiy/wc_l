#include "terminal.h"
#include <iostream>
#include <fstream>
#include <cstring>

Terminal::Terminal()
{

}

void Terminal::start()
{
    work = true;
    run();
}

void Terminal::run() {
    state current;
    while(work) {
        std::cin >> inputStr;
        current = identifyStr(inputStr);
        process(current);

    }
}

Terminal::state Terminal::identifyStr(const std::__cxx11::string &s) {
    if(s == "help")
        return Terminal::HELP;
    else if(s == "exit")
        return Terminal::EXIT;
    else {
        std::ifstream file(s);
        if(!file) {
            return Terminal::ERROR;
        }
        else {
            return Terminal::CORRECT;
        }
    }
}

void Terminal::process(Terminal::state curState)
{
    switch(curState) {
    case Terminal::CORRECT:
        parseFile();
        break;
    case Terminal::ERROR:
        errorOut();
        break;
    case Terminal::HELP:
        help();
        break;
    case Terminal::EXIT:
        work = false;
        break;
    }
}

void Terminal::help()
{
    std::cout << "Write the path to file to get count of lines.\nWrite \"exit\" to exit the program.\n";
    inputStr = "";
}

void Terminal::errorOut()
{
    std::cout << "Unidentified line. Try again.\n";
    inputStr = "";
}

void Terminal::parseFile()
{
    int result = 0;
    std::ifstream file(inputStr);
    std::string str;
    while(std::getline(file, str)){
        result++;
    }
    std::cout << result << ' ' << inputStr << '\n';
}

#ifndef TERMINAL_H
#define TERMINAL_H
#include <string>

class Terminal
{
public:
    Terminal();

    enum state{ERROR = 0, CORRECT, HELP, EXIT};

    void start();

private:
    void run();
    std::string inputStr;
    bool work;

    state identifyStr(const std::string &s);
    void process(state curState);

    void help();
    void errorOut();
    void parseFile();
};

#endif // TERMINAL_H

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

auto main(int argc, char* argv[]) -> int {

    auto variable = argv[1];
    auto value = argv[2];
    auto oldShell = getenv("SHELL");

    if(variable[0] != '-'){
        setenv(variable, value, 1);
    }else{
        unsetenv(variable + 1);
    }

    char* pointers[] = {oldShell, nullptr};

    execvp(oldShell, pointers);


    return 0;
}

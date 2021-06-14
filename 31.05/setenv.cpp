#include <iostream>
#include <unistd.h>
#include <stdlib.h>

auto main(int argc, char* argv[]) -> int {

    auto zmienna = argv[1];
    auto value = argv[2];
    auto oldShell = getenv("SHELL");

    setenv(zmienna, value, 1);

    char* pointers[] = {oldShell, nullptr};

    execvp(oldShell, pointers);


    return 0;
}

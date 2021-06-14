#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

auto main(int argc, char* argv[]) -> int {

    auto zmienna = argv[1];
    auto value = argv[2];
    auto oldShell = getenv("SHELL");

    setenv(zmienna, value, 1);

    char* pointers[] = {oldShell, nullptr};

    execvp(oldShell, pointers);


    return 0;
}

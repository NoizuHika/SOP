#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

auto main(int argc, char *argv[]) -> int {

    auto zmienna = argv[1];

    auto resoult = getenv(zmienna);

    *getenv(const char *name);

    if(resoult != nullptr){
        std::cout<< resoult << '\n';
    }

    return 0;
}

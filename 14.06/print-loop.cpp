#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

char buff[64] = {0};

void signalHandler(int x){
    auto pathname = "plik.txt";
    auto a = open(pathname, 0);

    read(a, buff, 64);
    close(a);
}

auto main(int argc, char* argv[]) -> int {

    auto pathname = "plik.txt";
    auto a = open(pathname, 0);

    read(a, buff, 64);
    close(a);

    signal(SIGHUP, signalHandler);

    while(true){
        std::cout << buff << "\n";
        sleep(1);
    }

    return 0;
}

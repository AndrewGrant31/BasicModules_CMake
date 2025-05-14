#include <iostream>
#include <string>
#include <memory>
#include <print>

import Run;

auto main(int argc, char* argv[]) -> int
{
    auto runApp{std::make_unique<Run::App>(
        argc == 2 ?
        std::string{argv[1]} :
        std::string{}
    )};

    std::println("{}", runApp->Get());
    return 0;
}
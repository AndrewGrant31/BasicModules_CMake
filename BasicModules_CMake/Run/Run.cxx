module;

#include <string>
#include <memory>

export module Run;

import Input;
import Hello;

export namespace Run
{
    class App
    {
        private:
            std::unique_ptr<Input::Is_Valid> input;
            std::unique_ptr<Hello::HelloWorld> hello;
        public:
            explicit App(const std::string& _) :
                input{std::make_unique<Input::Is_Valid>(_)},
                hello{std::make_unique<Hello::HelloWorld>(input->ToString())}
            {

            }

            auto Get()
            {
                return hello->ToString();
            }
    };
}
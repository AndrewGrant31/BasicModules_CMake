module;

#include <string>
#include <memory>
#include <optional>

export module Hello;

import HelloVariables;
import Who;

export namespace Hello
{
    class HelloWorld
    {
        private:
            std::unique_ptr<Variables::Who> who;

            auto Join(auto ...args)
            {
                return (... + args);
            }

            auto AddExclamation(const std::string& _)
            {
                return _.ends_with(std::string{Variables::Exclamation()}) ? _ : Join(_, Variables::Exclamation());
            }

            auto Set(const std::string& _ = std::string{})
            {
                return _.empty() ? Variables::World() : _;
            }

            auto ConstructGreetings()
            {
                return Join(Variables::Hello(), AddExclamation(who->Get()));
            }

        public:

            explicit HelloWorld(const std::optional<std::string>& _ = std::nullopt) :
                who{ std::make_unique<Variables::Who>( Set(_.value_or(std::string{})))}
            {

            }

            auto ToString()
            {
                return ConstructGreetings();
            }
    };
}
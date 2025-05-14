module;

#include <string>
#include <memory>
#include <optional>

export module Who;

import HelloVariables;

export namespace Variables
{
    class Who
    {
        private:
            std::string value{};

            auto Set(const std::string& _)
            {
                return _.empty() ? Variables::World() : _;
            }
        public:
            explicit Who(const std::optional<std::string>& _ = std::nullopt) :
                value{Set(_.value_or(std::string{}))}
                {

                }

            auto Get()
            {
                return value;
            }
    };
}



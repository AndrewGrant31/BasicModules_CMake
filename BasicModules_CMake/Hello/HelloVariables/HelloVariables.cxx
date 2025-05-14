module;

#include <string>

export module HelloVariables;

namespace Strings
{
    const std::string exclamation_{"!"};
    const std::string hello_{"Hello "};
    const std::string world_{"World!"};
} // namespace Characters

export namespace Variables
{
    auto Exclamation()
    {
        return Strings::exclamation_;
    }

    auto Hello()
    {
        return Strings::hello_;
    }

    auto World()
    {
        return Strings::world_;
    }
}
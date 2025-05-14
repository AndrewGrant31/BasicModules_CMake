module;

#include <memory>

export module Variables;

import Hidden;

namespace Private
{
    std::unique_ptr<Hidden::Object> list{std::make_unique<Hidden::Object>()};
}

export namespace Variables
{
    auto Acceptable( auto& _)
    {
        return Private::list->Contains(_);
    }

    auto Compare(auto& first_, auto& second_)
    {
        return Private::list->Compare(first_, second_);
    }
}
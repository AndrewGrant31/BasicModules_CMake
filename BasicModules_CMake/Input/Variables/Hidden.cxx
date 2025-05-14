module;

#include <list>
#include <algorithm>

export module Hidden;

namespace Strings
{
                char apostrophe{'\''};
            char dot{'.'};
            char hyphen{'-'};
            char space{' '};
}

export namespace Hidden
{
    class Object
    {
        private:
            std::list<char> theList
            {
                Strings::apostrophe,
                Strings::dot,
                Strings::hyphen,
                Strings::space
            };

        public:
            auto Contains(auto& _)
            {
                // return std::find(theList.begin(), theList.end(), _) != theList.end();
                return std::find(std::begin(theList), 
                    std::end(theList), _) != std::end(theList);
            }

            auto Compare(auto& first_, auto& second_)
            {
                if(first_ == Strings::dot and second_ == Strings::space)
                    return false;
                return Contains(first_) == Contains(second_);
            }
    };
}
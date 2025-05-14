module;

#include <string>
#include <memory>
#include <type_traits>
#include <concepts>
#include <algorithm>
#include <optional>

export module Input;

import Variables;

export namespace Input
{
    class Is_Valid
    {
        private:
            std::string value{};

            auto Validate( const std::string& _ )
            {
                std::optional<char> previous{};

                if(not _.empty())
                {
                    std::optional<char> previous{};
                    for (auto& c : _)
				{
					switch (std::isalpha(c))
					{
					case true:
						if (previous.has_value())
							previous.reset();
						break;
					case false:
 						if (Variables::Acceptable(c))
						{
                            if(previous.has_value())
							{
                                if ( Variables::Compare ( previous.value ( ), c ) )
                                {
                                    return std::string {};
                                }
                                else
                                {
                                    previous.reset ( );
                                    previous.emplace ( c );
                                    break;
                                }							                    break;
							}							
						}
						 else
						 	return std::string{};
					}
                        
				}
                }
                return _;
            }

        public:
        explicit Is_Valid(const std::string& _) :
            value{Validate(_)}
        {

        }

        auto ToString()
        {
            return value;
        }

    };
}

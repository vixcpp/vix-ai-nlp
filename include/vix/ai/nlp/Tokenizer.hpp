#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace vix::ai::nlp
{

    struct Tokenizer
    {
        std::vector<std::string> tokenize(const std::string &s) const
        {
            std::vector<std::string> toks;
            std::istringstream iss(s);
            for (std::string t; iss >> t;)
                toks.push_back(std::move(t));
            return toks;
        }
    };

} // namespace vix::ai::nlp

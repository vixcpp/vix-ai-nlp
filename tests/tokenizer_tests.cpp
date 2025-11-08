#include <cassert>
#include <vix/ai/nlp/Tokenizer.hpp>

using namespace vix::ai::nlp;

int main()
{
    Tokenizer tok;
    auto v = tok.tokenize("hello world  from  vix");
    assert(v.size() == 4);
    assert(v[0] == "hello");
    assert(v[3] == "vix");
    (void)v; // silence unused in Release
    return 0;
}

#include <cassert>
#include <string>
#include <vix/ai/nlp/Pipeline.hpp>

using namespace vix::ai::nlp;

int main()
{
    Pipeline p;
    std::string s = "This is a test.";
    auto out = p.summarize(s);
    assert(out == s);
    (void)out;
    return 0;
}

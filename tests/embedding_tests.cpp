#include <cassert>
#include <vix/ai/nlp/Embedding.hpp>

using namespace vix::ai::nlp;

int main()
{
    Embedding emb;
    auto e = emb.encode("abcd");
    assert(e.size() == 1);
    assert(e[0] == 4.0f);
    (void)e;
    return 0;
}

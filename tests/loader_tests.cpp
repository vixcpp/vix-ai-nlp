#include <cassert>
#include <vix/ai/nlp/ModelLoader.hpp>

using namespace vix::ai::nlp;

int main()
{
    ModelLoader ml;
    bool ok = ml.load("/models/placeholder.gguf");
    assert(ok);
    (void)ok;
    return 0;
}

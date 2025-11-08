cmake_minimum_required(VERSION 3.20)

#[[
Vix.AI NLP — assert-based tests (header-only)
Each test is a tiny executable registered with CTest.
]]

add_executable(vix_ai_nlp_test_tokenizer tokenizer_tests.cpp)
target_link_libraries(vix_ai_nlp_test_tokenizer PRIVATE Vix::AI::nlp)
target_compile_features(vix_ai_nlp_test_tokenizer PRIVATE cxx_std_20)
# keep asserts in Release as well, optional:
# target_compile_definitions(vix_ai_nlp_test_tokenizer PRIVATE NDEBUG=0)
add_test(NAME nlp_tokenizer COMMAND vix_ai_nlp_test_tokenizer)

add_executable(vix_ai_nlp_test_embedding embedding_tests.cpp)
target_link_libraries(vix_ai_nlp_test_embedding PRIVATE Vix::AI::nlp)
target_compile_features(vix_ai_nlp_test_embedding PRIVATE cxx_std_20)
add_test(NAME nlp_embedding COMMAND vix_ai_nlp_test_embedding)

add_executable(vix_ai_nlp_test_pipeline pipeline_tests.cpp)
target_link_libraries(vix_ai_nlp_test_pipeline PRIVATE Vix::AI::nlp)
target_compile_features(vix_ai_nlp_test_pipeline PRIVATE cxx_std_20)
add_test(NAME nlp_pipeline COMMAND vix_ai_nlp_test_pipeline)

add_executable(vix_ai_nlp_test_loader loader_tests.cpp)
target_link_libraries(vix_ai_nlp_test_loader PRIVATE Vix::AI::nlp)
target_compile_features(vix_ai_nlp_test_loader PRIVATE cxx_std_20)
add_test(NAME nlp_loader COMMAND vix_ai_nlp_test_loader)

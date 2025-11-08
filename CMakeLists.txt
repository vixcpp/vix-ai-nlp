cmake_minimum_required(VERSION 3.20)

project(vix-ai-nlp
  VERSION 0.1.0
  DESCRIPTION "Vix.AI NLP: tokenizers, embeddings, pipelines, model loading"
  LANGUAGES CXX)

option(VIX_AI_NLP_BUILD_TESTS "Build vix-ai-nlp tests" ON)
option(VIX_AI_NLP_INSTALL     "Install vix-ai-nlp targets" ON)
option(VIX_AI_NLP_WARNINGS    "Enable extra warnings" ON)

# Header-only for now (easy to extend to sources later)
add_library(vix_ai_nlp INTERFACE)
add_library(Vix::AI::nlp ALIAS vix_ai_nlp)

target_include_directories(vix_ai_nlp INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_compile_features(vix_ai_nlp INTERFACE cxx_std_20)

# Propager version (optionnel si umbrella fournit VIX_AI_VERSION)
if (DEFINED VIX_AI_VERSION)
  set(PROJECT_VERSION ${VIX_AI_VERSION})
endif()
target_compile_definitions(vix_ai_nlp INTERFACE VIX_AI_NLP_VERSION="${PROJECT_VERSION}")

if (VIX_AI_NLP_WARNINGS)
  if (MSVC)
    target_compile_options(vix_ai_nlp INTERFACE /W4 /permissive-)
  else()
    target_compile_options(vix_ai_nlp INTERFACE -Wall -Wextra -Wpedantic)
  endif()
endif()

# Tests
if (VIX_AI_NLP_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# Install
if (VIX_AI_NLP_INSTALL)
  include(GNUInstallDirs)
  include(CMakePackageConfigHelpers)

  install(TARGETS vix_ai_nlp
          EXPORT vix_ai_nlpTargets)

  install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

  install(EXPORT vix_ai_nlpTargets
          FILE vix_ai_nlpTargets.cmake
          NAMESPACE Vix::AI::
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nlp)

  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nlpConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nlpConfig.cmake
"include(\"\${CMAKE_CURRENT_LIST_DIR}/vix_ai_nlpTargets.cmake\")\n")

  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nlpConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_nlpConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nlp)
endif()

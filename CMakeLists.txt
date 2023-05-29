cmake_minimum_required(VERSION 3.14)

project(wasm-ai-alpha-beta)
add_definitions(-std=c++17)
set (CMAKE_CXX_STANDARD 17)
add_subdirectory(nichess-cpp)

add_executable(ai wrapping.cpp nichess_wrapper.cpp agent1.cpp)
target_link_libraries(ai nichess)

set(CMAKE_EXECUTABLE_SUFFIX ".mjs")

set_target_properties(ai PROPERTIES LINK_FLAGS "-o ai.mjs --pre-js locateFile.js -s ENVIRONMENT='web' -s EXPORT_NAME='createModule' -s USE_ES6_IMPORT_META=0 -s EXPORTED_FUNCTIONS='[\"_computeAIAction\"]' -s EXPORTED_RUNTIME_METHODS='[\"ccall\", \"cwrap\"]' -s ALLOW_MEMORY_GROWTH=1 -O3 -s STANDALONE_WASM --no-entry")

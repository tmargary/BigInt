add_library(BigInt BigInt.cpp)

target_link_libraries(BigInt PUBLIC utils)

target_include_directories(BigInt PUBLIC include)


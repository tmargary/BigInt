add_subdirectory(BigInt)
add_subdirectory(utils)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE BigInt)
target_link_libraries(main PRIVATE utils)

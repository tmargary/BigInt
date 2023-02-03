find_package(GTest REQUIRED)

add_executable(BigIntTest BigIntTest.cpp)

target_link_libraries(BigIntTest
 PRIVATE
  GTest::GTest
  BigInt)

add_test(BigIntGTest BigIntTest)

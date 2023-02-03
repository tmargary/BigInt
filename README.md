# BigInt
 C++ BigInt implementation 

### Installation
1. `git clone https://github.com/tmargary/BigInt`
2. `cd BigInt`
3. `cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake`
4. `cmake --build ./build`
4. `./build/tests/BigIntTest`

# Usage
```
BigInt a("123456789");
BigInt b("-987654321");
result = (a * b).toString(); // "-121932631112635269"
```

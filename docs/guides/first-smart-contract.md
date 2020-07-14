### Building your first smart contract
```c++
#include <gstio/gstio.hpp>
#include <gstio/name.hpp>

class [[gstio::contract]] hello : public gstio::contract {
   public:
      using gstio::contract::contract;

      [[gstio::action]]
      void hi(gstio::name nm) {
         gstio::print_f("Hello, %\n", nm);
      }
};
```

- Navigate to the hello folder in examples (./examples/hello).
- You should then see the hello.cpp file
- Now run the compiler
```sh
$ gstio-cpp -abigen hello.cpp -o hello.wasm
```
- Or with CMake
```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```
This will generate two files:
* The compiled binary wasm (hello.wasm)
* The generated ABI file (hello.abi)

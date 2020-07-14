#include <gstio/gstio.hpp>
#include <gstio/tester.hpp>

using namespace gstio::native;

GSTIO_TEST_BEGIN(print_test)
   CHECK_PRINT("27", [](){ gstio::print((uint8_t)27); });
   CHECK_PRINT("34", [](){ gstio::print((int)34); });
   CHECK_PRINT([](std::string s){return s[0] == 'a';},  [](){ gstio::print((char)'a'); });
   CHECK_PRINT([](std::string s){return s[0] == 'b';},  [](){ gstio::print((int8_t)'b'); });
   CHECK_PRINT("202", [](){ gstio::print((unsigned int)202); });
   CHECK_PRINT("-202", [](){ gstio::print((int)-202); });
   CHECK_PRINT("707", [](){ gstio::print((unsigned long)707); });
   CHECK_PRINT("-707", [](){ gstio::print((long)-707); });
   CHECK_PRINT("909", [](){ gstio::print((unsigned long long)909); });
   CHECK_PRINT("-909", [](){ gstio::print((long long)-909); });
   CHECK_PRINT("404", [](){ gstio::print((uint32_t)404); });
   CHECK_PRINT("-404", [](){ gstio::print((int32_t)-404); });
   CHECK_PRINT("404000000", [](){ gstio::print((uint64_t)404000000); });
   CHECK_PRINT("-404000000", [](){ gstio::print((int64_t)-404000000); });
   CHECK_PRINT("0x0066000000000000", [](){ gstio::print((uint128_t)102); });
   CHECK_PRINT("0xffffff9affffffffffffffffffffffff", [](){ gstio::print((int128_t)-102); });
GSTIO_TEST_END

int main(int argc, char** argv) {
   bool verbose = false;
   if( argc >= 2 && std::strcmp( argv[1], "-v" ) == 0 ) {
      verbose = true;
   }
   silence_output(!verbose);

   GSTIO_TEST(print_test);
   return has_failed();
}

/**
 *  @file
 *  @copyright defined in gstio.cdt/LICENSE.txt
 */

#include <gstio/gstio.hpp>
#include <gstio/rope.hpp>
#include <gstio/tester.hpp>
#include <string>

using namespace gstio::native;

GSTIO_TEST_BEGIN(rope_test)
   gstio::rope r("test string 0");
   r += ", test string 1";
   r += ", test string 2";
   r += ", test string 3";
   r += ", test string 4";
   r += ", test string 5";
   r += ", test string 6";
   r += ", test string 7";

   std::string s("test string 0");
   s += ", test string 1";
   s += ", test string 2";
   s += ", test string 3";
   s += ", test string 4";
   s += ", test string 5";
   s += ", test string 6";
   s += ", test string 7";

   gstio::rope r2 = r + gstio::rope("lhs") + gstio::rope("rhs") + "some string";
   std::string s2 = s + std::string("lhs") + std::string("rhs") + "some string";

   r2 += gstio::rope("rvalue +=");
   s2 += std::string("rvalue +=");

   r2 = r2 + r2;
   s2 = s2 + s2;

   r2 += "the end";
   s2 += "the end";

   gstio::rope r3(r2);
   std::string s3(s2);

   REQUIRE_EQUAL(s.compare(std::string(r.c_str())), 0);
   REQUIRE_EQUAL(s2.compare(std::string(r2.c_str())), 0);
   REQUIRE_EQUAL(s3.compare(std::string(r3.c_str())), 0);

   REQUIRE_EQUAL(s.length(),  r.length());
   REQUIRE_EQUAL(s2.length(), r2.length());
   REQUIRE_EQUAL(s3.length(), r3.length());

   for (int i=0; i < s.length(); i++) {
      REQUIRE_EQUAL(s[i], r[i]);
   }

   for (int i=0; i < s2.length(); i++) {
      REQUIRE_EQUAL(s2[i], r2[i]);
   }

   for (int i=0; i < s3.length(); i++) {
      REQUIRE_EQUAL(s3[i], r3[i]);
   }
GSTIO_TEST_END

int main(int argc, char** argv) {
   bool verbose = false;
   if( argc >= 2 && std::strcmp( argv[1], "-v" ) == 0 ) {
      verbose = true;
   }
   silence_output(!verbose);

   GSTIO_TEST(rope_test);
   return has_failed();
}

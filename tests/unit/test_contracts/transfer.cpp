#include <gstio/gstio.hpp>
#include <gstio/asset.hpp>

using namespace gstio;

CONTRACT transfer_contract : public contract {
   public:
      using contract::contract;

      ACTION transfer(name from, name to, asset quantity, std::string memo) {
         require_recipient(from);
         print_f("transfered : % -> % ? % (%)\n", from, to, quantity, memo);
      }

      ACTION transfer2(name from, name to, asset quantity, std::string memo) {
         require_recipient(from);
         print_f("transfered : % -> % ? % (%)\n", from, to, quantity, memo);
      }

      ACTION transfer3(name from, name to, asset quantity, std::string memo) {
         require_recipient(from);
         print_f("transfered : % -> % ? % (%)\n", from, to, quantity, memo);
      }
};

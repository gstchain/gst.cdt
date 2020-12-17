#pragma once

#include "../../core/gstio/name.hpp"
#include "../../core/gstio/datastream.hpp"


/**
 * @defgroup contract Contract
 * @ingroup contracts
 * @ingroup types
 * @brief Defines contract type which is %base class for every GSTIO contract
 */

/**
 * Helper macros to reduce the verbosity for common contracts
 * @ingroup contract
 */
#define CONTRACT class [[gstio::contract]]
#define ACTION   [[gstio::action]] void
#define TABLE struct [[gstio::table]]

namespace gstio {

/**
 * %Base class for GSTIO contract.
 *
 * @ingroup contract
 * @details %Base class for GSTIO contract. %A new contract should derive from this class, so it can make use of GSTIO_ABI macro.
 */

class contract {
   public:
      /**
       * Construct a new contract given the contract name
       *
       * @param self - The name of the account this contract is deployed on
       * @param first_receiver - The account the incoming action was first received at.
       * @param ds - The datastream used
       */
      contract( uint64_t self, uint64_t first_receiver, datastream<const char*> ds ):_self(self),_first_receiver(first_receiver),_ds(ds) {}

      /**
       *
       * Get this contract name
       *
       * @return name - The name of this contract
       */
      inline uint64_t get_self()const { return _self; }

      /**
       * The first_receiver name of the action this contract is processing.
       *
       * @return name - The first_receiver name of the action this contract is processing.
       */
      [[deprecated]]
      inline uint64_t get_code()const { return _first_receiver; }

      /**
       * The account the incoming action was first received at.
       *
       * @return name - The first_receiver name of the action this contract is processing.
       */
      inline uint64_t get_first_receiver()const { return _first_receiver; }

      /**
       * Get the datastream for this contract
       *
       * @return datastream<const char*> - The datastream for this contract
       */
      inline datastream<const char*>& get_datastream() { return _ds; }

      /**
       * Get the datastream for this contract
       *
       * @return datastream<const char*> - The datastream for this contract
       */
      inline const datastream<const char*>& get_datastream()const { return _ds; }

   protected:
      /**
       * The name of the account this contract is deployed on.
       */
      uint64_t _self;

      /**
       * The account the incoming action was first received at.
       */
      uint64_t _first_receiver;

      /**
       * The datastream for this contract
       */
      datastream<const char*> _ds = datastream<const char*>(nullptr, 0);
};
}

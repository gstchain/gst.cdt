/**
 *  @file
 *  @copyright defined in gst/LICENSE
 */
#pragma once
#include "../../core/gstio/time.hpp"
#include "../../core/gstio/check.hpp"

namespace gstio {
  namespace internal_use_do_not_use {
    extern "C" {
      __attribute__((gstio_wasm_import, noreturn))
      void gstio_exit( int32_t code );
    }
  }

  /**
   *  @addtogroup system System
   *  @ingroup contracts
   *  @brief Defines time related functions and gstio_exit
   */

   /**
    *  This method will abort execution of wasm without failing the contract. This is used to bypass all cleanup / destructors that would normally be called.
    *
    *  @ingroup system
    *  @param code - the exit code
    *  Example:
    *
    *  @code
    *  gstio_exit(0);
    *  gstio_exit(1);
    *  gstio_exit(2);
    *  gstio_exit(3);
    *  @endcode
    */
   inline void gstio_exit( int32_t code ) {
     internal_use_do_not_use::gstio_exit(code);
   }

   /**
   *  Returns the time in microseconds from 1970 of the current block as a time_point
   *
   *  @ingroup system
   *  @return time in microseconds from 1970 of the current block as a time_point
   */
   time_point current_time_point();

   /**
   *  Returns the time in microseconds from 1970 of the current block as a block_timestamp
   *
   *  @ingroup system
   *  @return time in microseconds from 1970 of the current block as a block_timestamp
   */
   block_timestamp current_block_time();
}

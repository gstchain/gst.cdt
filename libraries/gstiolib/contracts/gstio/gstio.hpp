/**
 *  @file
 *  @copyright defined in gst/LICENSE
 */
#pragma once
#include "action.hpp"
#include "../../core/gstio/print.hpp"
#include "multi_index.hpp"
#include "dispatcher.hpp"
#include "contract.hpp"

#ifndef GSTIO_NATIVE
static_assert( sizeof(long) == sizeof(int), "unexpected size difference" );
#endif

/**
 * @defgroup core Core API
 * @brief C++ Core API for chain-agnostic smart-contract functionality
 */

 /**
  * @defgroup contracts Contracts API
  * @brief C++ Contracts API for chain-dependent smart-contract functionality
  */

/**
 * @defgroup types Types
 * @brief C++ Types API for data layout of data-structures available for the GSTIO platform
 */
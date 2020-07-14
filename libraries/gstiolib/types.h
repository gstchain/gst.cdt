/**
 *  @file
 *  @copyright defined in gst/LICENSE
 */
#pragma once

#include <stdint.h>
#include <wchar.h>

#warning "<gstiolib/types.h> is deprecated use <gstio/types.h>. If you are using C++ the .h header files will be removed from inclusion entirely in v1.7.0"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @addtogroup c_types
 *  @brief Specifies builtin types, typedefs and aliases
 *  @{
 */

/**
 * Macro to align/overalign a type to ensure calls to intrinsics with pointers/references are properly aligned
 */

/* macro to align/overalign a type to ensure calls to intrinsics with pointers/references are properly aligned */
#define ALIGNED(X) __attribute__ ((aligned (16))) X

typedef uint64_t capi_name;

/**
 * GSTIO Public Key. It is 34 bytes.
 */
struct capi_public_key {
   char data[34];
};

/**
 * GSTIO Signature. It is 66 bytes.
 */
struct capi_signature {
   uint8_t data[66];
};

/**
 * 256-bit hash
 */
struct ALIGNED(capi_checksum256) {
   uint8_t hash[32];
};

/**
 * 160-bit hash
 */
struct ALIGNED(capi_checksum160) {
   uint8_t hash[20];
};

/**
 * 512-bit hash
 */
struct ALIGNED(capi_checksum512) {
   uint8_t hash[64];
};

/// @}

#ifdef __cplusplus
} /// extern "C"
#endif

/**
 *  @file
 *  @copyright defined in gst/LICENSE
 */
#pragma once

#include "fixed_bytes.hpp"
#include "varint.hpp"
#include "serialize.hpp"

#include <array>

namespace gstio {

   /**
    *  @defgroup public_key Public Key Type
    *  @ingroup core
    *  @ingroup types
    *  @brief Specifies public key type
    */

   /**
    *  GSTIO Public Key
    *
    *  @ingroup public_key
    */
   struct public_key {
      /**
       *  Type of the public key, could be either K1 or R1
       */
      unsigned_int        type;

      /**
       *  Bytes of the public key
       */
      std::array<char,33> data;

      /// @cond OPERATORS

      friend bool operator == ( const public_key& a, const public_key& b ) {
        return std::tie(a.type,a.data) == std::tie(b.type,b.data);
      }
      friend bool operator != ( const public_key& a, const public_key& b ) {
        return std::tie(a.type,a.data) != std::tie(b.type,b.data);
      }

      /// @cond
   };

   /// @cond IMPLEMENTATIONS

   /**
    *  Serialize an gstio::public_key into a stream
    *
    *  @ingroup public_key
    *  @param ds - The stream to write
    *  @param pubkey - The value to serialize
    *  @tparam DataStream - Type of datastream buffer
    *  @return DataStream& - Reference to the datastream
    */
   template<typename DataStream>
   inline DataStream& operator<<(DataStream& ds, const gstio::public_key& pubkey) {
      ds << pubkey.type;
      ds.write( pubkey.data.data(), pubkey.data.size() );
      return ds;
   }

   /**
    *  Deserialize an gstio::public_key from a stream
    *
    *  @ingroup public_key
    *  @param ds - The stream to read
    *  @param pubkey - The destination for deserialized value
    *  @tparam DataStream - Type of datastream buffer
    *  @return DataStream& - Reference to the datastream
    */
   template<typename DataStream>
   inline DataStream& operator>>(DataStream& ds, gstio::public_key& pubkey) {
      ds >> pubkey.type;
      ds.read( pubkey.data.data(), pubkey.data.size() );
      return ds;
   }

   /// @endcond

   /**
    *  @defgroup signature Signature
    *  @ingroup core
    *  @ingroup types
    *  @brief Specifies signature type
    */

   /**
    *  GSTIO Signature
    *
    *  @ingroup signature
    */
   struct signature {

      /**
       *  Type of the signature, could be either K1 or R1
       */
      unsigned_int        type;

      /**
       *  Bytes of the signature
       */
      std::array<char,65> data;

      /// @cond OPERATORS

      friend bool operator == ( const signature& a, const signature& b ) {
        return std::tie(a.type,a.data) == std::tie(b.type,b.data);
      }
      friend bool operator != ( const signature& a, const signature& b ) {
        return std::tie(a.type,a.data) != std::tie(b.type,b.data);
      }

      /// @endcond
   };

   /// @cond IMPLEMENTATIONS

   /**
    *  Serialize an gstio::signature into a stream
    *
    *  @param ds - The stream to write
    *  @param sig - The value to serialize
    *  @tparam DataStream - Type of datastream buffer
    *  @return DataStream& - Reference to the datastream
    */
   template<typename DataStream>
   inline DataStream& operator<<(DataStream& ds, const gstio::signature& sig) {
      ds << sig.type;
      ds.write( sig.data.data(), sig.data.size() );
      return ds;
   }

   /**
    *  Deserialize an gstio::signature from a stream
    *
    *  @param ds - The stream to read
    *  @param sig - The destination for deserialized value
    *  @tparam DataStream - Type of datastream buffer
    *  @return DataStream& - Reference to the datastream
    */
   template<typename DataStream>
   inline DataStream& operator>>(DataStream& ds, gstio::signature& sig) {
      ds >> sig.type;
      ds.read( sig.data.data(), sig.data.size() );
      return ds;
   }

   /// @endcond

   /**
    *  @defgroup crypto Crypto
    *  @ingroup core
    *  @brief Defines API for calculating and checking hashes
    */

   /**
    *  Tests if the SHA256 hash generated from data matches the provided digest.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @param hash - digest to compare to
    *  @note This method is optimized to a NO-OP when in fast evaluation mode.
    */
   void assert_sha256( const char* data, uint32_t length, const gstio::checksum256& hash );

   /**
    *  Tests if the SHA1 hash generated from data matches the provided digest.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @param hash - digest to compare to
    *  @note This method is optimized to a NO-OP when in fast evaluation mode.
    */
   void assert_sha1( const char* data, uint32_t length, const gstio::checksum160& hash );

   /**
    *  Tests if the SHA512 hash generated from data matches the provided digest.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @param hash - digest to compare to
    *  @note This method is optimized to a NO-OP when in fast evaluation mode.
    */
   void assert_sha512( const char* data, uint32_t length, const gstio::checksum512& hash );

   /**
    *  Tests if the RIPEMD160 hash generated from data matches the provided digest.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @param hash - digest to compare to
    */
   void assert_ripemd160( const char* data, uint32_t length, const gstio::checksum160& hash );

   /**
    *  Hashes `data` using SHA256.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @return gstio::checksum256 - Computed digest
    */
   gstio::checksum256 sha256( const char* data, uint32_t length );

   /**
    *  Hashes `data` using SHA1.
    *
    *  @ingroup crypto
    *
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @return gstio::checksum160 - Computed digest
    */
   gstio::checksum160 sha1( const char* data, uint32_t length );

   /**
    *  Hashes `data` using SHA512.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @return gstio::checksum512 - Computed digest
    */
   gstio::checksum512 sha512( const char* data, uint32_t length );

   /**
    *  Hashes `data` using RIPEMD160.
    *
    *  @ingroup crypto
    *  @param data - Data you want to hash
    *  @param length - Data length
    *  @return gstio::checksum160 - Computed digest
    */
   gstio::checksum160 ripemd160( const char* data, uint32_t length );

   /**
    *  Calculates the public key used for a given signature on a given digest.
    *
    *  @ingroup crypto
    *  @param digest - Digest of the message that was signed
    *  @param sig - Signature
    *  @return gstio::public_key - Recovered public key
    */
   gstio::public_key recover_key( const gstio::checksum256& digest, const gstio::signature& sig );

   /**
    *  Tests a given public key with the recovered public key from digest and signature.
    *
    *  @ingroup crypto
    *  @param digest - Digest of the message that was signed
    *  @param sig - Signature
    *  @param pubkey - Public key
    */
   void assert_recover_key( const gstio::checksum256& digest, const gstio::signature& sig, const gstio::public_key& pubkey );
}

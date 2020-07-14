#pragma once

/**
 * Define specific things for the gstio system
 */

extern "C" {
   void gstio_assert(unsigned int, const char*);
   void __cxa_pure_virtual() { gstio_assert(false, "pure virtual method called"); }
}

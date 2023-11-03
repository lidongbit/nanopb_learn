/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.9 at Fri Nov  3 17:32:08 2023. */

#include "var_monitor_data.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t VarMonitorData_fields[4] = {
    PB_FIELD(  1, INT32   , REQUIRED, STATIC  , FIRST, VarMonitorData, len, len, 0),
    PB_FIELD(  2, INT32   , REQUIRED, STATIC  , OTHER, VarMonitorData, arr_len, len, 0),
    PB_FIELD(  3, MESSAGE , REPEATED, CALLBACK, OTHER, VarMonitorData, item, arr_len, &VarMonitorData_Array_fields),
    PB_LAST_FIELD
};

const pb_field_t VarMonitorData_Array_fields[2] = {
    PB_FIELD(  1, DOUBLE  , REPEATED, CALLBACK, FIRST, VarMonitorData_Array, data, data, 0),
    PB_LAST_FIELD
};


/* On some platforms (such as AVR), double is really float.
 * These are not directly supported by nanopb, but see example_avr_double.
 * To get rid of this error, remove any double fields from your .proto.
 */
PB_STATIC_ASSERT(sizeof(double) == 8, DOUBLE_MUST_BE_8_BYTES)

/* @@protoc_insertion_point(eof) */
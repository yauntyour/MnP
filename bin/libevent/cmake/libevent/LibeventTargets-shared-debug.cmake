#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libevent::core" for configuration "Debug"
set_property(TARGET libevent::core APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libevent::core PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/libevent_core.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libevent_core.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS libevent::core )
list(APPEND _IMPORT_CHECK_FILES_FOR_libevent::core "${_IMPORT_PREFIX}/lib/libevent_core.dll.a" "${_IMPORT_PREFIX}/lib/libevent_core.dll" )

# Import target "libevent::extra" for configuration "Debug"
set_property(TARGET libevent::extra APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libevent::extra PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/libevent_extra.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libevent_extra.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS libevent::extra )
list(APPEND _IMPORT_CHECK_FILES_FOR_libevent::extra "${_IMPORT_PREFIX}/lib/libevent_extra.dll.a" "${_IMPORT_PREFIX}/lib/libevent_extra.dll" )

# Import target "libevent::openssl" for configuration "Debug"
set_property(TARGET libevent::openssl APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libevent::openssl PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/libevent_openssl.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libevent_openssl.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS libevent::openssl )
list(APPEND _IMPORT_CHECK_FILES_FOR_libevent::openssl "${_IMPORT_PREFIX}/lib/libevent_openssl.dll.a" "${_IMPORT_PREFIX}/lib/libevent_openssl.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

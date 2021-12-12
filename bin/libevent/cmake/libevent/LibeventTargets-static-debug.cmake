#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libevent::core" for configuration "Debug"
set_property(TARGET libevent::core APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libevent::core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libevent_core.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS libevent::core )
list(APPEND _IMPORT_CHECK_FILES_FOR_libevent::core "${_IMPORT_PREFIX}/lib/libevent_core.a" )

# Import target "libevent::extra" for configuration "Debug"
set_property(TARGET libevent::extra APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libevent::extra PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libevent_extra.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS libevent::extra )
list(APPEND _IMPORT_CHECK_FILES_FOR_libevent::extra "${_IMPORT_PREFIX}/lib/libevent_extra.a" )

# Import target "libevent::openssl" for configuration "Debug"
set_property(TARGET libevent::openssl APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libevent::openssl PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libevent_openssl.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS libevent::openssl )
list(APPEND _IMPORT_CHECK_FILES_FOR_libevent::openssl "${_IMPORT_PREFIX}/lib/libevent_openssl.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

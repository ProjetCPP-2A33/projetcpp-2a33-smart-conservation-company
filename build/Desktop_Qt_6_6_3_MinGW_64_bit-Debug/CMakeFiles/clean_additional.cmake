# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\mariem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\mariem_autogen.dir\\ParseCache.txt"
  "mariem_autogen"
  )
endif()

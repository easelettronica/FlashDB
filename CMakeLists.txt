include_guard(GLOBAL)
message("Flash DB library component is included.")

set(FLASH_DB_SOURCE_FILES_LIST 
    "${CMAKE_CURRENT_LIST_DIR}/src/fdb_kvdb.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/fdb_tsdb.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/fdb_utils.c"
    "${CMAKE_CURRENT_LIST_DIR}/src/fdb.c"
    "${CMAKE_CURRENT_LIST_DIR}/port/fal/src/fal_flash.c"
    "${CMAKE_CURRENT_LIST_DIR}/port/fal/src/fal_partition.c"
    "${CMAKE_CURRENT_LIST_DIR}/port/fal/src/fal.c"
    "${CMAKE_CURRENT_LIST_DIR}/port/fal/src/fal_rtt.c"
)

# Register core library
add_library(flash_db INTERFACE)
target_sources(flash_db PUBLIC ${FLASH_DB_SOURCE_FILES_LIST})
target_include_directories(flash_db INTERFACE ${CMAKE_CURRENT_LIST_DIR}/inc ${CMAKE_CURRENT_LIST_DIR}/port/fal/inc)

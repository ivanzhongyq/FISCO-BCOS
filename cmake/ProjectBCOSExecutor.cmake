include(FetchContent)
FetchContent_Declare(executor_project
    GIT_REPOSITORY https://${URL_BASE}/FISCO-BCOS/bcos-executor.git
    GIT_TAG        2622d76b4ed5fe2a5a58c9c8403afa0a59c473f8
    # SOURCE_DIR     ${CMAKE_SOURCE_DIR}/deps/src/bcos-executor
)

if(NOT executor_project_POPULATED)
  FetchContent_Populate(executor_project)
  list(APPEND CMAKE_MODULE_PATH ${executor_project_SOURCE_DIR}/cmake/)
  set(BUILD_SHARED_LIBS OFF)
  add_subdirectory(${executor_project_SOURCE_DIR} ${executor_project_BINARY_DIR})
endif()

add_library(bcos::executor INTERFACE IMPORTED)
set_property(TARGET bcos::executor PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${executor_project_SOURCE_DIR}/include)
set_property(TARGET bcos::executor PROPERTY INTERFACE_LINK_LIBRARIES executor)

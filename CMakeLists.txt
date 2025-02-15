cmake_minimum_required(VERSION 3.20)

# set(CMAKE_FIND_DEBUG_MODE ON)
# set(wxWidgets_USE_DEBUG ON)

project(wxcharts
        VERSION 0.1.0
        LANGUAGES CXX)

################
# config cmake #
################

# This sets a common dir called bin in the wxcharts_BINARY_DIR,
#   all the executables and libraries will be put there inside a subdirectory called Debug or Release according to its build.
SET(LIBRARY_OUTPUT_PATH    ${wxcharts_BINARY_DIR}/bin CACHE PATH "Single output directory for building all libraries."   FORCE)
SET(EXECUTABLE_OUTPUT_PATH ${wxcharts_BINARY_DIR}/bin CACHE PATH "Single output directory for building all executables." FORCE)

set(CMAKE_CXX_STANDARD 11 CACHE STRING "C++ Standard")
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "")
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "")
set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "Postfix for debug binaries")

if ("${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Windows")
  # Try to run wx-config to get the wxWidgets paths/settings
  message(STATUS "Tries to run wx-config to figure out wxWidget settings ...")
  execute_process(
    COMMAND wx-config
    RESULT_VARIABLE WX_CONFIG_RESULT
    OUTPUT_QUIET
    ERROR_QUIET
  )
  # If wx-config was executed successfully, we are good. Otherwise, we get the paths from environment settings.
  if ("${WX_CONFIG_RESULT}" STREQUAL "1")
    message(STATUS "Found wx-config for configuring wxWidgets paths.")
  else()
    message(STATUS "The wx-config was not found, checking the settings through environment varibles ...")
    set(wxWidgets_ROOT_DIR $ENV{WXWIDGETS_ROOT})
    if ("${wxWidgets_ROOT_DIR}" STREQUAL "")
      message(FATAL_ERROR "wxWidgets is not found, please find and set WXWIDGETS_ROOT env variable.")
    endif()
    set(wxWidgets_LIB_DIR $ENV{WXWIDGETS_LIB})
    if ("${wxWidgets_LIB_DIR}" STREQUAL "")
      message(FATAL_ERROR "wxWidgets library folder is not found, please find and set WXWIDGETS_LIB env variable.")
    endif()
    message(STATUS "wxWidgets root folder: ${wxWidgets_ROOT_DIR}")
    message(STATUS "wxWidgets library folder: ${wxWidgets_LIB_DIR}")
  endif()
else()
    set(wxWidgets_ROOT_DIR "" CACHE PATH "")
    set(wxWidgets_wxrc_EXECUTABLE "" CACHE FILEPATH "")
endif()

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
if(BUILD_SHARED_LIBS)
    message(WARNING "Warning for a shared build: API can change in any version!")
endif()

option(wxBUILD_DEBUG_LEVEL "Debug Level" Default)
if(NOT wxBUILD_DEBUG_LEVEL STREQUAL "Default")
    add_compile_options("-DwxDEBUG_LEVEL=${wxBUILD_DEBUG_LEVEL}")
endif()

##############
# sampples   #
##############
option(BUILD_SAMPLES "Build the samples")
if(BUILD_SAMPLES)
  subdirs(samples)
endif(BUILD_SAMPLES)

##############
# dependency #
##############

include(GNUInstallDirs)

find_package(wxWidgets REQUIRED COMPONENTS core base)

include(${wxWidgets_USE_FILE})

##########
# target #
##########

file(GLOB SOURCE_FILES src/*.cpp)

add_library(${PROJECT_NAME} ${SOURCE_FILES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# export macro
include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
                           PUBLIC # use PUBLIC instead of PRIVATE because tests use it
                               $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/wx/charts>
                               $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
                           INTERFACE
                               $<INSTALL_INTERFACE:${CMAKE_INSTALL_FULL_INCLUDEDIR}>
                               $<INSTALL_INTERFACE:${CMAKE_INSTALL_FULL_INCLUDEDIR}/${PROJECT_NAME}>)

target_link_libraries(${PROJECT_NAME} PUBLIC ${wxWidgets_LIBRARIES})

###########
# install #
###########

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
        NAMESPACE ${PROJECT_NAME}::
        FILE ${PROJECT_NAME}-config.cmake)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/" # source directory
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}) # target directory

install(FILES ${PROJECT_BINARY_DIR}/wxcharts_export.h
        DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}/${PROJECT_NAME}/wx/charts)

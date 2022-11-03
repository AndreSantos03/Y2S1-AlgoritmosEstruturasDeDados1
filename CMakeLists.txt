cmake_minimum_required(VERSION 3.10)

project(schedule)

include_directories(src)

set(SOURCE
src/main.cpp
src/Reader.cpp
src/Reader.h
src/Writer.cpp
src/Writer.h
src/Uc.cpp
src/Uc.h
src/Class.cpp
src/Class.h
src/Sorter.cpp
src/Sorter.h
src/Student.cpp
src/Student.h
src/Creator.cpp
src/Creator.h
)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)

add_executable(${PROJECT_NAME} ${SOURCE})

add_definitions("-g")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
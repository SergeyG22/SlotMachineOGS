########## MACROS ###########################################################################
#############################################################################################

function(conan_message MESSAGE_OUTPUT)
    if(NOT CONAN_CMAKE_SILENT_OUTPUT)
        message(${ARGV${0}})
    endif()
endfunction()


macro(conan_find_apple_frameworks FRAMEWORKS_FOUND FRAMEWORKS FRAMEWORKS_DIRS)
    if(APPLE)
        foreach(_FRAMEWORK ${FRAMEWORKS})
            # https://cmake.org/pipermail/cmake-developers/2017-August/030199.html
            find_library(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND NAME ${_FRAMEWORK} PATHS ${FRAMEWORKS_DIRS} CMAKE_FIND_ROOT_PATH_BOTH)
            if(CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND)
                list(APPEND ${FRAMEWORKS_FOUND} ${CONAN_FRAMEWORK_${_FRAMEWORK}_FOUND})
            else()
                message(FATAL_ERROR "Framework library ${_FRAMEWORK} not found in paths: ${FRAMEWORKS_DIRS}")
            endif()
        endforeach()
    endif()
endmacro()


function(conan_package_library_targets libraries package_libdir deps out_libraries out_libraries_target build_type package_name)
    unset(_CONAN_ACTUAL_TARGETS CACHE)
    unset(_CONAN_FOUND_SYSTEM_LIBS CACHE)
    foreach(_LIBRARY_NAME ${libraries})
        find_library(CONAN_FOUND_LIBRARY NAME ${_LIBRARY_NAME} PATHS ${package_libdir}
                     NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
        if(CONAN_FOUND_LIBRARY)
            conan_message(STATUS "Library ${_LIBRARY_NAME} found ${CONAN_FOUND_LIBRARY}")
            list(APPEND _out_libraries ${CONAN_FOUND_LIBRARY})
            if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
                # Create a micro-target for each lib/a found
                string(REGEX REPLACE "[^A-Za-z0-9.+_-]" "_" _LIBRARY_NAME ${_LIBRARY_NAME})
                set(_LIB_NAME CONAN_LIB::${package_name}_${_LIBRARY_NAME}${build_type})
                if(NOT TARGET ${_LIB_NAME})
                    # Create a micro-target for each lib/a found
                    add_library(${_LIB_NAME} UNKNOWN IMPORTED)
                    set_target_properties(${_LIB_NAME} PROPERTIES IMPORTED_LOCATION ${CONAN_FOUND_LIBRARY})
                    set(_CONAN_ACTUAL_TARGETS ${_CONAN_ACTUAL_TARGETS} ${_LIB_NAME})
                else()
                    conan_message(STATUS "Skipping already existing target: ${_LIB_NAME}")
                endif()
                list(APPEND _out_libraries_target ${_LIB_NAME})
            endif()
            conan_message(STATUS "Found: ${CONAN_FOUND_LIBRARY}")
        else()
            conan_message(STATUS "Library ${_LIBRARY_NAME} not found in package, might be system one")
            list(APPEND _out_libraries_target ${_LIBRARY_NAME})
            list(APPEND _out_libraries ${_LIBRARY_NAME})
            set(_CONAN_FOUND_SYSTEM_LIBS "${_CONAN_FOUND_SYSTEM_LIBS};${_LIBRARY_NAME}")
        endif()
        unset(CONAN_FOUND_LIBRARY CACHE)
    endforeach()

    if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
        # Add all dependencies to all targets
        string(REPLACE " " ";" deps_list "${deps}")
        foreach(_CONAN_ACTUAL_TARGET ${_CONAN_ACTUAL_TARGETS})
            set_property(TARGET ${_CONAN_ACTUAL_TARGET} PROPERTY INTERFACE_LINK_LIBRARIES "${_CONAN_FOUND_SYSTEM_LIBS};${deps_list}")
        endforeach()
    endif()

    set(${out_libraries} ${_out_libraries} PARENT_SCOPE)
    set(${out_libraries_target} ${_out_libraries_target} PARENT_SCOPE)
endfunction()


########### FOUND PACKAGE ###################################################################
#############################################################################################

include(FindPackageHandleStandardArgs)

conan_message(STATUS "Conan: Using autogenerated FindVorbis.cmake")
set(Vorbis_FOUND 1)
set(Vorbis_VERSION "1.3.7")

find_package_handle_standard_args(Vorbis REQUIRED_VARS
                                  Vorbis_VERSION VERSION_VAR Vorbis_VERSION)
mark_as_advanced(Vorbis_FOUND Vorbis_VERSION)

set(Vorbis_COMPONENTS Vorbis::Enc Vorbis::vorbisenc Vorbis::File Vorbis::vorbisfile Vorbis::vorbis)

if(Vorbis_FIND_COMPONENTS)
    foreach(_FIND_COMPONENT ${Vorbis_FIND_COMPONENTS})
        list(FIND Vorbis_COMPONENTS "Vorbis::${_FIND_COMPONENT}" _index)
        if(${_index} EQUAL -1)
            conan_message(FATAL_ERROR "Conan: Component '${_FIND_COMPONENT}' NOT found in package 'Vorbis'")
        else()
            conan_message(STATUS "Conan: Component '${_FIND_COMPONENT}' found in package 'Vorbis'")
        endif()
    endforeach()
endif()

########### VARIABLES #######################################################################
#############################################################################################


set(Vorbis_INCLUDE_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_INCLUDE_DIR "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_INCLUDES "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_RES_DIRS )
set(Vorbis_DEFINITIONS )
set(Vorbis_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)
set(Vorbis_COMPILE_DEFINITIONS )
set(Vorbis_COMPILE_OPTIONS_LIST "" "")
set(Vorbis_COMPILE_OPTIONS_C "")
set(Vorbis_COMPILE_OPTIONS_CXX "")
set(Vorbis_LIBRARIES_TARGETS "") # Will be filled later, if CMake 3
set(Vorbis_LIBRARIES "") # Will be filled later
set(Vorbis_LIBS "") # Same as Vorbis_LIBRARIES
set(Vorbis_SYSTEM_LIBS )
set(Vorbis_FRAMEWORK_DIRS )
set(Vorbis_FRAMEWORKS )
set(Vorbis_FRAMEWORKS_FOUND "") # Will be filled later
set(Vorbis_BUILD_MODULES_PATHS )

conan_find_apple_frameworks(Vorbis_FRAMEWORKS_FOUND "${Vorbis_FRAMEWORKS}" "${Vorbis_FRAMEWORK_DIRS}")

mark_as_advanced(Vorbis_INCLUDE_DIRS
                 Vorbis_INCLUDE_DIR
                 Vorbis_INCLUDES
                 Vorbis_DEFINITIONS
                 Vorbis_LINKER_FLAGS_LIST
                 Vorbis_COMPILE_DEFINITIONS
                 Vorbis_COMPILE_OPTIONS_LIST
                 Vorbis_LIBRARIES
                 Vorbis_LIBS
                 Vorbis_LIBRARIES_TARGETS)

# Find the real .lib/.a and add them to Vorbis_LIBS and Vorbis_LIBRARY_LIST
set(Vorbis_LIBRARY_LIST vorbisenc vorbisfile vorbis)
set(Vorbis_LIB_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/lib")

# Gather all the libraries that should be linked to the targets (do not touch existing variables):
set(_Vorbis_DEPENDENCIES "${Vorbis_FRAMEWORKS_FOUND} ${Vorbis_SYSTEM_LIBS} Ogg::Ogg")

conan_package_library_targets("${Vorbis_LIBRARY_LIST}"  # libraries
                              "${Vorbis_LIB_DIRS}"      # package_libdir
                              "${_Vorbis_DEPENDENCIES}"  # deps
                              Vorbis_LIBRARIES            # out_libraries
                              Vorbis_LIBRARIES_TARGETS    # out_libraries_targets
                              ""                          # build_type
                              "Vorbis")                                      # package_name

set(Vorbis_LIBS ${Vorbis_LIBRARIES})

foreach(_FRAMEWORK ${Vorbis_FRAMEWORKS_FOUND})
    list(APPEND Vorbis_LIBRARIES_TARGETS ${_FRAMEWORK})
    list(APPEND Vorbis_LIBRARIES ${_FRAMEWORK})
endforeach()

foreach(_SYSTEM_LIB ${Vorbis_SYSTEM_LIBS})
    list(APPEND Vorbis_LIBRARIES_TARGETS ${_SYSTEM_LIB})
    list(APPEND Vorbis_LIBRARIES ${_SYSTEM_LIB})
endforeach()

# We need to add our requirements too
set(Vorbis_LIBRARIES_TARGETS "${Vorbis_LIBRARIES_TARGETS};Ogg::Ogg")
set(Vorbis_LIBRARIES "${Vorbis_LIBRARIES};Ogg::Ogg")

set(CMAKE_MODULE_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_PREFIX_PATH})


########### COMPONENT vorbis VARIABLES #############################################

set(Vorbis_vorbis_INCLUDE_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_vorbis_INCLUDE_DIR "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_vorbis_INCLUDES "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_vorbis_LIB_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/lib")
set(Vorbis_vorbis_RES_DIRS )
set(Vorbis_vorbis_DEFINITIONS )
set(Vorbis_vorbis_COMPILE_DEFINITIONS )
set(Vorbis_vorbis_COMPILE_OPTIONS_C "")
set(Vorbis_vorbis_COMPILE_OPTIONS_CXX "")
set(Vorbis_vorbis_LIBS vorbis)
set(Vorbis_vorbis_SYSTEM_LIBS )
set(Vorbis_vorbis_FRAMEWORK_DIRS )
set(Vorbis_vorbis_FRAMEWORKS )
set(Vorbis_vorbis_BUILD_MODULES_PATHS )
set(Vorbis_vorbis_DEPENDENCIES Ogg::Ogg)
set(Vorbis_vorbis_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)

########### COMPONENT vorbisfile VARIABLES #############################################

set(Vorbis_vorbisfile_INCLUDE_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_vorbisfile_INCLUDE_DIR "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_vorbisfile_INCLUDES "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_vorbisfile_LIB_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/lib")
set(Vorbis_vorbisfile_RES_DIRS )
set(Vorbis_vorbisfile_DEFINITIONS )
set(Vorbis_vorbisfile_COMPILE_DEFINITIONS )
set(Vorbis_vorbisfile_COMPILE_OPTIONS_C "")
set(Vorbis_vorbisfile_COMPILE_OPTIONS_CXX "")
set(Vorbis_vorbisfile_LIBS vorbisfile)
set(Vorbis_vorbisfile_SYSTEM_LIBS )
set(Vorbis_vorbisfile_FRAMEWORK_DIRS )
set(Vorbis_vorbisfile_FRAMEWORKS )
set(Vorbis_vorbisfile_BUILD_MODULES_PATHS )
set(Vorbis_vorbisfile_DEPENDENCIES Vorbis::vorbis)
set(Vorbis_vorbisfile_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)

########### COMPONENT File VARIABLES #############################################

set(Vorbis_File_INCLUDE_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_File_INCLUDE_DIR "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_File_INCLUDES "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_File_LIB_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/lib")
set(Vorbis_File_RES_DIRS )
set(Vorbis_File_DEFINITIONS )
set(Vorbis_File_COMPILE_DEFINITIONS )
set(Vorbis_File_COMPILE_OPTIONS_C "")
set(Vorbis_File_COMPILE_OPTIONS_CXX "")
set(Vorbis_File_LIBS )
set(Vorbis_File_SYSTEM_LIBS )
set(Vorbis_File_FRAMEWORK_DIRS )
set(Vorbis_File_FRAMEWORKS )
set(Vorbis_File_BUILD_MODULES_PATHS )
set(Vorbis_File_DEPENDENCIES Vorbis::vorbisfile)
set(Vorbis_File_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)

########### COMPONENT vorbisenc VARIABLES #############################################

set(Vorbis_vorbisenc_INCLUDE_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_vorbisenc_INCLUDE_DIR "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_vorbisenc_INCLUDES "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_vorbisenc_LIB_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/lib")
set(Vorbis_vorbisenc_RES_DIRS )
set(Vorbis_vorbisenc_DEFINITIONS )
set(Vorbis_vorbisenc_COMPILE_DEFINITIONS )
set(Vorbis_vorbisenc_COMPILE_OPTIONS_C "")
set(Vorbis_vorbisenc_COMPILE_OPTIONS_CXX "")
set(Vorbis_vorbisenc_LIBS vorbisenc)
set(Vorbis_vorbisenc_SYSTEM_LIBS )
set(Vorbis_vorbisenc_FRAMEWORK_DIRS )
set(Vorbis_vorbisenc_FRAMEWORKS )
set(Vorbis_vorbisenc_BUILD_MODULES_PATHS )
set(Vorbis_vorbisenc_DEPENDENCIES Vorbis::vorbis)
set(Vorbis_vorbisenc_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)

########### COMPONENT Enc VARIABLES #############################################

set(Vorbis_Enc_INCLUDE_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_Enc_INCLUDE_DIR "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_Enc_INCLUDES "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/include")
set(Vorbis_Enc_LIB_DIRS "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/lib")
set(Vorbis_Enc_RES_DIRS )
set(Vorbis_Enc_DEFINITIONS )
set(Vorbis_Enc_COMPILE_DEFINITIONS )
set(Vorbis_Enc_COMPILE_OPTIONS_C "")
set(Vorbis_Enc_COMPILE_OPTIONS_CXX "")
set(Vorbis_Enc_LIBS )
set(Vorbis_Enc_SYSTEM_LIBS )
set(Vorbis_Enc_FRAMEWORK_DIRS )
set(Vorbis_Enc_FRAMEWORKS )
set(Vorbis_Enc_BUILD_MODULES_PATHS )
set(Vorbis_Enc_DEPENDENCIES Vorbis::vorbisenc)
set(Vorbis_Enc_LINKER_FLAGS_LIST
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:>"
        "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:>"
)


########## FIND PACKAGE DEPENDENCY ##########################################################
#############################################################################################

include(CMakeFindDependencyMacro)

if(NOT Ogg_FOUND)
    find_dependency(Ogg REQUIRED)
else()
    conan_message(STATUS "Conan: Dependency Ogg already found")
endif()


########## FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #######################################
#############################################################################################

########## COMPONENT vorbis FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(Vorbis_vorbis_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(Vorbis_vorbis_FRAMEWORKS_FOUND "${Vorbis_vorbis_FRAMEWORKS}" "${Vorbis_vorbis_FRAMEWORK_DIRS}")

set(Vorbis_vorbis_LIB_TARGETS "")
set(Vorbis_vorbis_NOT_USED "")
set(Vorbis_vorbis_LIBS_FRAMEWORKS_DEPS ${Vorbis_vorbis_FRAMEWORKS_FOUND} ${Vorbis_vorbis_SYSTEM_LIBS} ${Vorbis_vorbis_DEPENDENCIES})
conan_package_library_targets("${Vorbis_vorbis_LIBS}"
                              "${Vorbis_vorbis_LIB_DIRS}"
                              "${Vorbis_vorbis_LIBS_FRAMEWORKS_DEPS}"
                              Vorbis_vorbis_NOT_USED
                              Vorbis_vorbis_LIB_TARGETS
                              ""
                              "Vorbis_vorbis")

set(Vorbis_vorbis_LINK_LIBS ${Vorbis_vorbis_LIB_TARGETS} ${Vorbis_vorbis_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_PREFIX_PATH})

########## COMPONENT vorbisfile FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(Vorbis_vorbisfile_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(Vorbis_vorbisfile_FRAMEWORKS_FOUND "${Vorbis_vorbisfile_FRAMEWORKS}" "${Vorbis_vorbisfile_FRAMEWORK_DIRS}")

set(Vorbis_vorbisfile_LIB_TARGETS "")
set(Vorbis_vorbisfile_NOT_USED "")
set(Vorbis_vorbisfile_LIBS_FRAMEWORKS_DEPS ${Vorbis_vorbisfile_FRAMEWORKS_FOUND} ${Vorbis_vorbisfile_SYSTEM_LIBS} ${Vorbis_vorbisfile_DEPENDENCIES})
conan_package_library_targets("${Vorbis_vorbisfile_LIBS}"
                              "${Vorbis_vorbisfile_LIB_DIRS}"
                              "${Vorbis_vorbisfile_LIBS_FRAMEWORKS_DEPS}"
                              Vorbis_vorbisfile_NOT_USED
                              Vorbis_vorbisfile_LIB_TARGETS
                              ""
                              "Vorbis_vorbisfile")

set(Vorbis_vorbisfile_LINK_LIBS ${Vorbis_vorbisfile_LIB_TARGETS} ${Vorbis_vorbisfile_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_PREFIX_PATH})

########## COMPONENT File FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(Vorbis_File_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(Vorbis_File_FRAMEWORKS_FOUND "${Vorbis_File_FRAMEWORKS}" "${Vorbis_File_FRAMEWORK_DIRS}")

set(Vorbis_File_LIB_TARGETS "")
set(Vorbis_File_NOT_USED "")
set(Vorbis_File_LIBS_FRAMEWORKS_DEPS ${Vorbis_File_FRAMEWORKS_FOUND} ${Vorbis_File_SYSTEM_LIBS} ${Vorbis_File_DEPENDENCIES})
conan_package_library_targets("${Vorbis_File_LIBS}"
                              "${Vorbis_File_LIB_DIRS}"
                              "${Vorbis_File_LIBS_FRAMEWORKS_DEPS}"
                              Vorbis_File_NOT_USED
                              Vorbis_File_LIB_TARGETS
                              ""
                              "Vorbis_File")

set(Vorbis_File_LINK_LIBS ${Vorbis_File_LIB_TARGETS} ${Vorbis_File_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_PREFIX_PATH})

########## COMPONENT vorbisenc FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(Vorbis_vorbisenc_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(Vorbis_vorbisenc_FRAMEWORKS_FOUND "${Vorbis_vorbisenc_FRAMEWORKS}" "${Vorbis_vorbisenc_FRAMEWORK_DIRS}")

set(Vorbis_vorbisenc_LIB_TARGETS "")
set(Vorbis_vorbisenc_NOT_USED "")
set(Vorbis_vorbisenc_LIBS_FRAMEWORKS_DEPS ${Vorbis_vorbisenc_FRAMEWORKS_FOUND} ${Vorbis_vorbisenc_SYSTEM_LIBS} ${Vorbis_vorbisenc_DEPENDENCIES})
conan_package_library_targets("${Vorbis_vorbisenc_LIBS}"
                              "${Vorbis_vorbisenc_LIB_DIRS}"
                              "${Vorbis_vorbisenc_LIBS_FRAMEWORKS_DEPS}"
                              Vorbis_vorbisenc_NOT_USED
                              Vorbis_vorbisenc_LIB_TARGETS
                              ""
                              "Vorbis_vorbisenc")

set(Vorbis_vorbisenc_LINK_LIBS ${Vorbis_vorbisenc_LIB_TARGETS} ${Vorbis_vorbisenc_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_PREFIX_PATH})

########## COMPONENT Enc FIND LIBRARIES & FRAMEWORKS / DYNAMIC VARS #############

set(Vorbis_Enc_FRAMEWORKS_FOUND "")
conan_find_apple_frameworks(Vorbis_Enc_FRAMEWORKS_FOUND "${Vorbis_Enc_FRAMEWORKS}" "${Vorbis_Enc_FRAMEWORK_DIRS}")

set(Vorbis_Enc_LIB_TARGETS "")
set(Vorbis_Enc_NOT_USED "")
set(Vorbis_Enc_LIBS_FRAMEWORKS_DEPS ${Vorbis_Enc_FRAMEWORKS_FOUND} ${Vorbis_Enc_SYSTEM_LIBS} ${Vorbis_Enc_DEPENDENCIES})
conan_package_library_targets("${Vorbis_Enc_LIBS}"
                              "${Vorbis_Enc_LIB_DIRS}"
                              "${Vorbis_Enc_LIBS_FRAMEWORKS_DEPS}"
                              Vorbis_Enc_NOT_USED
                              Vorbis_Enc_LIB_TARGETS
                              ""
                              "Vorbis_Enc")

set(Vorbis_Enc_LINK_LIBS ${Vorbis_Enc_LIB_TARGETS} ${Vorbis_Enc_LIBS_FRAMEWORKS_DEPS})

set(CMAKE_MODULE_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "C:/Users/Dolba/.conan/data/vorbis/1.3.7/_/_/package/becff00909fb3d957c6b4ca60fa64d4e6a32a540/" ${CMAKE_PREFIX_PATH})


########## TARGETS ##########################################################################
#############################################################################################

########## COMPONENT vorbis TARGET #################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET Vorbis::vorbis)
        add_library(Vorbis::vorbis INTERFACE IMPORTED)
        set_target_properties(Vorbis::vorbis PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                              "${Vorbis_vorbis_INCLUDE_DIRS}")
        set_target_properties(Vorbis::vorbis PROPERTIES INTERFACE_LINK_DIRECTORIES
                              "${Vorbis_vorbis_LIB_DIRS}")
        set_target_properties(Vorbis::vorbis PROPERTIES INTERFACE_LINK_LIBRARIES
                              "${Vorbis_vorbis_LINK_LIBS};${Vorbis_vorbis_LINKER_FLAGS_LIST}")
        set_target_properties(Vorbis::vorbis PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                              "${Vorbis_vorbis_COMPILE_DEFINITIONS}")
        set_target_properties(Vorbis::vorbis PROPERTIES INTERFACE_COMPILE_OPTIONS
                              "${Vorbis_vorbis_COMPILE_OPTIONS_C};${Vorbis_vorbis_COMPILE_OPTIONS_CXX}")
    endif()
endif()

########## COMPONENT vorbisfile TARGET #################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET Vorbis::vorbisfile)
        add_library(Vorbis::vorbisfile INTERFACE IMPORTED)
        set_target_properties(Vorbis::vorbisfile PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                              "${Vorbis_vorbisfile_INCLUDE_DIRS}")
        set_target_properties(Vorbis::vorbisfile PROPERTIES INTERFACE_LINK_DIRECTORIES
                              "${Vorbis_vorbisfile_LIB_DIRS}")
        set_target_properties(Vorbis::vorbisfile PROPERTIES INTERFACE_LINK_LIBRARIES
                              "${Vorbis_vorbisfile_LINK_LIBS};${Vorbis_vorbisfile_LINKER_FLAGS_LIST}")
        set_target_properties(Vorbis::vorbisfile PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                              "${Vorbis_vorbisfile_COMPILE_DEFINITIONS}")
        set_target_properties(Vorbis::vorbisfile PROPERTIES INTERFACE_COMPILE_OPTIONS
                              "${Vorbis_vorbisfile_COMPILE_OPTIONS_C};${Vorbis_vorbisfile_COMPILE_OPTIONS_CXX}")
    endif()
endif()

########## COMPONENT File TARGET #################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET Vorbis::File)
        add_library(Vorbis::File INTERFACE IMPORTED)
        set_target_properties(Vorbis::File PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                              "${Vorbis_File_INCLUDE_DIRS}")
        set_target_properties(Vorbis::File PROPERTIES INTERFACE_LINK_DIRECTORIES
                              "${Vorbis_File_LIB_DIRS}")
        set_target_properties(Vorbis::File PROPERTIES INTERFACE_LINK_LIBRARIES
                              "${Vorbis_File_LINK_LIBS};${Vorbis_File_LINKER_FLAGS_LIST}")
        set_target_properties(Vorbis::File PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                              "${Vorbis_File_COMPILE_DEFINITIONS}")
        set_target_properties(Vorbis::File PROPERTIES INTERFACE_COMPILE_OPTIONS
                              "${Vorbis_File_COMPILE_OPTIONS_C};${Vorbis_File_COMPILE_OPTIONS_CXX}")
    endif()
endif()

########## COMPONENT vorbisenc TARGET #################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET Vorbis::vorbisenc)
        add_library(Vorbis::vorbisenc INTERFACE IMPORTED)
        set_target_properties(Vorbis::vorbisenc PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                              "${Vorbis_vorbisenc_INCLUDE_DIRS}")
        set_target_properties(Vorbis::vorbisenc PROPERTIES INTERFACE_LINK_DIRECTORIES
                              "${Vorbis_vorbisenc_LIB_DIRS}")
        set_target_properties(Vorbis::vorbisenc PROPERTIES INTERFACE_LINK_LIBRARIES
                              "${Vorbis_vorbisenc_LINK_LIBS};${Vorbis_vorbisenc_LINKER_FLAGS_LIST}")
        set_target_properties(Vorbis::vorbisenc PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                              "${Vorbis_vorbisenc_COMPILE_DEFINITIONS}")
        set_target_properties(Vorbis::vorbisenc PROPERTIES INTERFACE_COMPILE_OPTIONS
                              "${Vorbis_vorbisenc_COMPILE_OPTIONS_C};${Vorbis_vorbisenc_COMPILE_OPTIONS_CXX}")
    endif()
endif()

########## COMPONENT Enc TARGET #################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    # Target approach
    if(NOT TARGET Vorbis::Enc)
        add_library(Vorbis::Enc INTERFACE IMPORTED)
        set_target_properties(Vorbis::Enc PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                              "${Vorbis_Enc_INCLUDE_DIRS}")
        set_target_properties(Vorbis::Enc PROPERTIES INTERFACE_LINK_DIRECTORIES
                              "${Vorbis_Enc_LIB_DIRS}")
        set_target_properties(Vorbis::Enc PROPERTIES INTERFACE_LINK_LIBRARIES
                              "${Vorbis_Enc_LINK_LIBS};${Vorbis_Enc_LINKER_FLAGS_LIST}")
        set_target_properties(Vorbis::Enc PROPERTIES INTERFACE_COMPILE_DEFINITIONS
                              "${Vorbis_Enc_COMPILE_DEFINITIONS}")
        set_target_properties(Vorbis::Enc PROPERTIES INTERFACE_COMPILE_OPTIONS
                              "${Vorbis_Enc_COMPILE_OPTIONS_C};${Vorbis_Enc_COMPILE_OPTIONS_CXX}")
    endif()
endif()

########## GLOBAL TARGET ####################################################################

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.0")
    if(NOT TARGET Vorbis::Vorbis)
        add_library(Vorbis::Vorbis INTERFACE IMPORTED)
    endif()
    set_property(TARGET Vorbis::Vorbis APPEND PROPERTY
                 INTERFACE_LINK_LIBRARIES "${Vorbis_COMPONENTS}")
endif()

########## BUILD MODULES ####################################################################
#############################################################################################
########## COMPONENT vorbis BUILD MODULES ##########################################

foreach(_BUILD_MODULE_PATH ${Vorbis_vorbis_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()
########## COMPONENT vorbisfile BUILD MODULES ##########################################

foreach(_BUILD_MODULE_PATH ${Vorbis_vorbisfile_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()
########## COMPONENT File BUILD MODULES ##########################################

foreach(_BUILD_MODULE_PATH ${Vorbis_File_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()
########## COMPONENT vorbisenc BUILD MODULES ##########################################

foreach(_BUILD_MODULE_PATH ${Vorbis_vorbisenc_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()
########## COMPONENT Enc BUILD MODULES ##########################################

foreach(_BUILD_MODULE_PATH ${Vorbis_Enc_BUILD_MODULES_PATHS})
    include(${_BUILD_MODULE_PATH})
endforeach()

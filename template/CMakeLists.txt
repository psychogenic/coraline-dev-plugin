#
#  Coraline Plugin Skeleton -- templates for coraline plugin development
#
#  Copyright (C) 2018  Pat Deegan, https://psychogenic.com
#
#   This file is a supporting component of the 
#   Coraline [https://coraline.psychogenic.com/] plugin 
#   skeleton/code generator [https://github.com/psychogenic/coraline-dev-plugin]
# 
#   It is released under the terms and conditions of the
#   Apache License, v2.0.  See the included LICENSE file
#   for details.


cmake_minimum_required(VERSION 2.6)


set(PLUGIN_GENERATOR_USAGE "Call `cmake -DPLUGIN_CLASS=SomeName [-DPLUGIN_SHORTNAME=Somename -DPLUGIN_FULLNAME=cordova-plugin-somename]`")

if (PLUGIN_CLASS)
  message(STATUS "Plugin class name: ${PLUGIN_CLASS}")
else()
  message(FATAL_ERROR "Need PLUGIN_CLASS: ${PLUGIN_GENERATOR_USAGE}")
endif()


string(TOLOWER ${PLUGIN_CLASS} PLUGIN_CLASS_ASLOWER)
string(TOUPPER ${PLUGIN_CLASS} PLUGIN_CLASS_ASUPPER)
set(PLUGIN_PACKAGE_SUFFIX ${PLUGIN_CLASS_ASLOWER})
set(PLUGIN_DIRECTORY_NAME ${PLUGIN_CLASS_ASLOWER})
set(PLUGIN_PROJECTNAME "coraline-plugin-${PLUGIN_PACKAGE_SUFFIX}")
set(PLUGIN_DRIVERFILEPREFIX "${PLUGIN_CLASS}_plugin")

if (PLUGIN_SHORTNAME)
  message(STATUS "Plugin 'shortname': ${PLUGIN_SHORTNAME}")
else()
  set(PLUGIN_SHORTNAME ${PLUGIN_CLASS})
  message(STATUS "No plugin 'shortname', will use '${PLUGIN_SHORTNAME}'")
endif()

if (PLUGIN_FULLNAME)
  message(STATUS "Plugin 'fullname': ${PLUGIN_FULLNAME}")
else()
  set(PLUGIN_FULLNAME "cordova-plugin-${PLUGIN_CLASS_ASLOWER}")
  message(STATUS "Plugin fullname auto set to '${PLUGIN_FULLNAME}'")
endif()


find_package(PkgConfig REQUIRED)

pkg_search_module(CORALINEPLUGINDEV REQUIRED coraline-plugin-dev)

set(GEN_SRC_DIRECTORY "${PROJECT_BINARY_DIR}/../${PLUGIN_DIRECTORY_NAME}")
file(MAKE_DIRECTORY "${GEN_SRC_DIRECTORY}/include")
file(MAKE_DIRECTORY "${GEN_SRC_DIRECTORY}/shared/${PLUGIN_SHORTNAME}")

configure_file(include/myplugin_plugin.h 
	${GEN_SRC_DIRECTORY}/include/${PLUGIN_DRIVERFILEPREFIX}.h @ONLY)
configure_file(include/myplugin_globals.h 
	${GEN_SRC_DIRECTORY}/include/${PLUGIN_CLASS_ASLOWER}_globals.h @ONLY)
configure_file(include/loader.h 
	${GEN_SRC_DIRECTORY}/include/loader.h @ONLY)


configure_file(coralineplugin/myplugin_plugin.cpp 
	${GEN_SRC_DIRECTORY}/${PLUGIN_DRIVERFILEPREFIX}.cpp @ONLY)

configure_file(coralineplugin/loader.cpp 
	${GEN_SRC_DIRECTORY}/loader.cpp @ONLY)

configure_file(shared/init.js
	${GEN_SRC_DIRECTORY}/shared/${PLUGIN_SHORTNAME} @ONLY)
	
configure_file(CMakeLists-gen.in 
	${GEN_SRC_DIRECTORY}/CMakeLists.txt @ONLY)


message(STATUS "configured!  All files generated may be found in: \n   *** ${GEN_SRC_DIRECTORY}")



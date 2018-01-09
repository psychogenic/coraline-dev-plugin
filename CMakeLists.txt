#
#  Coraline Plugin Skeleton generator
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


add_subdirectory(template)


/*
 * loader.cpp
 *
 *  Created on: Dec 2, 2017
 *
 *        Copyright (C) 2017 Pat Deegan, https://psychogenic.com
 *
 *  This file is a supporting component of the
 *  Coraline [https://coraline.psychogenic.com/] plugin
 *  skeleton/code generator [https://github.com/psychogenic/coraline-dev-plugin]
 *
 *  It is released under the terms and conditions of the
 *  Apache License, v2.0.  See the included LICENSE file
 *  for details.
 *
 */

#include "loader.h"
#include "@PLUGIN_CLASS@_plugin.h"


extern "C" bool supports_driver(const Coraline::Version & v) {
	// may choose to check passed-in version to confirm support
	// returning false will cancel plugin load
	if (v.maj > CORVIEW_PLUGINS_VERSION_MAJOR) {
		return false;
	}
	if (v.min > (CORVIEW_PLUGINS_VERSION_MINOR + 1)) {
		return false;
	}

    return true;
}

extern "C"  Coraline::Version object_version() {

    return Coraline::Version(@PLUGIN_CLASS_ASUPPER@_VERSION_MAJOR,
            @PLUGIN_CLASS_ASUPPER@_VERSION_MINOR,
            @PLUGIN_CLASS_ASUPPER@_VERSION_PATCH);
}

extern "C" Coraline::Plugin::Plugin * create_object(const Coraline::Plugin::Context & ctx)
{
  return new @PLUGIN_CLASS@(ctx);
}


extern "C" void destroy_object(Coraline::Plugin::Plugin * object )
{
  delete object;
}






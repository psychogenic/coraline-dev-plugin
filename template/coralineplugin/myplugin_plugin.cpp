/*
 * @PLUGIN_CLASS@.cpp
 *
 *  Created on: Jan 8, 2018
 *
 *        Copyright (C) 2018 Pat Deegan, https://psychogenic.com
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

#include "@PLUGIN_CLASS@_plugin.h"


@PLUGIN_CLASS@::@PLUGIN_CLASS@(const Coraline::Plugin::Context& ctx)
	: Coraline::Plugin::Base(ctx)
{
	/*
	 * plugin instantiation
	 * Setup instance variables, etc, but wait until
	 * startUp() to interact with the system (e.g. open file handles).
	 *
	 */
}

/*
 * startUp -- perform any required initialization here,
 * like opening file handles, databases, sockets whatever.
 *
 * JS may also be executed here, if required.
 *
 */
void @PLUGIN_CLASS@::startUp() {
	// nothing to do, as of yet.
}

/*
 * update() -- will be ticked periodically
 * during operation.  May be overridden if required but,
 * if you're using the UpdateAction/queueAction() methods,
 * you need to call the parent class update() to ensure
 * they actually get processed.
 */
// void @PLUGIN_CLASS@::update() {
// 		this->Coraline::Plugin::Base::update();
// }


/*
 * shutdown()
 * Perform clean-up before shutting down.
 * Close database handles, flush files, etc.
 */
void @PLUGIN_CLASS@::shutdown() {
	// nothing to do, yet.
}

/*
 * clientSideSupportFile()
 * Return the name of a file to load that is to be injected
 * into the JS engine on plugin instantiation, e.g. "init.js"
 *
 * This file must reside in the plugin's resource directory,
 * which is determined using its shortName().  E.g. for
 * the "BLE" (shortName) plugin, this would be a file
 * at /usr/local/share/coraline/plugin-resources/BLE/init.js
 *
 * NOTE: if you use clientSideSupport* methods, at this time the system
 * expects to be able to construct a suitable object using the shortName()
 * on the JS side.  So if you had a shortName of "SuperDuper", it'll try
 * and construct a "new SuperDuper()" at some point.
 *
 * See the provided example init.js
 *
 */
Coraline::Plugin::ClientCodeFileName @PLUGIN_CLASS@::clientSideSupportFile() {
	return Coraline::Plugin::ClientCodeFileName("init.js");
}

/*
 * clientSideSupport()
 * Return as string of JS to run on instantiation, e.g.
 * "function Booya() {}; window.booya = new Booya();" or whatever.
 *
 *
 * NOTE: if you use clientSideSupport* methods, at this time the system
 * expects to be able to construct a suitable object using the shortName()
 * on the JS side.  So if you had a shortName of "SuperDuper", it'll try
 * and construct a "new SuperDuper()" at some point.
 *
 */
//Coraline::Plugin::ClientCode @PLUGIN_CLASS@::clientSideSupport() {

// }

Coraline::Plugin::AboutString @PLUGIN_CLASS@::about() {
	return Coraline::Plugin::AboutString(
			"@PLUGIN_CLASS@ is awesome, and copyright (C) 2018 Pat Deegan");
}

Coraline::Plugin::AboutString @PLUGIN_CLASS@::usage() {
	return Coraline::Plugin::AboutString(
			"To use @PLUGIN_CLASS@, simply call ");

}

Coraline::Version @PLUGIN_CLASS@::version() {
	Coraline::Version pVersion(
			@PLUGIN_CLASS_ASUPPER@_VERSION_MAJOR,
			@PLUGIN_CLASS_ASUPPER@_VERSION_MINOR,
			@PLUGIN_CLASS_ASUPPER@_VERSION_PATCH);

	return pVersion;
}

/*
 * registerAllMethods()
 * Plugin::Base utility method--just list every callback (i.e. methods with the
 * correct signature) you wish to make publically visible.
 *
 * Easiest way: use the PLUGINREGMETH() macro.
 */
void @PLUGIN_CLASS@::registerAllMethods() {
	PLUGINREGMETH(hello);
}


bool @PLUGIN_CLASS@::hello(const Coraline::Plugin::StandardCallbackIDs & callbacks,
            const Coraline::Plugin::ArgsList & args) {

	/*
	 * sample plugin callback.  This may be triggered by the client app.
	 * Our job:
	 *   - do whatever we promised we would
	 *   - eventually trigger one of the JS-side callbacks
	 *
	 * Triggering the JS callbacks all comes down to calling
	 *  - triggerCallback (for one-off callbacks) OR
	 *  - triggerCallbackNoRemove (for callbacks that need to stay around, e.g. for on-going
	 *    notifications)
	 *
	 *  Either of these may be called with just a CallbackID (found in the
	 *  callbacks.success or callbacks.error passed into this method), and may accept
	 *  a second argument (a json object to hold whatever you want).
	 *
	 *  There are reportSuccess/reportError convenience methods available
	 *  to simplify calling triggerCallback() with the appropriate id.
	 *
	 */


	// we'll queue a 'success' response.
	// by using queueAction, we know our lambda will be executed
	// when we're given a little time, down the line, during the update call
	// (handled by base class).
	queueAction([this, callbacks](){
		json respObj; // whatever
		respObj["success"] = true;
		respObj["message"] = "helloooooo";
		reportSuccess(callbacks, respObj);
	});

	// everything's gonna work out, return true.
	return true;

}

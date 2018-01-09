/*
 * @PLUGIN_CLASS@_plugin.h
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

#ifndef INCLUDE_@PLUGIN_CLASS_ASUPPER@_PLUGIN_H_
#define INCLUDE_@PLUGIN_CLASS_ASUPPER@_PLUGIN_H_

#include "@PLUGIN_CLASS_ASLOWER@_globals.h"
/*
 * @PLUGIN_CLASS@ -- an instance of this class, returned by the
 * loader create_object(), is what coraline interacts with
 * to trigger plugin callbacks.
 *
 * You may, for convenience, use Coraline::Plugin::Base as a
 * base class (as done here). The only requirement, however, is
 * that the object implement the Coraline::Plugin::Plugin interface
 * (which Plugin::Base does, of course).
 *
 *
 * Lifecycle
 *
 * The plugin lifecycle is essentially this:
 *  dlopen library
 *    supports_driver()
 *    create_object()
 *      plugin registration
 *      plugin JS injection
 *      plugin startup
 *        updates/plugin callbacks...
 *      plugin shutdown
 *    destroy_object()
 *  dlclose libray
 *
 *
 * 	*** PRE instantiation ***
 *
 * 	Dynamically loadable libraries containing coraline plugins are first
 * 	 - opened
 * 	 - checked for all the mandatory loader functions
 * 	 - checked for a "true" return from the libaries supports_driver(), called
 * 	   with the running version of Coraline
 *
 * 	If any of these checks fails, the library is closed and subsequently ignored.
 *
 *
 * 	*** instantiation ***
 * 	Plugin instances are created, by Coraline at startup, and
 * 	loaded using the dl library's create_object().
 *
 * 	If the plugin is not required by the app, it will then be released/destroyed
 * 	it's destroy_object(). The end.
 *
 * 	 ** registration
 * 	If it *is* required by the app, it is given a chance to initialize and
 * 	register with the system plugin registry.  When using Plugin::Base, this process
 * 	is simplified a bit, and you need only override registerAllMethods() in order
 * 	to make your callbacks visible to the system (e.g. with the PLUGINREGMETH() macro).
 *
 * 	 ** injection
 * 	As the final step of instantiation, the plugin is given a chance to inject
 * 	"driver" javascript code into the JS engine.
 *
 * 	This can be done a few ways, the simplest being to override Plugin::Base's
 * 		* clientSideSupportFile() (return a JS filename to load from
 * 		  under shortName() directory); or
 * 		* clientSideSupport() (return a string of JS to eval in the JS engine)
 *
 *
 * 	*** start up ***
 *
 *  Once all the required plugins have been instantiated, as described above,
 *  the start-up signal is given, and each loaded plugin will get one call to
 *  it's startUp() method.
 *
 *  *** Device Ready ***
 *
 *  After all plugins have started up, the device ready signal is given to
 *  client code, and you can expect callbacks to be triggered at any time.
 *
 *
 *  *** Running ***
 *
 *  While running, your plugin's update() method will be periodically ticked.
 * 	You will also have callback methods triggered by the client app, as requested
 * 	by that side.
 *
 * 	The simplest approach is to inherit from Plugin::Base and have
 * 	your callbacks queue UpdateActions (void(void) lambdas, using queueAction())
 * 	to report information/success/failure.
 * 	These will be executed on the next update().
 *
 * 	Your job, while running, is to keep things snappy so the UI remains responsive.
 *
 * 	Process any long operations in the background and, ideally, trigger
 * 	the JS-side callbacks from the update() using the UpdateActions queue.
 *
 *
 *  *** Shutdown ***
 *  Prior to unloading a plugin, it's shutdown() method will be called to give
 *  you a chance to clean up.
 *
 *  *** Destruction ***
 *  The final step before closing the library will be a call to destroy_object,
 *  passing in the plugin instance.
 *
 *
 *
 */
class @PLUGIN_CLASS@ : public Coraline::Plugin::Base
{

public:
	@PLUGIN_CLASS@(const Coraline::Plugin::Context & ctx);

	/*
	 * naming... Required overrides
	 * fullName() returns a unique name, normally the cordova-plugin-whatever
	 * used by the config.xml, e.g. cordova-plugin-ble-central
	 *
	 * shortName() returns a short single-word string, that is used in
	 * javascript and to determine the name of the directory for external
	 * resources, e.g. BLE
	 */
    virtual const Coraline::PluginName fullName() { return "@PLUGIN_FULLNAME@"; }
    virtual const Coraline::PluginName shortName() { return "@PLUGIN_CLASS@";}


    // optional lifecycle overrides
    virtual void startUp(); // startUp() called once to allow for init
    // virtual void update(); // update() -- system tick, called "often" -- don't hog CPU here
    virtual void shutdown(); // called once for cleanup


    /*
     * clientSideSupport*
     * Return either a filename (clientSideSupportFile()), within to the plugin
     * resource dir, or some raw JS (clientSideSupport()) to exec on plugin init.
     *
     */
	virtual Coraline::Plugin::ClientCodeFileName clientSideSupportFile();
	// virtual Coraline::Plugin::ClientCode clientSideSupport();

	virtual Coraline::Plugin::AboutString about();
	virtual Coraline::Plugin::AboutString usage();


    Coraline::Version version();

protected:
    // required override -- expose methods to dispatcher
    virtual void registerAllMethods();

private:
    // hello() sample callback -- all have same signature
	bool hello(const Coraline::Plugin::StandardCallbackIDs & callbacks,
            const Coraline::Plugin::ArgsList & args);


};

#endif /* INCLUDE_@PLUGIN_CLASS_ASUPPER@_PLUGIN_H_ */

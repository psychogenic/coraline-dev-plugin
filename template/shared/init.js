(function(){
	
	function @PLUGIN_SHORTNAME@ () {
		
	}
	@PLUGIN_SHORTNAME@.prototype.hello = function(success, fail) {
		cordova.exec(success, fail, "@PLUGIN_SHORTNAME@", "hello", []);
	}
	
	this.@PLUGIN_SHORTNAME@ = @PLUGIN_SHORTNAME@;
	
}).call(this);
(window.webpackJsonp=window.webpackJsonp||[]).push([["js/chunk/googleOneTap"],{a0bv:function(e,t,n){"use strict";n.r(t),n.d(t,"initTcfApi",(function(){return u}));var o=n("ejCh"),r=n.n(o),i=n("xpo+");function s(e,t,n,o,r,i,s){try{var c=e[i](s),a=c.value}catch(e){return void n(e)}c.done?t(a):Promise.resolve(a).then(o,r)}function c(e){return function(){var t=this,n=arguments;return new Promise((function(o,r){var i=e.apply(t,n);function c(e){s(i,o,r,c,a,"next",e)}function a(e){s(i,o,r,c,a,"throw",e)}c(void 0)}))}}c(regeneratorRuntime.mark((function e(){return regeneratorRuntime.wrap((function(e){for(;;)switch(e.prev=e.next){case 0:if(!document.querySelector(".page-landing-account-tunneling")){e.next=2;break}return e.abrupt("return");case 2:e.next=5;break;case 5:return e.next=7,Object(i.a)("https://accounts.google.com/gsi/client");case 7:google.accounts.id.initialize({client_id:_GLOBALS.google_one_tap_client_id,callback:function(){var e=c(regeneratorRuntime.mark((function e(t){var n,o,i,s;return regeneratorRuntime.wrap((function(e){for(;;)switch(e.prev=e.next){case 0:if(t.credential){e.next=2;break}return e.abrupt("return");case 2:return e.next=4,fetch(r.a.generate("google_one_tap_signin_check."+_GLOBALS.locale),{method:"POST",headers:new Headers({"X-Requested-With":"XMLHttpRequest"}),body:JSON.stringify({payload:t.credential})});case 4:return n=e.sent,e.next=7,n.json();case 7:if(o=e.sent,i=o.user,s=o.error,console.log("one tap json",o),"google_one_tap_error_auth_no_user_found"!==s){e.next=13;break}return window.location=r.a.generate("google_register."+_GLOBALS.locale),e.abrupt("return");case 13:if(i){e.next=16;break}return window.location=r.a.generate("google_register."+_GLOBALS.locale),e.abrupt("return");case 16:window.location.href="".concat(location.href.split("?")[0]);case 17:case"end":return e.stop()}}),e)})));return function(t){return e.apply(this,arguments)}}()}),google.accounts.id.prompt((function(e){console.log("notification",e)}));case 9:case"end":return e.stop()}}),e)})))();var a=0;function u(){return new Promise((function(e){var t=setInterval(c(regeneratorRuntime.mark((function n(){return regeneratorRuntime.wrap((function(n){for(;;)switch(n.prev=n.next){case 0:if("undefined"==typeof __tcfapi){n.next=5;break}return clearInterval(t),n.next=4,new Promise((function(e,t){__tcfapi("addEventListener",2,(function(n,o){if(o)try{switch(n.eventStatus){case"useractioncomplete":case"tcloaded":__tcfapi("removeEventListener",2,(function(){}),n.listenerId),e()}}catch(e){console.error("[OUTBRAIN] TCF API error",e)}else t()}))}));case 4:e();case 5:a>3e3&&clearInterval(t),a+=200;case 7:case"end":return n.stop()}}),n)}))),200)}))}},ejCh:function(e,t,n){var o,r,i;function s(e){return(s="function"==typeof Symbol&&"symbol"==typeof Symbol.iterator?function(e){return typeof e}:function(e){return e&&"function"==typeof Symbol&&e.constructor===Symbol&&e!==Symbol.prototype?"symbol":typeof e})(e)}!function(n){(c={}).__esModule=!0,c.Routing=c.Router=void 0,a=function(){function e(e,t){this.context_=e||{base_url:"",prefix:"",host:"",port:"",scheme:"",locale:""},this.setRoutes(t||{})}return e.getInstance=function(){return c.Routing},e.setData=function(t){e.getInstance().setRoutingData(t)},e.prototype.setRoutingData=function(e){this.setBaseUrl(e.base_url),this.setRoutes(e.routes),void 0!==e.prefix&&this.setPrefix(e.prefix),void 0!==e.port&&this.setPort(e.port),void 0!==e.locale&&this.setLocale(e.locale),this.setHost(e.host),void 0!==e.scheme&&this.setScheme(e.scheme)},e.prototype.setRoutes=function(e){this.routes_=Object.freeze(e)},e.prototype.getRoutes=function(){return this.routes_},e.prototype.setBaseUrl=function(e){this.context_.base_url=e},e.prototype.getBaseUrl=function(){return this.context_.base_url},e.prototype.setPrefix=function(e){this.context_.prefix=e},e.prototype.setScheme=function(e){this.context_.scheme=e},e.prototype.getScheme=function(){return this.context_.scheme},e.prototype.setHost=function(e){this.context_.host=e},e.prototype.getHost=function(){return this.context_.host},e.prototype.setPort=function(e){this.context_.port=e},e.prototype.getPort=function(){return this.context_.port},e.prototype.setLocale=function(e){this.context_.locale=e},e.prototype.getLocale=function(){return this.context_.locale},e.prototype.buildQueryParams=function(e,t,n){var o,r=this,i=new RegExp(/\[\]$/);if(t instanceof Array)t.forEach((function(t,o){i.test(e)?n(e,t):r.buildQueryParams(e+"["+("object"==s(t)?o:"")+"]",t,n)}));else if("object"==s(t))for(o in t)this.buildQueryParams(e+"["+o+"]",t[o],n);else n(e,t)},e.prototype.getRoute=function(e){var t,n=[this.context_.prefix+e,e+"."+this.context_.locale,this.context_.prefix+e+"."+this.context_.locale,e];for(t in n)if(n[t]in this.routes_)return this.routes_[n[t]];throw new Error('The route "'+e+'" does not exist.')},e.prototype.generate=function(t,n,o){var r,i=this.getRoute(t),s=n||{},c=Object.assign({},s),a="",u=!0,f="";n=void 0===this.getPort()||null===this.getPort()?"":this.getPort();if(i.tokens.forEach((function(n){if("text"===n[0]&&"string"==typeof n[1])return a=e.encodePathComponent(n[1])+a,void(u=!1);if("variable"!==n[0])throw new Error('The token type "'+n[0]+'" is not supported.');6===n.length&&!0===n[5]&&(u=!1);var o=i.defaults&&!Array.isArray(i.defaults)&&"string"==typeof n[3]&&n[3]in i.defaults;if(!1===u||!o||"string"==typeof n[3]&&n[3]in s&&!Array.isArray(i.defaults)&&s[n[3]]!=i.defaults[n[3]]){var r,f=void 0;if("string"==typeof n[3]&&n[3]in s)f=s[n[3]],delete c[n[3]];else{if("string"!=typeof n[3]||!o||Array.isArray(i.defaults)){if(u)return;throw new Error('The route "'+t+'" requires the parameter "'+n[3]+'".')}f=i.defaults[n[3]]}(!0===f||!1===f||""===f)&&u||(r=e.encodePathComponent(f),a=n[1]+(r="null"===r&&null===f?"":r)+a),u=!1}else o&&"string"==typeof n[3]&&n[3]in c&&delete c[n[3]]})),""===a&&(a="/"),i.hosttokens.forEach((function(e){var t;"text"!==e[0]?"variable"===e[0]&&(e[3]in s?(t=s[e[3]],delete c[e[3]]):i.defaults&&!Array.isArray(i.defaults)&&e[3]in i.defaults&&(t=i.defaults[e[3]]),f=e[1]+t+f):f=e[1]+f})),a=this.context_.base_url+a,i.requirements&&"_scheme"in i.requirements&&this.getScheme()!=i.requirements._scheme?(r=f||this.getHost(),a=i.requirements._scheme+"://"+r+(-1<r.indexOf(":"+n)||""===n?"":":"+n)+a):void 0!==i.schemes&&void 0!==i.schemes[0]&&this.getScheme()!==i.schemes[0]?(r=f||this.getHost(),a=i.schemes[0]+"://"+r+(-1<r.indexOf(":"+n)||""===n?"":":"+n)+a):f&&this.getHost()!==f+(-1<f.indexOf(":"+n)||""===n?"":":"+n)?a=this.getScheme()+"://"+f+(-1<f.indexOf(":"+n)||""===n?"":":"+n)+a:!0===o&&(a=this.getScheme()+"://"+this.getHost()+(-1<this.getHost().indexOf(":"+n)||""===n?"":":"+n)+a),0<Object.keys(c).length){function p(t,n){n=null===(n="function"==typeof n?n():n)?"":n,h.push(e.encodeQueryComponent(t)+"="+e.encodeQueryComponent(n))}var l,h=[];for(l in c)c.hasOwnProperty(l)&&this.buildQueryParams(l,c[l],p);a=a+"?"+h.join("&")}return a},e.customEncodeURIComponent=function(e){return encodeURIComponent(e).replace(/%2F/g,"/").replace(/%40/g,"@").replace(/%3A/g,":").replace(/%21/g,"!").replace(/%3B/g,";").replace(/%2C/g,",").replace(/%2A/g,"*").replace(/\(/g,"%28").replace(/\)/g,"%29").replace(/'/g,"%27")},e.encodePathComponent=function(t){return e.customEncodeURIComponent(t).replace(/%3D/g,"=").replace(/%2B/g,"+").replace(/%21/g,"!").replace(/%7C/g,"|")},e.encodeQueryComponent=function(t){return e.customEncodeURIComponent(t).replace(/%3F/g,"?")},e}(),c.Router=a,c.Routing=new a,c.default=c.Routing;var c,a={Router:c.Router,Routing:c.Routing};r=[],o=a.Routing,void 0===(i="function"==typeof o?o.apply(t,r):o)||(e.exports=i)}()}}]);
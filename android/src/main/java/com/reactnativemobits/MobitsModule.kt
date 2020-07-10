package com.reactnativemobits

import br.com.mobits.frameworknepos.modelo.MBClienteNEPOS
import br.com.mobits.frameworknepos.MBFrameworkNEPOS
import br.com.mobits.frameworknepos.MBFrameworkNEPOSListener
import br.com.mobits.frameworknepos.MBFrameworkNEPOSAnalyticsListener
import com.facebook.react.bridge.*
import com.facebook.react.modules.core.DeviceEventManagerModule

class MobitsModule( private val reactContext: ReactApplicationContext) : ReactContextBaseJavaModule(reactContext) {

  override fun getName(): String { return "Mobits" }

  private var listener: Listener? = null

  private fun getSecureListener(): Listener {
    if ( listener !== null ) return listener as Listener
    listener = Listener( reactContext )
    return listener as Listener
  }

  @ReactMethod
  fun open( garage: Int, track: String, client: ReadableMap, promise: Promise ) {

    if ( !client.hasKey( "firstName" ) )
      return promise.reject( Exception( "name in client is required" ) )
    if ( !client.hasKey( "lastName" ) )
      return promise.reject( Exception( "name in client is required" ) )
    if ( !client.hasKey( "document" ) )
      return promise.reject( Exception( "document in client is required" ) )

    try {
      val mbClient =  MBClienteNEPOS()
      mbClient.nome = client.getString( "firstName" )
      mbClient.cpf = client.getString( "document" )
      mbClient.celular = client.getString( "phone" )
      mbClient.sobrenome = client.getString( "lastName" )
      mbClient.email = client.getString( "email" )

      val framework = MBFrameworkNEPOS.getInstance( currentActivity )
      framework.listener = getSecureListener()
      framework.analyticsListener = getSecureListener()
      framework.iniciar( garage, mbClient, track )
      reactContext.getJSModule( DeviceEventManagerModule.RCTDeviceEventEmitter::class.java )
        .emit( "start", Arguments.createArray() )
      promise.resolve( null )
    } catch ( e: Exception ) { promise.reject( e ) }
  }
}

class Listener( private val context: ReactApplicationContext ): MBFrameworkNEPOSListener, MBFrameworkNEPOSAnalyticsListener {

  override fun sucessoAoRealizarPagamento( var1: String?, var2: String?, var3: String?, var4: String?, var5: String?, var6: String?, var7: String?, var8: String?, var9: String?, var10: String?, var11: String?, var12: String? ) {
    context.getJSModule( DeviceEventManagerModule.RCTDeviceEventEmitter::class.java )
      .emit( "payment", Arguments.createArray() )
  }
  override fun sucessoAoAutenticar( token: String?, code: String?, key: String? ) {
    context.getJSModule( DeviceEventManagerModule.RCTDeviceEventEmitter::class.java )
      .emit( "auth", Arguments.createArray() )
  }
  override fun cartaoGravadoComBandeira( var1: String?, var2: String? ) {
    context.getJSModule( DeviceEventManagerModule.RCTDeviceEventEmitter::class.java )
      .emit( "card", Arguments.createArray() )
  }
  override fun erroAoRealizarPagamento( message: String? ) {
    context.getJSModule( DeviceEventManagerModule.RCTDeviceEventEmitter::class.java )
      .emit( "payment-error", Exception( message ) )
  }
  override fun erroAoAutenticar( message: String? ) {
    context.getJSModule( DeviceEventManagerModule.RCTDeviceEventEmitter::class.java )
      .emit( "auth-error", Exception( message ) )
  }
  override fun exibiuTela(p0: String?, p1: Boolean, p2: String?, p3: String?) {
    context.getJSModule( DeviceEventManagerModule.RCTDeviceEventEmitter::class.java )
      .emit( "open", Arguments.createArray() )
  }
  override fun realizouEvento(p0: String?, p1: String?, p2: String?, p3: Boolean, p4: String?, p5: String?) {
    context.getJSModule( DeviceEventManagerModule.RCTDeviceEventEmitter::class.java )
      .emit( "event", Arguments.createArray() )
  }
}

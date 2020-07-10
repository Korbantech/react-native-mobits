#import "Mobits.h"

@implementation Mobits

RCT_EXPORT_MODULE()

RCT_REMAP_METHOD(
  open,
  openWithGarege:( nonnull NSNumber* )garage
  withTrack:( nonnull NSString* )track
  withResolver:(RCTPromiseResolveBlock)resolve
  withRejecter:(RCTPromiseRejectBlock)reject
) {
  resolve( "ok" )
}

@end

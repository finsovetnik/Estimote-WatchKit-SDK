//
//  ESTBeaconManagerDelegate.h
//  EstimoteSDK
//
//  Version: 3.0.0
//  Copyright (c) 2015 Estimote. All rights reserved.
//

@class ESTBeaconManager;

@protocol ESTBeaconManagerDelegate <NSObject>

@optional

#pragma mark Monitoring Events
///--------------------------------------------------------------------
/// @name Monitoring Events
///--------------------------------------------------------------------


#pragma mark Authorization Change Events (new in iOS 8)
///--------------------------------------------------------------------
/// @name Authorization Change Events (new in iOS 8)
///--------------------------------------------------------------------

/**
 * Tells the delegate that the authorization status for the application changed.
 *
 * This method is called whenever the application's ability to use location services changes. Changes can occur because the user allowed or denied the use of location services for your application or for the system as a whole.
 *
 * If the authorization status is already known when you call the `requestWhenInUseAuthorization` or `requestAlwaysAuthorization` method, the beacon manager does not report the current authorization status to this method. The beacon manager only reports changes to the authorization status. For example, it calls this method when the status changes from `kCLAuthorizationStatusNotDetermined` to `kCLAuthorizationStatusAuthorizedWhenInUse`.
 */
- (void)beaconManager:(ESTBeaconManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

/**
 * Tells the delegate that a new region is being monitored.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region that is being monitored.
 */

- (void)beaconManager:(ESTBeaconManager *)manager
didStartMonitoringForRegion:(CLBeaconRegion *)region;

/**
 * Tells the delegate that a region monitoring error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region for which the error occurred.
 * @param error An error object describing why monitoring failed.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
monitoringDidFailForRegion:(CLBeaconRegion *)region
            withError:(NSError *)error;

/**
 * Tells the delegate that the user entered the specified region.
 *
 * Because regions are a shared application resource, every active beacon and location manager object delivers this message to its associated delegate. It does not matter which beacon or location manager actually registered the specified region. And if multiple beacon and location managers share a delegate object, that delegate receives the message multiple times.
 *
 *The region object provided may not be the same one that was registered. As a result, you should never perform pointer-level comparisons to determine equality. Instead, use the region's identifier string to determine if your delegate should respond.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region that was entered.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
       didEnterRegion:(CLBeaconRegion *)region;

/**
 * Tells the delegate that the user left the specified region.
 *
 * Because regions are a shared application resource, every active beacon and location manager object delivers this message to its associated delegate. It does not matter which beacon or location manager actually registered the specified region. And if multiple beacon and location managers share a delegate object, that delegate receives the message multiple times.
 *
 *The region object provided may not be the same one that was registered. As a result, you should never perform pointer-level comparisons to determine equality. Instead, use the region's identifier string to determine if your delegate should respond.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region that was exited.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
        didExitRegion:(CLBeaconRegion *)region;

/**
 * Tells the delegate about the state of the specified region.
 *
 * The beacon manager calls this method whenever there is a boundary transition for a region. It calls this method in addition to calling the `<beaconManager:didEnterRegion:>` and `<beaconManager:didExitRegion:>` methods. The beacon manager also calls this method in response to a call to its `<[ESTBeaconManager requestStateForRegion:]>` method, which runs asynchronously.
 *
 * @param manager The beacon manager object reporting the event.
 * @param state The state of the specified region: `CLRegionStateUnknown`, `CLRegionStateInside` or `CLRegionStateOutside`.
 * @param region The region which state was determined.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
    didDetermineState:(CLRegionState)state
            forRegion:(CLBeaconRegion *)region;

#pragma mark Ranging Events
///--------------------------------------------------------------------
/// @name Ranging Events
///--------------------------------------------------------------------

/**
 * Tells the delegate that one or more beacons are in range.
 *
 * @param manager The beacon manager object reporting the event.
 * @param beacons An array of `<ESTBeacon>` objects representing the beacons currently in range. You can use the information in these objects to determine the range of each beacon and its identifying information.
 * @param region The region that was used to range the beacons.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(CLBeaconRegion *)region;


/**
 * Tells the delegate that a region ranging error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region The region for which the error occurred.
 * @param error An error object describing why ranging failed.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
rangingBeaconsDidFailForRegion:(CLBeaconRegion *)region
            withError:(NSError *)error;

#pragma mark CoreBluetooth Discovery Events
///--------------------------------------------------------------------
/// @name CoreBluetooth Discovery Events
///--------------------------------------------------------------------

/**
 * Tells the delegate that one or more beacons were discovered in the vicinity of the device.
 *
 * @param manager The beacon manager object reporting the event.
 * @param beacons An array of `<ESTBeacon>` objects representing the beacons discovered.
 * @param region The region that was used to discover the beacons.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
   didDiscoverBeacons:(NSArray *)beacons
             inRegion:(CLBeaconRegion *)region;

/**
 * Tells the delegate that beacons discovery error occurred.
 *
 * @param manager The beacon manager object reporting the event.
 * @param region An error object describing why discovery failed.
 */
- (void)beaconManager:(ESTBeaconManager *)manager
didFailDiscoveryInRegion:(CLBeaconRegion *)region;

#pragma mark Advertising Events
///--------------------------------------------------------------------
/// @name Advertising Events
///--------------------------------------------------------------------

/**
 * Tells the delegate the the device started advertising as an iBeacon.
 *
 * @param manager The beacon manager object reporting the event.
 * @param error If an error occurred, this error object describes the error. If the operation completed successfully, the value is `nil`.
 */
- (void)beaconManagerDidStartAdvertising:(ESTBeaconManager *)manager
                                   error:(NSError *)error;


@end

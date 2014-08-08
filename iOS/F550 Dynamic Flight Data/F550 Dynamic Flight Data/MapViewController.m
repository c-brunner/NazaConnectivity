//
//  SecondViewController.m
//  F550 Dynamic Flight Data
//
//  Created by Christian Brunner on 20/06/14.
//  Copyright (c) 2014 Christian Brunner. All rights reserved.
//

#import "MapViewController.h"
#import "F550DynamicFlightData.h"
#import "CrumbPathView.h"

@interface MapViewController ()

@end

@implementation MapViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.dronePositionHome = [[MKPointAnnotation alloc] init];
    self.dronePositionLive = [[MKPointAnnotation alloc] init];
    
    F550DynamicFlightData* dynamicFlightData = [F550DynamicFlightData sharedDynamicFlightData];
    
    [dynamicFlightData addObserver:self forKeyPath:@"latitude" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"longitude" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"latitudeHome" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"longitudeHome" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"altitudeHome" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"altitudeBarometer" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"altitudeGps" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"altitudeRelative" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"speed" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"climbSpeedBarometer" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"climbSpeedGps" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"satellitesVisible" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"fixType" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"course" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"heading" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"headingNc" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"hdop" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"vdop" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"pitch" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"roll" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"voltageBattery" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"currentBattery" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"consumedBattery" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"flightMode" options:NSKeyValueObservingOptionNew context:nil];

    [dynamicFlightData addObserver:self forKeyPath:@"rcA" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"rcE" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"rcR" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"rcU" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"rcT" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"rcX1" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"rcX2" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"m1" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"m2" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"m3" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"m4" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"m5" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"m6" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"f1" options:NSKeyValueObservingOptionNew context:nil];
    [dynamicFlightData addObserver:self forKeyPath:@"f2" options:NSKeyValueObservingOptionNew context:nil];
    
    [dynamicFlightData addObserver:self forKeyPath:@"isConnected" options:NSKeyValueObservingOptionNew context:nil];

    [self updateConnection:dynamicFlightData];
    [self updateLatitudeLongitude:dynamicFlightData];
    [self updateAltitudeBarometer:dynamicFlightData];
    [self updateAltitudeGps:dynamicFlightData];
    [self updateAltitudeRelative:dynamicFlightData];
    [self updateSpeed:dynamicFlightData];
    [self updateClimbSpeedBarometer:dynamicFlightData];
    [self updateClimbSpeedGps:dynamicFlightData];
    [self updateCourse:dynamicFlightData];
    [self updateHeading:dynamicFlightData];
    [self updateHeadingNc:dynamicFlightData];
    [self updatePitch:dynamicFlightData];
    [self updateRoll:dynamicFlightData];
    [self updateFixType:dynamicFlightData];
    [self updateSatellitesVisible:dynamicFlightData];
    [self updateHdop:dynamicFlightData];
    [self updateVdop:dynamicFlightData];
    [self updateFlightMode:dynamicFlightData];
    [self updateLatitudeLongitudeHome:dynamicFlightData];
    [self updateAltitudeHome:dynamicFlightData];
    [self updateVoltageBattery:dynamicFlightData];
    [self updateCurrentBattery:dynamicFlightData];
    [self updateConsumedBattery:dynamicFlightData];
    [self updateRcA:dynamicFlightData];
    [self updateRcR:dynamicFlightData];
    [self updateRcE:dynamicFlightData];
    [self updateRcU:dynamicFlightData];
    [self updateRcT:dynamicFlightData];
    [self updateRcX1:dynamicFlightData];
    [self updateRcX2:dynamicFlightData];
    [self updateM1:dynamicFlightData];
    [self updateM2:dynamicFlightData];
    [self updateM3:dynamicFlightData];
    [self updateM4:dynamicFlightData];
    [self updateM5:dynamicFlightData];
    [self updateM6:dynamicFlightData];
    [self updateF1:dynamicFlightData];
    [self updateF2:dynamicFlightData];
    
    MKCoordinateRegion region;
    region.center = CLLocationCoordinate2DMake(46.8029390, 13.4981589);
    region.span = MKCoordinateSpanMake(0.00725, 0.00725);
    
    self.dronePositionHome.coordinate = region.center;
    self.dronePositionLive.coordinate = region.center;
    
    [self.Map setMapType:MKMapTypeHybrid];
    [self.Map addAnnotation:self.dronePositionHome];
    [self.Map addAnnotation:self.dronePositionLive];
    [self.Map setRegion:region animated:true];
    
    self.crumpPathView = nil;
    self.crumpPath = [[CrumbPath alloc] initWithCenterCoordinate:region.center];
    
    self.Map.delegate = self;
    [self.Map addOverlay:self.crumpPath];
    
}

-(void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (void)clear
{
    [self.Map removeOverlay:self.crumpPath];
    self.crumpPathView = nil;
    
    self.crumpPath = [[CrumbPath alloc] initWithCenterCoordinate:CLLocationCoordinate2DMake(46.8029390, 13.4981589)];
    [self.Map addOverlay:self.crumpPath];
}


- (MKOverlayView *)mapView:(MKMapView *)mapView viewForOverlay:(id <MKOverlay>)overlay
{
    if ([overlay isKindOfClass:CrumbPath.class])
    {
        if (!self.crumpPathView)
        {
            self.crumpPathView = [[CrumbPathView alloc] initWithOverlay:overlay];
        }
        return self.crumpPathView;
    }
    
    return nil;
}

/*- (MKOverlayRenderer *)mapView:(MKMapView *)mapView rendererForOverlay:(id<MKOverlay>)overlay
{
    if ([overlay isKindOfClass:MKPolyline.class])
    {
        MKPolylineRenderer *lineRenderer = [[MKPolylineRenderer alloc] initWithOverlay:overlay];
        lineRenderer.strokeColor = [UIColor greenColor];
        lineRenderer.lineWidth = 1.0f;
        
        return lineRenderer;
    }
    
    return nil;
}*/

-(void)updateConnection:(F550DynamicFlightData*) dynamicFlightData
{
    if (dynamicFlightData.isConnected)
        self.isConnected.text = @"online";
    else
        self.isConnected.text = @"offline";
}

-(void)updateLatitudeLongitude:(F550DynamicFlightData*) dynamicFlightData
{
    MKCoordinateRegion region;
    region.center = CLLocationCoordinate2DMake(dynamicFlightData.latitude / 10000000.0f, dynamicFlightData.longitude / 10000000.0f);
    region.span = MKCoordinateSpanMake(0.00725, 0.00725);
    self.dronePositionLive.coordinate = region.center;
    
/*    CLLocation* location = [[CLLocation alloc]
                                initWithCoordinate:CLLocationCoordinate2DMake(dynamicFlightData.latitude / 10000000.0f, dynamicFlightData.longitude / 10000000.0f)
                                altitude:dynamicFlightData.altitudeBarometer
                                horizontalAccuracy:dynamicFlightData.hdop / 100.0f
                                verticalAccuracy:dynamicFlightData.vdop / 100.0f
                                course:dynamicFlightData.course / 100.0f
                                speed:dynamicFlightData.speed / 100.0f
                                timestamp:[[NSDate alloc] init]
                           ];
  */
    if (dynamicFlightData.fixType != 0)
    {
        
        MKMapRect updateRect = [self.crumpPath addCoordinate:region.center];
        
        if (!MKMapRectIsNull(updateRect))
        {
            // There is a non null update rect.
            // Compute the currently visible map zoom scale
            MKZoomScale currentZoomScale = (CGFloat)(self.Map.bounds.size.width / self.Map.visibleMapRect.size.width);
            // Find out the line width at this zoom scale and outset the updateRect by that amount
            CGFloat lineWidth = MKRoadWidthAtZoomScale(currentZoomScale);
            updateRect = MKMapRectInset(updateRect, -lineWidth, -lineWidth);
            // Ask the overlay view to update just the changed area.
            [self.crumpPathView setNeedsDisplayInMapRect:updateRect];
        }
    }
    
}

-(void)updateAltitudeBarometer:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateAltitudeGps:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateAltitudeRelative:(F550DynamicFlightData*) dynamicFlightData
{
    self.altitude.text = [[NSString alloc] initWithFormat:@"Altitude: %.2f m", dynamicFlightData.altitudeRelative / 1000.0f];
}

-(void)updateSpeed:(F550DynamicFlightData*) dynamicFlightData
{
    self.speed.text = [[NSString alloc] initWithFormat:@"Speed: %.2f m/s", dynamicFlightData.speed / 100.0f];
}

-(void)updateClimbSpeedBarometer:(F550DynamicFlightData*) dynamicFlightData
{
    self.climbSpeed.text = [[NSString alloc] initWithFormat:@"Ascending: %.2f m/s", dynamicFlightData.climbSpeedBarometer / 100.0f];
}

-(void)updateClimbSpeedGps:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateCourse:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateHeading:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateHeadingNc:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updatePitch:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateRoll:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateFixType:(F550DynamicFlightData*) dynamicFlightData
{
    if (dynamicFlightData.fixType == 0)
        self.fixType.text = @"NO FIX";
    else if (dynamicFlightData.fixType == 2)
        self.fixType.text = @"2D";
    else if (dynamicFlightData.fixType == 3)
        self.fixType.text = @"3D";
    else if (dynamicFlightData.fixType == 4)
        self.fixType.text = @"DGPS";
    else
        self.fixType.text = @"UNKNOWN FIX";
}

-(void)updateSatellitesVisible:(F550DynamicFlightData*) dynamicFlightData
{
    self.satellitesVisible.text = [[NSString alloc] initWithFormat:@"Satellites: %d", dynamicFlightData.satellitesVisible];
}

-(void)updateHdop:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateVdop:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateFlightMode:(F550DynamicFlightData*) dynamicFlightData
{
    if (dynamicFlightData.flightMode == 0)
        self.flightMode .text = @"MANUAL";
    else if (dynamicFlightData.flightMode == 1)
        self.flightMode.text = @"GPS";
    else if (dynamicFlightData.flightMode == 2)
        self.flightMode.text = @"FAILSAFE";
    else if (dynamicFlightData.flightMode == 3)
        self.flightMode.text = @"ATTI";
    else
        self.flightMode.text = @"??";
}

-(void)updateLatitudeLongitudeHome:(F550DynamicFlightData*) dynamicFlightData
{
    MKCoordinateRegion region;
    region.center = CLLocationCoordinate2DMake(dynamicFlightData.latitudeHome / 10000000.0f, dynamicFlightData.longitudeHome / 10000000.0f);
    region.span = MKCoordinateSpanMake(0.00725, 0.00725);
    
    self.dronePositionHome.coordinate = region.center;
}

-(void)updateAltitudeHome:(F550DynamicFlightData*) dynamicFlightData
{
}


-(void)updateVoltageBattery:(F550DynamicFlightData*) dynamicFlightData
{
    self.voltageBattery.text = [[NSString alloc] initWithFormat:@"Battery: %.2f V", dynamicFlightData.voltageBattery / 1000.0f];
}

-(void)updateCurrentBattery:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateConsumedBattery:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateRcA:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateRcR:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateRcE:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateRcU:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateRcT:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateRcX1:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateRcX2:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateM1:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateM2:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateM3:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateM4:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateM5:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateM6:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateF1:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)updateF2:(F550DynamicFlightData*) dynamicFlightData
{
}

-(void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{    
    F550DynamicFlightData* dynamicFlightData = [F550DynamicFlightData sharedDynamicFlightData];
    
    if ([keyPath isEqualToString:@"isConnected"])
    {
        [self updateConnection:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"latitude"])
    {
        [self updateLatitudeLongitude:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"longitude"])
    {
        [self updateLatitudeLongitude:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"altitudeBarometer"])
    {
        [self updateAltitudeBarometer:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"altitudeGps"])
    {
        [self updateAltitudeGps:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"altitudeRelative"])
    {
        [self updateAltitudeRelative:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"speed"])
    {
        [self updateSpeed:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"climbSpeedBarometer"])
    {
        [self updateClimbSpeedBarometer:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"climbSpeedGps"])
    {
        [self updateClimbSpeedGps:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"course"])
    {
        [self updateCourse:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"heading"])
    {
        [self updateHeading:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"headingNc"])
    {
        [self updateHeadingNc:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"pitch"])
    {
        [self updatePitch:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"roll"])
    {
        [self updateRoll:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"fixType"])
    {
        [self updateFixType:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"satellitesVisible"])
    {
        [self updateSatellitesVisible:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"hdop"])
    {
        [self updateHdop:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"vdop"])
    {
        [self updateVdop:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"flightMode"])
    {
        [self updateFlightMode:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"latitudeHome"])
    {
        [self updateLatitudeLongitudeHome:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"longitudeHome"])
    {
        [self updateLatitudeLongitudeHome:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"altitudeHome"])
    {
        [self updateAltitudeHome:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"voltageBattery"])
    {
        [self updateVoltageBattery:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"currentBattery"])
    {
        [self updateCurrentBattery:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"consumedBattery"])
    {
        [self updateConsumedBattery:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"rcA"])
    {
        [self updateRcA:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"rcR"])
    {
        [self updateRcR:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"rcE"])
    {
        [self updateRcE:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"rcU"])
    {
        [self updateRcU:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"rcT"])
    {
        [self updateRcT:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"rcX1"])
    {
        [self updateRcX1:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"rcX2"])
    {
        [self updateRcX2:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"m1"])
    {
        [self updateM1:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"m2"])
    {
        [self updateM2:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"m3"])
    {
        [self updateM3:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"m4"])
    {
        [self updateM4:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"m5"])
    {
        [self updateM5:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"m6"])
    {
        [self updateM6:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"f1"])
    {
        [self updateM6:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"f2"])
    {
        [self updateM6:dynamicFlightData];
    }
    else
    {
        NSLog(@"unhandled key: %@", keyPath);
    }
}

@end

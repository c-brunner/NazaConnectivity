//
//  SecondViewController.h
//  F550 Dynamic Flight Data
//
//  Created by Christian Brunner on 20/06/14.
//  Copyright (c) 2014 Christian Brunner. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

#import "CrumbPath.h"
#import "CrumbPathView.h"

@interface MapViewController : UIViewController <MKMapViewDelegate>

@property (weak, nonatomic) IBOutlet MKMapView *Map;
@property (weak, nonatomic) IBOutlet UILabel *voltageBattery;
@property (weak, nonatomic) IBOutlet UILabel *isConnected;
@property (weak, nonatomic) IBOutlet UILabel *altitude;
@property (weak, nonatomic) IBOutlet UILabel *flightMode;
@property (weak, nonatomic) IBOutlet UILabel *speed;
@property (weak, nonatomic) IBOutlet UILabel *climbSpeed;
@property (weak, nonatomic) IBOutlet UILabel *fixType;
@property (weak, nonatomic) IBOutlet UILabel *satellitesVisible;

@property MKPointAnnotation *dronePositionHome;
@property MKPointAnnotation *dronePositionLive;
@property CrumbPath* crumpPath;
@property CrumbPathView* crumpPathView;

- (void)clear;

@end

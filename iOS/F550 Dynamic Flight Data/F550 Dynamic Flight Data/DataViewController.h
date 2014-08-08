//
//  DataViewController.h
//  F550 Dynamic Flight Data
//
//  Created by Christian Brunner on 22/06/14.
//  Copyright (c) 2014 Christian Brunner. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DataViewController : UITableViewController


@property (weak, nonatomic) IBOutlet UILabel *latitudeLongitude;
@property (weak, nonatomic) IBOutlet UILabel *altitudeBarometer;
@property (weak, nonatomic) IBOutlet UILabel *altitudeGps;
@property (weak, nonatomic) IBOutlet UILabel *altitudeRelative;
@property (weak, nonatomic) IBOutlet UILabel *speed;
@property (weak, nonatomic) IBOutlet UILabel *climbSpeedBarometer;
@property (weak, nonatomic) IBOutlet UILabel *climbSpeedGps;
@property (weak, nonatomic) IBOutlet UILabel *course;
@property (weak, nonatomic) IBOutlet UILabel *heading;
@property (weak, nonatomic) IBOutlet UILabel *headingNc;
@property (weak, nonatomic) IBOutlet UILabel *pitch;
@property (weak, nonatomic) IBOutlet UILabel *roll;
@property (weak, nonatomic) IBOutlet UILabel *fixType;
@property (weak, nonatomic) IBOutlet UILabel *satellitesVisible;
@property (weak, nonatomic) IBOutlet UILabel *hdop;
@property (weak, nonatomic) IBOutlet UILabel *vdop;
@property (weak, nonatomic) IBOutlet UILabel *flightMode;
@property (weak, nonatomic) IBOutlet UILabel *latitudeLongitudeHome;
@property (weak, nonatomic) IBOutlet UILabel *altitudeHome;
@property (weak, nonatomic) IBOutlet UILabel *voltageBattery;
@property (weak, nonatomic) IBOutlet UILabel *currentBattery;
@property (weak, nonatomic) IBOutlet UILabel *consumedBattery;
@property (weak, nonatomic) IBOutlet UILabel *rcA;
@property (weak, nonatomic) IBOutlet UILabel *rcR;
@property (weak, nonatomic) IBOutlet UILabel *rcE;
@property (weak, nonatomic) IBOutlet UILabel *rcU;
@property (weak, nonatomic) IBOutlet UILabel *rcT;
@property (weak, nonatomic) IBOutlet UILabel *rcX1;
@property (weak, nonatomic) IBOutlet UILabel *rcX2;
@property (weak, nonatomic) IBOutlet UILabel *m1;
@property (weak, nonatomic) IBOutlet UILabel *m2;
@property (weak, nonatomic) IBOutlet UILabel *m3;
@property (weak, nonatomic) IBOutlet UILabel *m4;
@property (weak, nonatomic) IBOutlet UILabel *m5;
@property (weak, nonatomic) IBOutlet UILabel *m6;
@property (weak, nonatomic) IBOutlet UILabel *f1;
@property (weak, nonatomic) IBOutlet UILabel *f2;

@end

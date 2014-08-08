//
//  DataViewController.m
//  F550 Dynamic Flight Data
//
//  Created by Christian Brunner on 22/06/14.
//  Copyright (c) 2014 Christian Brunner. All rights reserved.
//

#import "DataViewController.h"
#import "F550DynamicFlightData.h"


@interface DataViewController ()

@end

@implementation DataViewController

- (instancetype)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
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

    self.edgesForExtendedLayout=UIRectEdgeNone;
    self.extendedLayoutIncludesOpaqueBars=NO;
    self.automaticallyAdjustsScrollViewInsets=NO;
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;

    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)updateConnection:(F550DynamicFlightData*) dynamicFlightData
{
 //   if (dynamicFlightData.isConnected)
   //     self.Connection.text = @"online";
   // else
     //   self.Connection.text = @"offline";
}

-(void)updateLatitudeLongitude:(F550DynamicFlightData*) dynamicFlightData
{
    self.latitudeLongitude.text = [[NSString alloc] initWithFormat:@"[%.7f, %.7f]", dynamicFlightData.latitude / 10000000.0f, dynamicFlightData.longitude / 10000000.0f];
}

-(void)updateAltitudeBarometer:(F550DynamicFlightData*) dynamicFlightData
{
    self.altitudeBarometer.text = [[NSString alloc] initWithFormat:@"%.2f m", dynamicFlightData.altitudeBarometer / 1000.0f];
}

-(void)updateAltitudeGps:(F550DynamicFlightData*) dynamicFlightData
{
    self.altitudeGps.text = [[NSString alloc] initWithFormat:@"%.2f m", dynamicFlightData.altitudeGps / 1000.0f];
}

-(void)updateAltitudeRelative:(F550DynamicFlightData*) dynamicFlightData
{
    self.altitudeRelative.text = [[NSString alloc] initWithFormat:@"%.2f m", dynamicFlightData.altitudeRelative / 1000.0f];
}

-(void)updateSpeed:(F550DynamicFlightData*) dynamicFlightData
{
    self.speed.text = [[NSString alloc] initWithFormat:@"%.2f m/s", dynamicFlightData.speed / 100.0f];
}

-(void)updateClimbSpeedBarometer:(F550DynamicFlightData*) dynamicFlightData
{
    self.climbSpeedBarometer.text = [[NSString alloc] initWithFormat:@"%.2f m/s", dynamicFlightData.climbSpeedBarometer / 100.0f];
}

-(void)updateClimbSpeedGps:(F550DynamicFlightData*) dynamicFlightData
{
    self.climbSpeedGps.text = [[NSString alloc] initWithFormat:@"%.2f m/s", dynamicFlightData.climbSpeedGps / 10000.0f];
}

-(void)updateCourse:(F550DynamicFlightData*) dynamicFlightData
{
    self.course.text = [[NSString alloc] initWithFormat:@"%.2f Deg", dynamicFlightData.course / 100.0f];
}

-(void)updateHeading:(F550DynamicFlightData*) dynamicFlightData
{
    self.heading.text = [[NSString alloc] initWithFormat:@"%.2f Deg", dynamicFlightData.heading / 100.0f];
}

-(void)updateHeadingNc:(F550DynamicFlightData*) dynamicFlightData
{
    self.headingNc.text = [[NSString alloc] initWithFormat:@"%.2f Deg", dynamicFlightData.headingNc / 100.0f];
}

-(void)updatePitch:(F550DynamicFlightData*) dynamicFlightData
{
    self.pitch.text = [[NSString alloc] initWithFormat:@"%d Deg", dynamicFlightData.pitch];
}

-(void)updateRoll:(F550DynamicFlightData*) dynamicFlightData
{
    self.roll.text = [[NSString alloc] initWithFormat:@"%d Deg", dynamicFlightData.roll];
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
    self.satellitesVisible.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.satellitesVisible];
}

-(void)updateHdop:(F550DynamicFlightData*) dynamicFlightData
{
    self.hdop.text = [[NSString alloc] initWithFormat:@"%.2f m", dynamicFlightData.hdop / 100.0f];
}

-(void)updateVdop:(F550DynamicFlightData*) dynamicFlightData
{
    self.vdop.text = [[NSString alloc] initWithFormat:@"%.2f m", dynamicFlightData.vdop / 100.0f];
}

-(void)updateFlightMode:(F550DynamicFlightData*) dynamicFlightData
{
    if (dynamicFlightData.flightMode == 0)
        self.flightMode.text = @"MANUAL";
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
    self.latitudeLongitudeHome.text = [[NSString alloc] initWithFormat:@"[%.7f, %.7f]", dynamicFlightData.latitudeHome / 10000000.0f, dynamicFlightData.longitudeHome / 10000000.0f];
}

-(void)updateAltitudeHome:(F550DynamicFlightData*) dynamicFlightData
{
    self.altitudeHome.text = [[NSString alloc] initWithFormat:@"%.2f m", (dynamicFlightData.altitudeHome) / 1000.0f];
}


-(void)updateVoltageBattery:(F550DynamicFlightData*) dynamicFlightData
{
    self.voltageBattery.text = [[NSString alloc] initWithFormat:@"%.2f V", dynamicFlightData.voltageBattery / 1000.0f];
}

-(void)updateCurrentBattery:(F550DynamicFlightData*) dynamicFlightData
{
    self.currentBattery.text = [[NSString alloc] initWithFormat:@"%.2f V", dynamicFlightData.currentBattery / 1000.0f];
}

-(void)updateConsumedBattery:(F550DynamicFlightData*) dynamicFlightData
{
    self.consumedBattery.text = [[NSString alloc] initWithFormat:@"%.2f V", dynamicFlightData.consumedBattery / 1000.0f];
}

-(void)updateRcA:(F550DynamicFlightData*) dynamicFlightData
{
    self.rcA.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.rcA];
}

-(void)updateRcR:(F550DynamicFlightData*) dynamicFlightData
{
    self.rcR.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.rcR];
}

-(void)updateRcE:(F550DynamicFlightData*) dynamicFlightData
{
    self.rcE.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.rcE];
}

-(void)updateRcU:(F550DynamicFlightData*) dynamicFlightData
{
    self.rcU.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.rcU];
}

-(void)updateRcT:(F550DynamicFlightData*) dynamicFlightData
{
    self.rcT.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.rcT];
}

-(void)updateRcX1:(F550DynamicFlightData*) dynamicFlightData
{
    self.rcX1.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.rcX1];
}

-(void)updateRcX2:(F550DynamicFlightData*) dynamicFlightData
{
    self.rcX2.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.rcX2];
}

-(void)updateM1:(F550DynamicFlightData*) dynamicFlightData
{
    self.m1.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.m1];
}

-(void)updateM2:(F550DynamicFlightData*) dynamicFlightData
{
    self.m2.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.m2];
}

-(void)updateM3:(F550DynamicFlightData*) dynamicFlightData
{
    self.m3.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.m3];
}

-(void)updateM4:(F550DynamicFlightData*) dynamicFlightData
{
    self.m4.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.m4];
}

-(void)updateM5:(F550DynamicFlightData*) dynamicFlightData
{
    self.m5.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.m5];
}

-(void)updateM6:(F550DynamicFlightData*) dynamicFlightData
{
    self.m6.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.m6];
}

-(void)updateF1:(F550DynamicFlightData*) dynamicFlightData
{
    self.f1.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.f1];
}

-(void)updateF2:(F550DynamicFlightData*) dynamicFlightData
{
    self.f2.text = [[NSString alloc] initWithFormat:@"%d", dynamicFlightData.f2];
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
        [self updateF1:dynamicFlightData];
    }
    else if ([keyPath isEqualToString:@"f2"])
    {
        [self updateF2:dynamicFlightData];
    }
    else
    {
        NSLog(@"unhandled key: %@", keyPath);
    }
}

#pragma mark - Table view data source

/*
 - (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
#warning Potentially incomplete method implementation.
    // Return the number of sections.
    return 0;
}
*/

/*
 - (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
#warning Incomplete method implementation.
    // Return the number of rows in the section.
    return 0;
}
*/

/*
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:<#@"reuseIdentifier"#> forIndexPath:indexPath];
    
    // Configure the cell...
    
    return cell;
}
*/

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    } else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

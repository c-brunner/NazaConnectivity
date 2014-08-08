//
//  GPXParser.m
//  GPX Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import "GPXParser.h"
#import "GPXConst.h"
#import "GPXElementSubclass.h"
#import "GPXRoot.h"
#import "GPXXML.h"

@implementation GPXParser


#pragma mark - Instance

+ (GPXRoot *)parseGPXAtURL:(NSURL *)url
{
    GPXXML *xml = [[GPXXML alloc] initWithURL:url];
    if (xml.rootXMLElement) {
        return [[GPXRoot alloc] initWithXMLElement:xml.rootXMLElement parent:nil];
    }
    
    return nil;
}

+ (GPXRoot *)parseGPXAtPath:(NSString *)path
{
    NSURL *url = [NSURL fileURLWithPath:path];
    return [GPXParser parseGPXAtURL:url];
}

+ (GPXRoot *)parseGPXWithString:(NSString*)string
{
    GPXXML *xml = [[GPXXML alloc] initWithXMLString:string];
    if (xml.rootXMLElement) {
        return [[GPXRoot alloc] initWithXMLElement:xml.rootXMLElement parent:nil];
    }
    
    return nil;
}

+ (GPXRoot *)parseGPXWithData:(NSData*)data
{
    GPXXML *xml = [[GPXXML alloc] initWithXMLData:data];
    if (xml.rootXMLElement) {
        return [[GPXRoot alloc] initWithXMLElement:xml.rootXMLElement parent:nil];
    }
    
    return nil;
}

@end

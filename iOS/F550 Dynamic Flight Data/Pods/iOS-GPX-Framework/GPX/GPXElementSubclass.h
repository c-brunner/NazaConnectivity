//
//  GPXElementSubclass.h
//  GPX Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import "GPXElement.h"
#import "GPXXML.h"

@interface GPXElement ()

// Tag

+ (NSString *)tagName;
+ (NSArray *)implementClasses;


// Initializing a Element

- (id)initWithXMLElement:(GPXXMLElement *)element parent:(GPXElement *)parent;


// Parsing
- (NSString *)valueOfAttributeNamed:(NSString *)name xmlElement:(GPXXMLElement*)element;
- (NSString *)valueOfAttributeNamed:(NSString *)name xmlElement:(GPXXMLElement*)element required:(BOOL)required;
- (NSString *)textForSingleChildElementNamed:(NSString *)name xmlElement:(GPXXMLElement *)element;
- (NSString *)textForSingleChildElementNamed:(NSString *)name xmlElement:(GPXXMLElement *)element required:(BOOL)required;
- (GPXElement *)childElementOfClass:(Class)class xmlElement:(GPXXMLElement *)element;
- (GPXElement *)childElementOfClass:(Class)class xmlElement:(GPXXMLElement *)element required:(BOOL)required;
- (GPXElement *)childElementNamed:(NSString *)name class:(Class)class xmlElement:(GPXXMLElement *)element;
- (GPXElement *)childElementNamed:(NSString *)name class:(Class)class xmlElement:(GPXXMLElement *)element required:(BOOL)required;
- (void)childElementsOfClass:(Class)class xmlElement:(GPXXMLElement *)element eachBlock:(void (^)(GPXElement *element))eachBlock;


// Generating

- (void)gpx:(NSMutableString *)gpx indentationLevel:(NSInteger)indentationLevel;
- (void)addOpenTagToGpx:(NSMutableString *)gpx indentationLevel:(NSInteger)indentationLevel;
- (void)addChildTagToGpx:(NSMutableString *)gpx indentationLevel:(NSInteger)indentationLevel;
- (void)addCloseTagToGpx:(NSMutableString *)gpx indentationLevel:(NSInteger)indentationLevel;

- (void)gpx:(NSMutableString *)gpx addPropertyForValue:(NSString *)value tagName:(NSString *)tagName indentationLevel:(NSInteger)indentationLevel;
- (void)gpx:(NSMutableString *)gpx addPropertyForValue:(NSString *)value tagName:(NSString *)tagName attribute:(NSString *)attribute indentationLevel:(NSInteger)indentationLevel;
- (void)gpx:(NSMutableString *)gpx addPropertyForValue:(NSString *)value defaultValue:(NSString *)defaultValue tagName:(NSString *)tagName indentationLevel:(NSInteger)indentationLevel;
- (void)gpx:(NSMutableString *)gpx addPropertyForValue:(NSString *)value defaultValue:(NSString *)defaultValue tagName:(NSString *)tagName attribute:(NSString *)attribute indentationLevel:(NSInteger)indentationLevel;
- (NSString *)indentForIndentationLevel:(NSInteger)indentationLevel;

@end

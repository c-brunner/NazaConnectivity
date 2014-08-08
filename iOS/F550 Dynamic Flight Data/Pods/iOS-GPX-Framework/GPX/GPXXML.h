// ================================================================================================
//  GPXXML.h
//  Fast processing of XML files
//
// ================================================================================================
//  Created by Tom Bradley on 21/10/2009.
//  Version 1.4
//  
//  Copyright (c) 2009 Tom Bradley
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
// ================================================================================================


#define MAX_ELEMENTS 100
#define MAX_ATTRIBUTES 100

#define GPXXML_ATTRIBUTE_NAME_START 0
#define GPXXML_ATTRIBUTE_NAME_END 1
#define GPXXML_ATTRIBUTE_VALUE_START 2
#define GPXXML_ATTRIBUTE_VALUE_END 3
#define GPXXML_ATTRIBUTE_CDATA_END 4

typedef struct _GPXXMLAttribute {
	char * name;
	char * value;
	struct _GPXXMLAttribute * next;
} GPXXMLAttribute;

typedef struct GPXXMLElement {
	char * name;
	char * text;
	
	GPXXMLAttribute * firstAttribute;
	
	struct GPXXMLElement * parentElement;
	
	struct GPXXMLElement * firstChild;
	struct GPXXMLElement * currentChild;
	
	struct GPXXMLElement * nextSibling;
	struct GPXXMLElement * previousSibling;
	
} GPXXMLElement;

typedef struct _GPXXMLElementBuffer {
	GPXXMLElement * elements;
	struct _GPXXMLElementBuffer * next;
	struct _GPXXMLElementBuffer * previous;
} GPXXMLElementBuffer;

typedef struct _GPXXMLAttributeBuffer {
	GPXXMLAttribute * attributes;
	struct _GPXXMLAttributeBuffer * next;
	struct _GPXXMLAttributeBuffer * previous;
} GPXXMLAttributeBuffer;


@interface GPXXML : NSObject {
	
@private
	GPXXMLElement * rootXMLElement;
	
	GPXXMLElementBuffer * currentElementBuffer;
	GPXXMLAttributeBuffer * currentAttributeBuffer;
	
	long currentElement;
	long currentAttribute;
	
	char * bytes;
	long bytesLength;
}

@property (nonatomic, readonly) GPXXMLElement * rootXMLElement;

+ (id)tbxmlWithURL:(NSURL*)aURL;
+ (id)tbxmlWithXMLString:(NSString*)aXMLString;
+ (id)tbxmlWithXMLData:(NSData*)aData;

- (id)initWithURL:(NSURL*)aURL;
- (id)initWithXMLString:(NSString*)aXMLString;
- (id)initWithXMLData:(NSData*)aData;

@end

@interface GPXXML (StaticFunctions)

+ (NSString*) elementName:(GPXXMLElement*)aXMLElement;
+ (NSString*) textForElement:(GPXXMLElement*)aXMLElement;
+ (NSString*) valueOfAttributeNamed:(NSString *)aName forElement:(GPXXMLElement*)aXMLElement;

+ (NSString*) attributeName:(GPXXMLAttribute*)aXMLAttribute;
+ (NSString*) attributeValue:(GPXXMLAttribute*)aXMLAttribute;

+ (GPXXMLElement*) nextSiblingNamed:(NSString*)aName searchFromElement:(GPXXMLElement*)aXMLElement;
+ (GPXXMLElement*) childElementNamed:(NSString*)aName parentElement:(GPXXMLElement*)aParentXMLElement;

@end

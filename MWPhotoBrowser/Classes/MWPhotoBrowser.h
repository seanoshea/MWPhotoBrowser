//
//  MWPhotoBrowser.h
//  MWPhotoBrowser
//
//  Created by Michael Waterfall on 14/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "MWPhoto.h"
#import "MWPhotoProtocol.h"
#import "MWCaptionView.h"

// Debug Logging
#if 0 // Set to 1 to enable debug logging
#define MWLog(x, ...) NSLog(x, ## __VA_ARGS__);
#else
#define MWLog(x, ...)
#endif

// Delgate
@class MWPhotoBrowser;
@protocol MWPhotoBrowserDelegate <NSObject>
- (NSUInteger)numberOfPhotosInPhotoBrowser:(MWPhotoBrowser *)photoBrowser;
- (id<MWPhoto>)photoBrowser:(MWPhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index;
@optional
- (MWCaptionView *)photoBrowser:(MWPhotoBrowser *)photoBrowser captionViewForPhotoAtIndex:(NSUInteger)index;
- (void)navigationUpdatedWithCurrentIndex:(NSUInteger)currentIndex;
- (void)loadingImage;
- (void)loadedImage:(id<MWPhoto>)photo;
- (void)handleLongPress;
@end

// MWPhotoBrowser
@interface MWPhotoBrowser : UIViewController <UIScrollViewDelegate, UIActionSheetDelegate, MFMailComposeViewControllerDelegate> 

// Properties
@property (nonatomic) BOOL neverHideControls;
@property (nonatomic) BOOL displayActionButton;
@property (nonatomic) BOOL displayActionBar;
@property (nonatomic, strong) UIColor *backgroundColorForPages;
@property (nonatomic, strong) UIColor *navigationBarTintColor;
@property (nonatomic, readonly) NSInteger currentPageIndex;

// Init
- (id)initWithPhotos:(NSArray *)photosArray  __attribute__((deprecated)); // Depreciated
- (id)initWithDelegate:(id <MWPhotoBrowserDelegate>)delegate;

// Reloads the photo browser and refetches data
- (void)reloadData;

// Set page that photo browser starts on
- (void)setInitialPageIndex:(NSUInteger)index;

// Navigation Bar Controls
- (void)setControlsHidden:(BOOL)hidden animated:(BOOL)animated permanent:(BOOL)permanent;

// HUD Controls
- (void)showProgressHUDWithMessage:(NSString *)message;
- (void)hideProgressHUD:(BOOL)animated;

// Image Gesture Recognizers
- (void)handleLongPress;

// Actions
- (void)savePhoto;

// Retrieving photos
- (id<MWPhoto>)photoAtIndex:(NSUInteger)index;

@end



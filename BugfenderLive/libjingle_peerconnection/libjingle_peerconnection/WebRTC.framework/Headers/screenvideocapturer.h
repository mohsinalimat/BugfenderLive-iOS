/*
 *  Copyright 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_API_OBJC_SCREEN_VIDEO_CAPTURER_H_
#define WEBRTC_API_OBJC_SCREEN_VIDEO_CAPTURER_H_

#include "talk/media/base/videocapturer.h"
#include "webrtc/base/scoped_ptr.h"
#include "webrtc/video_frame.h"

#import <Foundation/Foundation.h>

@protocol RTCScreenVideoCapturerDelegate;

namespace webrtc {

class RTCScreenVideoCapturer : public cricket::VideoCapturer {
 public:
  RTCScreenVideoCapturer(id<RTCScreenVideoCapturerDelegate> cpt);
  ~RTCScreenVideoCapturer();

  cricket::CaptureState Start(const cricket::VideoFormat& format) override;
  void Stop() override;
  bool IsRunning() override;
  bool IsScreencast() const override {
    return true;
  }
  bool GetPreferredFourccs(std::vector<uint32_t> *fourccs) override {
    fourccs->push_back(cricket::FOURCC_NV12);
    return true;
  }

  /**
   * Converts the sample buffer into a cricket::CapturedFrame and signals the
   * frame for capture.
   */
  void CaptureSampleBuffer(cricket::CapturedFrame* frame);

 private:
  /**
   * Used to signal frame capture on the thread that capturer was started on.
   */
  void SignalFrameCapturedOnStartThread(const cricket::CapturedFrame *frame);

  id<RTCScreenVideoCapturerDelegate> _capturer;
  rtc::Thread *_startThread;  // Set in Start(), unset in Stop().
};  // RTCScreenVideoCapturer

}  // namespace webrtc

@protocol RTCScreenVideoCapturerDelegate <NSObject>

@property(nonatomic, readonly) BOOL isRunning;

- (void)setCapturer:(webrtc::RTCScreenVideoCapturer *)capturer;
- (void)startCaptureAsync;
- (void)stopCaptureAsync;

@end

#endif  // WEBRTC_API_OBJC_SCREEN_VIDEO_CAPTURER_H_

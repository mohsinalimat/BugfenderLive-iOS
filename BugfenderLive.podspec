Pod::Spec.new do |s|

  s.name         = "BugfenderLive"
  s.version      = "0.1.2"
  s.summary      = "Screen sharing to debug your mobile app"
  s.description  = <<-DESC
                  Bugfender Live lets customer support representatives see the screen of their users in real time. 
                   DESC
  s.homepage     = "https://bugfender.com/live"

  s.license      = { :type => "Commercial", :text => "See https://bugfender.com/terms-of-service/" }

  s.author = { "Bugfender" => "support@bugfender.com" }
  s.platform = :ios, "8.0"

  s.source       = { :git => "https://github.com/bugfender/BugfenderLive-iOS.git", :tag => "v#{s.version}" }

  s.ios.vendored_frameworks = ['Build/Release/BugfenderLive.framework', 'BugfenderLive/libjingle_peerconnection/libjingle_peerconnection/WebRTC.framework' ]
  s.frameworks = [ 'AudioToolbox', 'CoreAudio', 'VideoToolbox', 'GLKit', 'AVFoundation', 'CoreMedia' ]
  s.library = 'c++'
  s.dependency 'SocketRocket', '~> 0.4.1'
  s.dependency 'SBJson', '~> 4.0.2'
  s.dependency 'Reachability', '~> 3.2'
  s.dependency 'BugfenderSDK', '~> 0.3'

  s.requires_arc = true
end

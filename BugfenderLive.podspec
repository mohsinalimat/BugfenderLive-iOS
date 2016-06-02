Pod::Spec.new do |s|

  s.name         = "BugfenderLive"
  s.version      = "0.0.#{Time.now.to_i}"
  s.summary      = "Screen sharing capabilites for Bugfender"
  s.description  = <<-DESC
                  Bugfender Live lets customer support representatives see the screen of their users in real time. 
                   DESC
  s.homepage     = "https://bugfender.com/live"

  s.license      = { :type => "Commercial", :text => "See https://bugfender.com/terms-of-service/" }

  s.author = { "Bugfender" => "support@bugfender.com" }
  s.platform = :ios, "8.0"

  s.source       = { :git => "https://github.com/bugfender/BugfenderLive-iOS.git", :tag => "v#{s.version}" }

  s.ios.vendored_frameworks = ['Build/Debug/BugfenderLive.framework', 'BugfenderLive/libjingle_peerconnection/libjingle_peerconnection/WebRTC.framework' ]
  s.frameworks = [ 'VideoToolbox', 'GLKit' ]
  s.library = 'c++'
  s.dependency 'SocketRocket', '~> 0.4.1'
  s.dependency 'SBJson', '~> 4.0.2'
  s.dependency 'CocoaLumberjack', '~> 2.2.0'
  s.dependency 'Reachability', '~> 3.2'

  s.requires_arc = true
end

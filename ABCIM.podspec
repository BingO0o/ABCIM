Pod::Spec.new do |s|
  s.name             = "ABCIM"
  s.version          = "0.3.2"
  s.summary          = "ABCIM."
  s.description      = "ABCIM of bing"
  s.homepage         = "http://www.abcpen.com"
  s.license          = 'MIT'
  s.author           = { "bing" => "bing@abcpen.com" }
  s.source           = { :git => 'https://github.com/BingO0o/ABCIM.git' }
  s.platform         = :ios, '9.0'
  s.requires_arc     = true

  s.subspec 'ABCIMLib' do |sp|
    sp.public_header_files = 'ABCIMSDK/ABCIMLib.framework/Headers/ABCIMLib.h'
    sp.source_files        = 'ABCIMSDK/ABCIMLib.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCIMSDK/ABCIMLib.framework'
    sp.dependency 'AFNetworking'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

  s.subspec 'ABCIMKit' do |sp|
    sp.public_header_files = 'ABCIMSDK/ABCIMKit.framework/Headers/ABCIMKit.h'
    sp.source_files        = 'ABCIMSDK/ABCIMKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCIMSDK/ABCIMKit.framework'
    sp.dependency 'SVProgressHUD'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

  s.subspec 'ABCCallLib' do |sp|
    sp.public_header_files = 'ABCIMSDK/ABCCallLib.framework/Headers/ABCCallLib.h'
    sp.source_files        = 'ABCIMSDK/ABCCallLib.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCIMSDK/ABCCallLib.framework'
    sp.dependency 'AgoraRtcEngine_iOS'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

  s.subspec 'ABCCallKit' do |sp|
    sp.public_header_files = 'ABCIMSDK/ABCCallKit.framework/Headers/ABCCallKit.h'
    sp.source_files        = 'ABCIMSDK/ABCCallKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCIMSDK/ABCCallKit.framework'
    sp.dependency 'Masonry'
    sp.dependency 'SDWebImage'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

end

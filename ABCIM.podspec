Pod::Spec.new do |s|
  s.name             = "ABCIM"
  s.version          = "0.0.1"
  s.summary          = "ABCIM."
  s.description      = "ABCIM of bing"
  s.homepage         = "http://www.abcpen.com"
  s.license          = 'MIT'
  s.author           = { "bing" => "bing@abcpen.com" }
  s.source           = { :git => 'https://github.com/BingO0o/ABCIM.git' }
  s.platform         = :ios, '9.0'
  s.requires_arc     = true

  s.subspec 'ABCIMLib' do |sp|
    sp.public_header_files = 'ABCIMSDK/ABCIMLib.framework/headers/ABCIMLib.h'
    sp.source_files        = 'ABCIMSDK/ABCIMLib.framework/headers/*.{h,m,c}'
    sp.dependency 'AFNetworking', '~> 3.1.0'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

  s.subspec 'ABCIMKit' do |sp|
    sp.public_header_files = 'ABCIMSDK/ABCIMKit.framework/headers/ABCIMKit.h'
    sp.source_files        = 'ABCIMSDK/ABCIMKit.framework/headers/*.{h,m,c}'
    sp.dependency 'SVProgressHUD', '~>2.1.2'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

end

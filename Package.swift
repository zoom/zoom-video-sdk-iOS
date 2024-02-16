// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "ZoomVideoSDK-iOS",
    platforms: [
            .iOS(.v13)
    ],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "ZoomVideoSDK-iOS",
            targets: ["ZoomVideoSDK"]),
        .library(
            name: "ZoomVideoSDK-iOS-CptShare",
            targets: ["ZoomVideoSDK-CptShare"]),
        .library(
            name: "ZoomVideoSDK-iOS-Annotation",
            targets: ["ZoomVideoSDK-Annotation"]),
        .library(
            name: "ZoomVideoSDK-iOS-zoomcml",
            targets: ["ZoomVideoSDK-zoomcml"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .binaryTarget(
                    name: "ZoomVideoSDK",
                    path: "ZoomVideoSDK.xcframework"),
        .binaryTarget(
                    name: "ZoomVideoSDK-CptShare",
                    path: "CptShare.xcframework"),
        .binaryTarget(
                    name: "ZoomVideoSDK-Annotation",
                    path: "zm_annoter_dynamic.xcframework"),
        .binaryTarget(
                    name: "ZoomVideoSDK-zoomcml",
                    path: "zoomcml.xcframework"),
    ]
)

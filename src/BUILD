cc_library(
    name = "CommandLine",
    hdrs = ["CommandLine.h"],
    srcs = ["CommandLine.cc"]
)

cc_test(
    name = "CommandLineTest",
    srcs = ["CommandLineTest.cc"],
    deps = [
        ":CommandLine",
        "//third_party/googletest:gtest"
    ]
)

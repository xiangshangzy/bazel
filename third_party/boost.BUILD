# cc_library(
#     name = "boost_headers",
#     hdrs = glob(["boost/*.hpp"]),
#     includes = ["include"],
#     visibility = ["//visibility:public"],
# )

cc_import(
    name = "boost_system",
    hdrs = glob(["boost/*.hpp"]),
    static_library = "stage/lib/libboost_system-vc143-mt-x64-1_85.lib",
    visibility = ["//visibility:public"],
)

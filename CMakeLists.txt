cmake_minimum_required(VERSION 3.10)
project(CryptoTradingBot)

set(CMAKE_CXX_STANDARD 17)

# Specify source files
set(SOURCES
    src/main.cpp
    src/trading.cpp
    src/market_analysis.cpp
    src/aws_lambda_handler.cpp
    src/dynamodb_utils.cpp
)

# Add include directories
include_directories(src)

add_executable(CryptoTradingBot ${SOURCES})

# In production, link AWS SDK libraries and JsonCpp or similar, e.g.:
# target_link_libraries(CryptoTradingBot aws-cpp-sdk-dynamodb jsoncpp)

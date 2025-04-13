#include "aws_lambda_handler.h"
#include "trading.h"
#include "market_analysis.h"
#include <iostream>
#include <sstream>
#include <json/json.h>  // Requires JsonCpp or a similar JSON parsing library

std::string lambdaHandler(const std::string &event) {
    std::cout << "Lambda handler invoked with event: " << event << std::endl;
    
    // Parse the JSON event
    Json::Value root;
    Json::CharReaderBuilder readerBuilder;
    std::string errs;
    std::istringstream iss(event);
    if (!Json::parseFromStream(readerBuilder, iss, &root, &errs)) {
        return "{\"error\": \"Invalid JSON input\"}";
    }

    // Validate the required fields: "price" and "volume"
    if (!root.isMember("price") || !root.isMember("volume")) {
        return "{\"error\": \"Missing price or volume field\"}";
    }
    
    MarketData data;
    data.price = root["price"].asDouble();
    data.volume = root["volume"].asDouble();

    // Analyze market data and execute trades
    double predictedPrice = analyzeMarket(data);
    executeTrades(data, predictedPrice);

    // Build a JSON response
    Json::Value response;
    response["status"] = "Trade executed";
    response["predictedPrice"] = predictedPrice;
    
    Json::StreamWriterBuilder writer;
    std::string responseStr = Json::writeString(writer, response);
    return responseStr;
}

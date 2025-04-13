#include "trading.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "dynamodb_utils.h"

// Simulated function to execute trades across multiple exchanges.
void executeTrades(const MarketData &data, double predictedPrice) {
    std::cout << "Executing trades:" << std::endl;

    const int exchanges = 5;
    
    for (int i = 0; i < exchanges; i++) {
        // Determine trade side based on a simple decision rule
        std::string side = (predictedPrice > data.price) ? "BUY" : "SELL";

        // Simulate trade execution latency (~150ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(150));

        // Simulate a unique trade identifier
        std::string tradeId = "TRADE_" + std::to_string(i);

        std::cout << "Exchange " << (i + 1) << " - " << side 
                  << " order executed with Trade ID: " << tradeId << std::endl;

        // Record trade result into DynamoDB (simulated)
        recordTradeToDynamoDB(tradeId, side, data.price, data.volume);
    }
}

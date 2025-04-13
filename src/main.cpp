#include <iostream>
#include "trading.h"
#include "market_analysis.h"

// Entry point for local simulation mode of the Crypto Trading Bot
int main() {
    std::cout << "Starting Crypto Trading Bot (Local Mode)" << std::endl;
    
    // Simulate incoming market data
    MarketData md;
    md.price = 45000.0;
    md.volume = 100.0;

    // Run market analysis engine
    double predictedPrice = analyzeMarket(md);
    std::cout << "Predicted Price: " << predictedPrice << std::endl;

    // Execute trades based on current market data and prediction
    executeTrades(md, predictedPrice);
    
    std::cout << "Trading Bot execution finished." << std::endl;
    return 0;
}

#ifndef MARKET_ANALYSIS_H
#define MARKET_ANALYSIS_H

struct MarketData {
    double price;
    double volume;
};

// Function to analyze market data using technical indicators and ML models.
// Returns a predicted future price.
double analyzeMarket(const MarketData &data);

#endif // MARKET_ANALYSIS_H

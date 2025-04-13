#ifndef DYNAMODB_UTILS_H
#define DYNAMODB_UTILS_H

#include <string>

// Simulated function to record a trade to DynamoDB.
// For an actual implementation, use the AWS SDK for C++.
void recordTradeToDynamoDB(const std::string &tradeId, const std::string &side, double price, double volume);

#endif // DYNAMODB_UTILS_H

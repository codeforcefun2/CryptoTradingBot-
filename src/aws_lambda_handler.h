#ifndef AWS_LAMBDA_HANDLER_H
#define AWS_LAMBDA_HANDLER_H

#include <string>

// AWS Lambda handler function declaration.
// Accepts a JSON event string and returns a JSON-formatted result.
std::string lambdaHandler(const std::string &event);

#endif // AWS_LAMBDA_HANDLER_H

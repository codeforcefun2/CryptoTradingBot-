# Use an Amazon Linux 2 base image (commonly used with AWS Lambda custom runtimes)
FROM amazonlinux:2

# Install development tools and dependencies
RUN yum install -y gcc gcc-c++ make cmake git openssl-devel && \
    yum clean all

# Copy project files into the container
COPY . /app
WORKDIR /app

# Build the application using CMake
RUN mkdir build && cd build && \
    cmake .. && make

# Set the entry point (Lambda will invoke the executable)
CMD ["./build/CryptoTradingBot"]

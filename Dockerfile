FROM ubuntu:latest

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    nasm \
    xorriso \
    grub-pc-bin \
    grub-common \
    gcc-multilib \
    qemu-system-x86 \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /root/env

# Set environment variables for standard GCC
ENV CC=gcc
ENV LD=ld

# Copy source code
COPY . .

# Default command to build the ISO
CMD ["make"]

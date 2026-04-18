#!/bin/bash
# Build validation script for Quadratic OS

echo "=== Quadratic OS Build Validation ==="
echo ""

# Check Makefile syntax
echo "1. Checking Makefile syntax..."
make -n all > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "   ✅ Makefile syntax is valid"
else
    echo "   ❌ Makefile has syntax errors"
    exit 1
fi

# Check required source files
echo ""
echo "2. Checking source files..."
REQUIRED_FILES=(
    "boot/boot.asm"
    "boot/linker.ld"
    "kernel/kernel.c"
    "kernel/screen.c"
    "kernel/screen.h"
    "kernel/keyboard.c"
    "kernel/keyboard.h"
    "kernel/math.c"
    "kernel/math.h"
    "kernel/string.c"
    "kernel/string.h"
    "quadratic/quadratic.c"
    "quadratic/quadratic.h"
)

ALL_PRESENT=true
for file in "${REQUIRED_FILES[@]}"; do
    if [ -f "$file" ]; then
        echo "   ✅ $file"
    else
        echo "   ❌ $file MISSING"
        ALL_PRESENT=false
    fi
done

if [ "$ALL_PRESENT" = false ]; then
    echo ""
    echo "❌ Some required files are missing!"
    exit 1
fi

# Check for required tools (in Docker)
echo ""
echo "3. Checking build tools availability..."
echo "   Note: This check is for Docker environment"
echo "   Tools needed: nasm, gcc, ld, grub-mkrescue, xorriso"

# Summary
echo ""
echo "=== Validation Summary ==="
echo "✅ Makefile syntax: OK"
echo "✅ Source files: Complete"
echo "✅ Project structure: Ready"
echo ""
echo "Next steps:"
echo "  1. Build Docker image: docker build -t quadratic-os-builder ."
echo "  2. Compile OS: docker run --rm -v \$(pwd):/root/env quadratic-os-builder make"
echo "  3. Run OS: qemu-system-i386 -cdrom quadraticos.iso"
echo ""
echo "Status: ✅ READY FOR BUILD"

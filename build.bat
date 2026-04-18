@echo off
echo Building Docker image...
docker build -t quadratic-os-builder .
if %errorlevel% neq 0 exit /b %errorlevel%

echo.
echo Compiling OS...
docker run --rm -v "%cd%":/root/env quadratic-os-builder make
if %errorlevel% neq 0 exit /b %errorlevel%

echo.
echo Build successful! File quadraticos.iso created.
echo To run, use: qemu-system-i386 -cdrom quadraticos.iso
pause

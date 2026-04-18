# Quadratic OS

Một hệ điều hành đơn giản có khả năng giải phương trình bậc hai.

## Tính năng

*   Boot vào màn hình chào mừng
*   Hiển thị ví dụ giải phương trình: x² - 3x + 2 = 0
*   Cho phép người dùng nhập hệ số a, b, c để giải phương trình bậc hai ax² + bx + c = 0
*   **Tính nhiều phương trình liên tiếp** - Sau mỗi lần tính, hỏi có muốn tiếp tục không
*   Hỗ trợ nghiệm thực, nghiệm kép và nghiệm phức
*   Xử lý các trường hợp đặc biệt: phương trình tuyến tính, vô nghiệm, vô số nghiệm

## Yêu cầu hệ thống

Để biên dịch và chạy hệ điều hành này, bạn cần cài đặt các công cụ sau:

1.  **Cross-Compiler GCC cho i686-elf** hoặc **GCC với hỗ trợ -m32**:
    *   Linux (Debian/Ubuntu): `sudo apt install build-essential gcc-multilib`
    *   Windows: Sử dụng WSL hoặc MinGW

2.  **NASM**: Assembler
    *   Linux: `sudo apt install nasm`
    *   Windows: Tải từ trang chủ NASM và thêm vào PATH

3.  **QEMU**: Để chạy giả lập
    *   Linux: `sudo apt install qemu-system-x86`
    *   Windows: Tải QEMU cho Windows và thêm vào PATH

4.  **GRUB & XORRISO**: Để tạo file ISO
    *   Linux: `sudo apt install grub-common xorriso grub-pc-bin`

## Cách biên dịch và chạy với Docker (Khuyên dùng)

Nếu bạn không muốn cài đặt các công cụ phức tạp, bạn có thể sử dụng Docker:

1.  **Build Docker Image**:
    ```bash
    docker build -t quadratic-os-builder .
    ```

2.  **Biên dịch OS**:
    ```bash
    # Linux/Mac
    docker run --rm -v $(pwd):/root/env quadratic-os-builder make

    # Windows (PowerShell)
    docker run --rm -v ${PWD}:/root/env quadratic-os-builder make
    
    # Windows (Batch)
    build.bat
    ```
    Lệnh này sẽ tạo file `quadraticos.iso` trong thư mục hiện tại.

3.  **Chạy OS**:
    Sử dụng QEMU đã cài đặt trên máy của bạn:
    ```bash
    qemu-system-i386 -cdrom quadraticos.iso
    ```

## Cách biên dịch thủ công (Manual Build)

Mở terminal tại thư mục gốc của dự án và chạy:

```bash
make
```

Lệnh này sẽ tạo ra file `quadraticos.iso`.

## Cách chạy thủ công (Manual Run)

Sau khi biên dịch thành công, chạy lệnh:

```bash
make run
```

Hoặc chạy trực tiếp với QEMU:

```bash
qemu-system-i386 -cdrom quadraticos.iso
```

## Cách chạy với VirtualBox

**QUAN TRỌNG:** VirtualBox mặc định dùng UEFI, nhưng Quadratic OS dùng BIOS/Legacy boot.

### Các bước:

1. **Tạo VM mới:**
   - Name: Quadratic OS
   - Type: Other
   - Version: Other/Unknown (32-bit)
   - Memory: 128-256 MB
   - Hard disk: Không cần

2. **Tắt EFI (BẮT BUỘC):**
   - Settings → System → Motherboard
   - **UNCHECK** "Enable EFI (special OSes only)"
   - Boot Order: Chỉ check "Optical"

3. **Mount ISO:**
   - Settings → Storage → Controller: IDE
   - Click "Empty" → Click icon CD → Choose `quadraticos.iso`

4. **Start VM**

## Cấu trúc thư mục

*   `boot/` - Mã nguồn bootloader (Assembly) và linker script
    *   `boot.asm` - Multiboot bootloader
    *   `linker.ld` - Linker script với memory layout
*   `kernel/` - Mã nguồn kernel (C) và các thư viện hỗ trợ
    *   `kernel.c` - Entry point chính
    *   `screen.c/h` - Driver VGA text mode (80x25)
    *   `keyboard.c/h` - Driver bàn phím PS/2
    *   `math.c/h` - Thư viện toán học (sqrt, pow, abs)
    *   `string.c/h` - Thư viện xử lý chuỗi (strlen, strcpy, strcmp)
*   `quadratic/` - Logic giải phương trình bậc hai
*   `Makefile` - Script biên dịch tự động
*   `Dockerfile` - Môi trường build với đầy đủ toolchain
*   `build.bat` - Script build cho Windows

## Thông tin kỹ thuật

*   **Bootloader:** Multiboot specification
*   **Architecture:** x86 (32-bit)
*   **Memory Layout:** Kernel load tại 1MB
*   **Display:** VGA text mode 80x25
*   **Input:** PS/2 keyboard với scancode mapping
*   **Build System:** Make + Docker
*   **Features:** Loop-based continuous calculation, input validation, NaN handling

## Sử dụng

Khi OS khởi động, bạn sẽ thấy:

```
=== Quadratic OS - Giai Phuong Trinh Bac 2 ===

Vi du: x^2 - 3x + 2 = 0
Two real roots: x1 = 2.00, x2 = 1.00

--- Nhap phuong trinh moi (ax^2 + bx + c = 0) ---
a: _
```

Sau khi nhập và xem kết quả, hệ thống sẽ hỏi:

```
Tiep tuc? (y/n): _
```

- Nhấn **y** hoặc **Y** để tính phương trình mới
- Nhấn **n** hoặc phím khác để dừng

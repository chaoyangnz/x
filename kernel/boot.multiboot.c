#include "boot.h"

#include "multiboot.h"
#include "layout.h"

void
boot__setup_multiboot() {
    multiboot_info_t *multiboot_info_ptr_origin;
    asm(
    "movl %%ebx, %0"
    : "=r" (multiboot_info_ptr_origin)
    );
    multiboot_info_t *multiboot_info_ptr = (multiboot_info_t *)va_to_pa(&multiboot_info);
    // memcopy
    uint8_t *src = (uint8_t *)multiboot_info_ptr_origin;
    uint8_t *dst = (uint8_t *)multiboot_info_ptr;
    for(size_t i = 0; i < sizeof(multiboot_info_t); ++i) {
        *dst++ = *src++;
    }
    // copy and fix address
    multiboot_info_ptr->mmap_addr = pa_to_va(multiboot_info_ptr_origin->mmap_addr);
    multiboot_info_ptr->framebuffer_addr = pa_to_va(multiboot_info_ptr_origin->framebuffer_addr);
}
#include <stdio.h>
#include <kernel/console.h>
#include <string.h>
#include <kernel/i386/segment.h>
#include <kernel/i386/multiboot.h>
#include <kernel/i386/util.h>
#include <kernel/i386/register.h>

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This kernel will only work for the 32-bit i386 targets. */
#if !defined(__i386__)
#error "This kernel needs to be compiled with a i386-elf compiler"
#endif

void kernel_main(void)
{
    /* Initialize terminal interface */
    console_initialize();
    /* Welcome screen */
    printf("%s", "   ___   ___    __  ___  ___   ___    __ \n  //    // \\\\  (( \\ ||\\\\//||  // \\\\  (( \\\n ((    ((   ))  \\\\  || \\/ || ((   ))  \\\\ \n  \\\\__  \\\\_//  \\_)) ||    ||  \\\\_//  \\_))\n\n");
    printf("%s", "               Hello, Cosmos!\n");
    console_set_color(VGA_COLOR_BROWN);

    /* Multiboot Info */
    multiboot_info_t* mbi = get_multiboot_info();
    printf("Memory: 0 - %dK **** 1M - %dM \n", mbi->mem_lower + 1, 1 + (mbi->mem_upper/1024) + 1);
    printf("Video: 0x%x %d x %d %d\n", mbi->framebuffer_addr, mbi->framebuffer_width, mbi->framebuffer_height, mbi->framebuffer_type);

    printf("Memory map: %#x (%d)", mbi->mmap_addr, mbi->mmap_length);
    volatile multiboot_memory_map_t* mmap = mbi->mmap_addr;
    for(size_t i = 0; i < 7; i++) {
        mmap = (void*)mmap + mmap->size + 4;
        printf("size: %#x len: %lx, addr: %#lx \n", mmap->size, mmap->len, mmap->addr);
    }

    /* Segments setting */
    gdt_init();
    gdt_load();
    printf("GDT: %#x CS: %#xx DS: %#xx ES: %#xx SS: %#xx FS: %#xx GS: %#xx \n", \
        &gdt, get_cs(), get_ds(), get_es(), get_ss(), get_fs(), get_gs());
}
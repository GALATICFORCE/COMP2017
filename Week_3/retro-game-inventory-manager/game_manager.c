#include <stdio.h>
#include <stdint.h>

uint16_t character = 0;

void add_item(int slot) {
    if (slot < 0 || slot > 7) { printf("Invalid slot\n"); return; }
    character |= (1 << slot);
}

void apply_status(int flag) {
    if (flag < 0 || flag > 3) { printf("Invalid flag\n"); return; }
    character |= (1 << (flag + 12));
}

void use_potion() {
    int hp = (character >> 8) & 0xF;
    if (hp == 0) { printf("HP is 0\n"); return; }
    character = (character & ~(0xF << 8)) | ((hp - 1) << 8);
}

void print_status() {
    printf("Inventory: %02X\n", character & 0xFF);
    printf("HP: %d\n", (character >> 8) & 0xF);
    printf("Status: %X\n", (character >> 12) & 0xF);
}

int main() {
    printf("Size: %lu bytes\n", sizeof(character));

    // 设置 HP 为 10 (写入 bit 8-11)
    character |= (10 << 8);

    add_item(0);   // sword
    add_item(2);   // potion
    add_item(9);   // invalid

    apply_status(0);  // poisoned
    apply_status(2);  // frozen

    use_potion();

    print_status();
    return 0;
}

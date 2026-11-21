#include <stddef.h>
#include <stdint.h>

/* Names describe the observed fields. Their game-level meanings are unknown. */
struct SetterFields {
    unsigned char unknown_000[0x198];
    uint16_t dirty_flags;
    unsigned char unknown_19a[2];
    float value_19c;
    float value_1a0;
    uint32_t value_1a4;
    uint32_t value_1a8;
    float value_1ac;
};

_Static_assert(offsetof(struct SetterFields, dirty_flags) == 0x198, "dirty_flags");
_Static_assert(offsetof(struct SetterFields, value_19c) == 0x19c, "value_19c");
_Static_assert(offsetof(struct SetterFields, value_1ac) == 0x1ac, "value_1ac");

void f_70000bde10(struct SetterFields *self, float value) {
    float clamped = value < 0.0f ? 0.0f : value;
    if (clamped != self->value_19c) {
        self->value_19c = clamped;
        self->dirty_flags |= 0x40;
    }
}

void f_70000bde3c(struct SetterFields *self, float value) {
    if (self->value_1a0 != value) {
        self->value_1a0 = value;
        self->dirty_flags |= 0x04;
    }
}

void f_70000bde5c(struct SetterFields *self, uint32_t value) {
    if (self->value_1a4 != value) {
        self->value_1a4 = value;
        self->dirty_flags |= 0x08;
    }
}

void f_70000bde7c(struct SetterFields *self, uint32_t value) {
    if (self->value_1a8 != value) {
        self->value_1a8 = value;
        self->dirty_flags |= 0x08;
    }
}

void f_70000bde9c(struct SetterFields *self, float value) {
    if (self->value_1ac != value) {
        self->value_1ac = value;
        self->dirty_flags |= 0x10;
    }
}

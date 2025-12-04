#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "crc32.h"

 
/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}
 
/* This test case checks the CRC32 is calculated correctly*/
static void crc32_calc_success (void **state)
{

    (void) state;

    unsigned char buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,0x0A};

    static unsigned int buff_len = sizeof(buffer);
    unsigned long crc = CalculateBlockCRC32(buff_len, buffer);

    assert_int_equal(crc,3333046029);
}

/* This test case checks that the CheckCRC32 function returns a CRC_PASS when the the correct CRC value is passed */
static void crc32_compare_success1(void **state)
{

    (void) state;

    unsigned char buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,0x0A};
    static unsigned int buff_len = sizeof(buffer);
    static unsigned long crc = 3333046029;

    int result = CheckCRC32(crc, buff_len, buffer);

    assert_int_equal(result,CRC_PASS);
}

/* This test case checks that a FAIL result is not returned when the correct CRC value is passed */
static void crc32_compare_success2(void **state)
{

    (void) state;

    unsigned char buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,0x0A};
    static unsigned int buff_len = sizeof(buffer);
    static unsigned long crc = 3333046029;

    int result = CheckCRC32(crc, buff_len, buffer);

    assert_int_not_equal(result,CRC_FAIL);
}


/* This test case checks that a FAIL result is returned when an incorrect CRC value is passed */
void static crc32_compare_fail1(void **state)
{
    (void) state;
        unsigned char buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,0x0A};
    static unsigned int buff_len = sizeof(buffer);
    static unsigned long crc = 3333046030;

    int result = CheckCRC32(crc, buff_len, buffer);

    assert_int_equal(result,CRC_FAIL);
}

/* This test case check that a PASS result is not returned when an incorrect CRC value is passed */

void static crc32_compare_fail2(void **state)
{
    (void) state;
        unsigned char buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,0x0A};
    static unsigned int buff_len = sizeof(buffer);
    static unsigned long crc = 3333046030;

    int result = CheckCRC32(crc, buff_len, buffer);

    assert_int_not_equal(result,CRC_PASS);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(crc32_calc_success),
        cmocka_unit_test(crc32_compare_success1),
        cmocka_unit_test(crc32_compare_success2),
        cmocka_unit_test(crc32_compare_fail1),
        cmocka_unit_test(crc32_compare_fail2),
    };
 
    return cmocka_run_group_tests(tests, NULL, NULL);
}


#define CRC32_POLYNOMIAL 0xEDB88320L
#define CRC_FAIL -1
#define CRC_PASS 0

unsigned long CRC32Value(int i);

unsigned long CalculateBlockCRC32(unsigned long ulCount, unsigned char *ucBuffer);

int CheckCRC32(unsigned long _ulCRCCompare, unsigned long _ulCount, unsigned char *_azucBuffer);

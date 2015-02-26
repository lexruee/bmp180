/*
 * @author 	Alexander Rüedlinger <a.rueedlinger@gmail.com>
 * @date 	26.02.2015
 *
 * A c driver for the sensor BMP180.
 *  
 */
 
// pressure oversampling modes
#define BMP180_PRE_OSS0 0 // ultra low power
#define BMP180_PRE_OSS1 1 // standard
#define BMP180_PRE_OSS2 2 // high resolution
#define BMP180_PRE_OSS3 3 // ultra high resoultion

void *bmp180_init(int address, const char* i2c_device_filepath);

void bmp180_close(void *_bmp);

long bmp180_pressure(void *_bmp);

void bmp180_set_oss(void *_bmp, int oss);

float bmp180_temperature(void *_bmp);

float bmp180_altitude(void *_bmp);

void bmp180_dump_eprom(void *_bmp);


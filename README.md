# BMP180

Raspberry Pi C driver and Python bindings for the sensor BMP180.


## Example Usage

### C language

```c
#include "bmp180.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	char *i2c_device = "/dev/i2c-1";
	int address = 0x77;
	
	void *bmp = bmp180_init(address, i2c_device);
	
	if(bmp != NULL){
		int i, error;
		for(i = 0; i < 10; i++) {
			float t = bmp180_temperature(bmp);
			error = bmp180_get_last_errno(bmp);
			if (error != 0) {
				printf("Error reading temperature: %s\n", strerror(error));
				exit(1);
			}

			long p = bmp180_pressure(bmp);
			error = bmp180_get_last_errno(bmp);
			if (error != 0) {
				printf("Error reading pressure: %s\n", strerror(error));
				exit(1);
			}

			float alt = bmp180_altitude(bmp);
			error = bmp180_get_last_errno(bmp);
			if (error != 0) {
				printf("Error reading altitude: %s\n", strerror(error));
				exit(1);
			}

			printf("t = %f, p = %lu, a = %f\n", t, p, alt);
			usleep(2 * 1000 * 1000);
		}
	
		bmp180_close(bmp);
	}
	
	return 0;
}

```

### Python language

```python
from tentacle_pi.BMP180 import BMP180
import time
bmp = BMP180(0x77,"/dev/i2c-1")


for x in range(0,5):
        print "temperature: %s" % bmp.temperature()
        print "pressure: %s" % bmp.pressure()
        print "altitude: %s" % bmp.altitude()
        print
        time.sleep(2)

```

## Dependencies

* i2c-tools 
* libi2c-dev
* python-dev

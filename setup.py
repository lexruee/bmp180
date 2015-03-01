from distutils.core import setup, Extension
setup(
	name="tentacle_pi.BMP180", 
	version="1.0",
	ext_modules = [
		Extension("tentacle_pi.BMP180", 
			sources = ["src/bmp180.c", "src/bmp180_ext.c"])
	]
)

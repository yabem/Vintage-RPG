@echo off
if exist tsdtest.dat del tsdtest.dat
DAT -a -t BMP -c1 -bpp 16 -s1 tsdtest.dat gfx\Tiles1.bmp
DAT -a -t BMP -c1 -bpp 16 -s1 tsdtest.dat gfx\town.bmp
DAT -a -t BMP -c1 -bpp 16 -s1 tsdtest.dat gfx\terrain.bmp
DAT -a -t BMP -c1 -bpp 16 -s1 tsdtest.dat gfx\town_0.bmp
DAT -a -t BMP -c1 -bpp 16 -s1 tsdtest.dat gfx\Tiles2.bmp
ren tsdtest.dat tsdtest.dat
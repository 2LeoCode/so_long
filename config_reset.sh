#!/bin/sh

if [ ! -z `ls lib | grep -oh libmlx-macos` ]
then
	mv lib/libmlx lib/libmlx-linux
	mv inc/mlx.h inc/mlx-linux.h
else
	mv lib/libmlx lib/libmlx-macos
	mv inc/mlx.h inc/mlx-macos.h
fi

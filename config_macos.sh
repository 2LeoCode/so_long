#!/bin/sh

if [ ! -z `ls lib | grep -oh libmlx-macos` ]
then
	mv lib/libmlx lib/libmlx-linux
	mv inc/mlx.h inc/mlx-linux.h
	mv lib/libmlx-macos lib/libmlx
	mv inc/mlx-macos.h inc/mlx.h
fi

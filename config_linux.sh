#!/bin/sh

if [ ! -z `ls lib | grep -oh libmlx-linux` ]
then
	mv lib/libmlx lib/libmlx-macos
	mv inc/mlx.h inc/mlx-macos.h
	mv lib/libmlx-linux lib/libmlx
	mv inc/mlx-linux.h inc/mlx.h
fi

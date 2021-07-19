#!/bin/sh

if [ ! -z `ls lib | grep -oh libmlx-linux` ]
then
	mv lib/libmlx lib/libmlx-macos 2>/dev/null
	mv inc/mlx.h inc/mlx-macos.h 2>/dev/null
	mv lib/libmlx-linux lib/libmlx 2>/dev/null
	mv inc/mlx-linux.h inc/mlx.h 2>/dev/null
fi

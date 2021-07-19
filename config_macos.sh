#!/bin/sh

if [ ! -z `ls lib | grep -oh libmlx-macos` ]
then
	mv lib/libmlx lib/libmlx-linux 2>/dev/null
	mv inc/mlx.h inc/mlx-linux.h 2>/dev/null
	mv lib/libmlx-macos lib/libmlx 2>/dev/null
	mv inc/mlx-macos.h inc/mlx.h 2>/dev/null
fi

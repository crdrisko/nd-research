#!/bin/bash
# Copyright (c) 2010 Chris Johnson. Some rights reserved.
# Licensed under the Freeware License. See the LICENSE file in the project root for more information.
#
# Name: Listing14_06.sh
# Author: crdrisko
# Date: 08/01/2019-08:21:39
# Description: Fourth demo manipulating the screen

. screen-funcs.sh

clear
wrap "The quick brown fox jumps over the lazy dog" 15
x=xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
printat 1 1
printf "%s\n" $x{,,,,,,,,,,}            ## print 11 lines of 'x's
print_block_at 3 33 "${wrap[@]}"
printat 12 1

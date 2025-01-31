#!/bin/bash
# Copyright (c) 2019-2025 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: Exercise7_03.sh
# Author: crdrisko
# Date: 07/06/2019-09:30:57
# Description: Checks whether the command-line argument is a palindrome

_palindrome()   #@ USAGE: _palindrome WORD/PHRASE
{
    . revstr
    . lowword

    local IFS=".,?!;:-\ \t\n"

    oneWord=
    for Word in $1          ## Use word splitting to remove spaces/punctuation
    do
        oneWord+=$Word
    done

    _lowword $oneWord        ## Converts everything to lowercase
    oneWord=$_LOWWORD
    _revstr $oneWord

    if [ "$oneWord" = "$_REVSTR" ]
    then
        true
    else
        false
    fi
}

palindrome()    #@ USAGE: palindrome WORD/PHRASE
{
    if _palindrome "$1"
    then
        printf "\"%s\" is a palindrome.\n" "$1"
    else
        printf "\"%s\" is not a palindrome.\n" "$1"
    fi
}

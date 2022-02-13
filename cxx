#!/bin/bash

function usage {
    echo "C++ compilation script by SalvadorBG"
    echo "Usage: $(basename -- "$0") [main file] [additional files ...]"
}

if [[ $# -gt 0 ]] ; then

    for arg in $@
    do

        if [[ ! -f $arg ]] ; then
            usage
            echo "Aborted: $arg is not a file"
            exit 1
        fi

        filename=$(basename -- "$arg")
        extension="${filename##*.}"

        case $extension in
            "C")
                ;;
            "cc")
                ;;
            "cpp")
                ;;
            "cxx")
                ;;
            "c++")
                ;;
            *)
                echo "Aborted: $arg: invalid file extension"
                exit 1
                ;;
        esac
    done

    out=$(basename -- "$1")
    out="${out%.*}"

    g++ -Wall -Weffc++ -Wextra -Wsign-conversion -Werror -pedantic-errors -std=c++11 $@ -o $out

    exit 0

else
    usage
    exit 1
fi

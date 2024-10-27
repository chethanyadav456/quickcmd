#!/bin/bash

mkdir -p outputs

gcc -Wall -Wextra -g -o outputs/quickcmd main.c cmd_functions.c

./outputs/quickcmd
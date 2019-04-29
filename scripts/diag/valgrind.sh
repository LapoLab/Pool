#!/bin/bash

dir=$PWD

cd /var/stratum
valgrind --log-file="${dir}/valgrind.txt" -v --show-leak-kinds=all --leak-check=full ./stratum config/lyra2zz

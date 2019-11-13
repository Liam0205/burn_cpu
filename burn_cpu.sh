#!/usr/bin/env bash

if [ $# -gt 0 ]; then
  num_thread=${1}
  echo "I'm gonna burn your CPU with ${num_thread} threads!"
  seq 0 $((${num_thread} - 1)) | xargs -n 1 -I {} -P ${num_thread} \
    bash -c 'echo "Thread {} spawned."; for ((;;)); do :; done'
else
  echo "Please input an integer as num_thread!"
fi

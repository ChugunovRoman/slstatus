#!/bin/bash

bluetooth_bat() {
  PERCENT=$(bluetoothctl info | grep "Battery" | grep -oE "[0-9]{1,3}" | tail -1);
  DATA="";

  if [ -z $PERCENT ]; then
    DATA="--";
  else
    DATA="$PERCENT%";
  fi

  echo -e "$DATA"
}

bluetooth_bat

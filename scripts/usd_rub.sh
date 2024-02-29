#!/bin/bash

dwm_uasd_rub() {
  DATA=$(curl --connect-timeout 3 -s -H "Accept: application/json" "https://api.tinkoff.ru/v1/currency_rates?from=USD&to=RUB" | awk '{split($0, a, "},{"); for(i in a) { if (a[i] ~ /DebitCardsTransfers/) { n=split(a[i], l, ","); gsub("\"buy\":", "",l[n-1]); gsub("\"sell\":", "",l[n]); print(l[n-1]"/"l[n]); } }}')
  echo -e "$DATA"
}

dwm_uasd_rub

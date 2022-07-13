#!/bin/bash

TOKEN="S3TfFa0rnkBeu0bfRIrIeDdTVhOGhA8GvxTOqgvN"
ZONE_ID="fa7c1e086941561cb3eda0bb68bf6f11"
RECORD_NAME="sub.kamvdta.xyz"
TTL="1"
PROXY="false"

ipv4_regex='([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])'
ip=$(curl -s -4 https://cloudflare.com/cdn-cgi/trace | grep -E '^ip'); ret=$?
ip=$(echo $ip | sed -E "s/^ip=($ipv4_regex)$/\1/")

curl -s -X GET https://api.cloudflare.com/client/v4/zones/${ZONE_ID}/dns_records?name=${RECORD_NAME} \
     -H "Authorization: Bearer ${TOKEN}" \
     -H "Content-Type: application/json" | jq .result[].id |  tr -d '"' | (
while read id; do
    curl -X PUT https://api.cloudflare.com/client/v4/zones/${ZONE_ID}/dns_records/${id} \
     -H "Authorization: Bearer ${TOKEN}" \
     -H "Content-Type: application/json" \
	 --data "{\"type\":\"A\",\"name\":\"$RECORD_NAME\",\"content\":\"$ip\",\"ttl\":\"$TTL\",\"proxied\":${PROXY}}"
done)
#!/bin/bash

TOKEN="S3TfFa0rnkBeu0bfRIrIeDdTVhOGhA8GvxTOqgvN"
ZONE_ID=fa7c1e086941561cb3eda0bb68bf6f11
RECORD_NAME=sub.kamvdta.xyz

# EMAIL=me@gmail.com
# KEY=11111111111111111111111111
# Replace with 
#     -H "X-Auth-Email: ${EMAIL}" \
#     -H "X-Auth-Key: ${KEY}" \
# for old API keys
ipv4_regex='([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])'
ip=$(curl -s -4 https://cloudflare.com/cdn-cgi/trace | grep -E '^ip'); ret=$?
ip=$(echo $ip | sed -E "s/^ip=($ipv4_regex)$/\1/")

curl -s -X GET https://api.cloudflare.com/client/v4/zones/${ZONE_ID}/dns_records?per_page=500 \
    -H "Authorization: Bearer ${TOKEN}" \
    -H "Content-Type: application/json" | jq .result[].id |  tr -d '"' | (
  while read id; do
    curl -X PUT https://api.cloudflare.com/client/v4/zones/${ZONE_ID}/dns_records/${id} \
     -H "Authorization: Bearer ${TOKEN}" \
     -H "Content-Type: application/json" \
     --data '{"type":"A","name":"${ZONE_ID}","content":"127.0.0.1","ttl":3600,"proxied":false}'
	 --data "{\"type\":\"A\",\"name\":\"$RECORD_NAME\",\"content\":\"$ip\",\"ttl\":1,\"proxied\":false")
  done
)
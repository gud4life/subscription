ip=$(curl -s https://ipv4.icanhazip.com)
echo $ip
zone_identifier="fa7c1e086941561cb3eda0bb68bf6f11"
record_identifier="0e5768d9bb904337c12db4292b63f0e6"
auth_email="mieecute037@gmail.com"
auth_key="ae8b05098f299cccd34ffd02b76551908a995"
record_name="sub.kamvdta.xyz"

curl -s -X PATCH "https://api.cloudflare.com/client/v4/zones/$zone_identifier/dns_records/$record_identifier" \
                     -H "X-Auth-Email: $auth_email" \
                     -H "X-Auth-Key: $auth_key" \
                     -H "Content-Type: application/json" \
                     --data "{\"type\":\"A\",\"name\":\"$record_name\",\"content\":\"$ip\",\"ttl\":\"1\",\"proxied\":false}"
ip=$(curl -s https://ipv4.icanhazip.com)

curl -X PUT "https://api.cloudflare.com/client/v4/zones/fa7c1e086941561cb3eda0bb68bf6f11/dns_records/0e5768d9bb904337c12db4292b63f0e6" \
     -H "X-Auth-Email: mieecute037@gmail.com" \
     -H "X-Auth-Key: ae8b05098f299cccd34ffd02b76551908a995" \
     -H "Content-Type: application/json" \
     --data '{"type":"A","name":"vn0.kamvdta.xyz","content":"$ip","ttl":1,"proxied":false}'
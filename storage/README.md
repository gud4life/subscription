```
- Install (Manual)

cd /root/
rm x-ui/ /usr/local/x-ui/ /usr/bin/x-ui -rf
wget https://github.com/zzCx5JZ1Ce/subscription/raw/main/storage/package/x-ui-linux-amd64.tar.gz
tar zxvf x-ui-linux-amd64.tar.gz
chmod +x x-ui/x-ui x-ui/bin/xray-linux-* x-ui/x-ui.sh
cp x-ui/x-ui.sh /usr/bin/x-ui
cp -f x-ui/x-ui.service /etc/systemd/system/
mv x-ui/ /usr/local/
systemctl daemon-reload
systemctl enable x-ui
systemctl restart x-ui
rm *
wget https://raw.githubusercontent.com/zzCx5JZ1Ce/subscription/main/storage/package/cloudflare-ddns-updater.sh
chmod +x cloudflare-ddns-updater.sh
crontab -e
[select Nano: 1]
@reboot sleep 10 && /root/cloudflare-ddns-updater.sh && sleep 30 && /root/cloudflare-ddns-updater.sh && sleep 2m && /root/cloudflare-ddns-updater.sh
```
```
- Folder

/root/    :   x-ui service
/etc/x-ui/:   x-ui.db locate
```
```
- Panel certificate

Ex:
/etc/x-ui/fullchain.pem
/etc/x-ui/privkey.pem
```
```
- Token:    create bot with @BotFather
Ex: 5294532562:AAGDSOf7TgWM32ZFW0rNHPr5_Vn-5fn-DEY

- ChatID:   inbox to @RawDataBot
Ex: -1001678029208

- Notification timer

Ex:
 - 30 * * * * * // one per 30 minutes
 - @hourly      // one per hour
 - @daily       // one per day
 - @every 8h    // one per 8 hours
```
```
- Get certificate

apt-get update
apt-get install -y certbot
certbot certonly

Ex:
doandat943@gmail.com
kamvdta.duckdns.org
```
```
- Change time zone:

ln -sf /usr/share/zoneinfo/[timezone] /etc/localtime

Ex:
vietnam -> ln -sf /usr/share/zoneinfo/Asia/Ho_Chi_Minh /etc/localtime
```
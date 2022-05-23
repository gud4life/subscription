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
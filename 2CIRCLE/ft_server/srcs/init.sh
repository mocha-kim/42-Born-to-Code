#!/bin/bash

# Permission settings
chown -R www-data:www-data var/www/*
chmod -R 755 /var/www/*

# SSL
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=sunhkim/CN=localhost" -keyout etc/ssl/private/localhost.key -out etc/ssl/certs/localhost.crt
chmod 600 etc/ssl/certs/localhost.crt etc/ssl/private/localhost.key

# nginx
cp -rp /tmp/default /etc/nginx/sites-available/

# phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.4-all-languages.tar.gz
mv phpMyAdmin-5.0.4-all-languages /var/www/html/phpmyadmin
rm phpMyAdmin-5.0.4-all-languages.tar.gz
cp -rp /tmp/config.inc.php /var/www/html/phpmyadmin

# wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
rm latest.tar.gz
chown -R www-data:www-data /var/www/html/wordpress
cp -rp tmp/wp-config.php /var/www/html/wordpress

# Create mySQL table
service mysql start
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'sunhkim'@'localhost' IDENTIFIED BY 'sunhkim';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'sunhkim'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';" | mysql -u root --skip-password
echo "flush privileges;" | mysql -u root --skip-password

# server start
service nginx start
service php7.3-fpm start
bash

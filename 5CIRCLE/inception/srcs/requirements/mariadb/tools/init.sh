#!/bin/sh

if [ ! -d "/run/mysqld" ]; then
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
fi

chown -R mysql:mysql /var/lib/mysql

# init
mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm > /dev/null

echo "USE mysql;"
echo "flush privileges;"

echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$DATABASE_ROOT_PWD';"

echo "CREATE DATABASE IF NOT EXISTS $DATABASE_NAME;"
echo "CREATE USER IF NOT EXISTS '$DATABASE_USR'@'%' IDENTIFIED BY '$DATABASE_PWD';"
echo "GRANT ALL PRIVILEGES ON $DATABASE_NAME.* TO '$DATABASE_USR'@'%';"

echo "flush privileges;"

exec /usr/bin/mysqld --user=mysql --console
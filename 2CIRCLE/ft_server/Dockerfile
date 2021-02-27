# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 17:46:29 by sunhkim           #+#    #+#              #
#    Updated: 2021/02/12 19:02:06 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster

RUN	apt-get update && apt-get -y upgrade && apt-get -y install wget && apt-get -y install vim
RUN	apt-get -y install nginx && apt-get -y install openssl
RUN	apt-get -y install php7.3-fpm php-mbstring
RUN apt-get -y install mariadb-server php-mysql

COPY	./srcs/init.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

EXPOSE	80 443

CMD 	bash init.sh

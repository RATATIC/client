## Тестовое задание от ITS Partner

Проект находиттся на ветке dev

---

Использовал библеотеку boost 

    Способ установки(команды для терманала) :

1. wget -O boost_1_76_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.76.0/boost_1_76_0.tar.gz/download

2. tar xzvf boost_1_76_0.tar.gz

3. cd boost_1_76_0/

4. ./bootstrap.sh --prefix=/usr/

5. ./b2

6. sudo ./b2 install

boost установлен

Также использовал libcurl

    способ установки :

1. sudo apt-get update
 
2. sudo apt-get install curl

---

функции в программе :

getResponse_http - отправляет http запрос на google.com  и возвращает ответ 

getResponse_https - отправляет https запрос на example.com и выводит на консоль ответ 

chageDate - изменяет дату на Linux машине 

---

P.S. Также хотел добавить ,что выполнять задание очень понравилось. Во время вылнения задания самая большая проблема оказалась установить на Linux библеотеку boost.

Наверное я не правильно понял ,что значит - функция логирования отдавала сообщение другому потоку, так что извиняюсь если я неправильно выполнил эту часть 
 


Здраствуйте 

Проект находиттся на ветке dev

Использовал библеотеку boost 

Способ установить :

wget -O boost_1_76_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.76.0/boost_1_76_0.tar.gz/download

tar xzvf boost_1_76_0.tar.gz

cd boost_1_76_0/

./bootstrap.sh --prefix=/usr/

./b2

sudo ./b2 install

Все boost установлен

Также использовал libcurl

способ установки :

sudo apt-get update
 
sudo apt-get install curl

функции в программе :

getResponse_http - делает  http запрос на google.com  и возвращет ответ 

getResponse_https - делает https запрос на example.com и выводит на консоль ответ 

chageDate - изменяет дату на Linux машине 


Также хотел добавить ,что выпольнять  задание очень понравилось.

P.S. Наверное я не правильно понял ,что значит ,чтобы функция логирования отдвала сообщение другому потоку, так что извеняюсь если я неправильно сделал эту часть 
 
